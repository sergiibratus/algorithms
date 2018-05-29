/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int N = wordlist[0].size();
        
        vector<vector<int>> v(wordlist.size(), vector<int>(wordlist.size(), 0));
        for (int i = 0; i < wordlist.size(); ++i)
            for (int j = 0; j < wordlist.size(); ++j)
                v[i][j] = v[j][i] = count(wordlist[i], wordlist[j]);
        
        vector<int> all(wordlist.size());
        for (int i = 0; i < wordlist.size(); ++i)
            all[i] = i;

        while (!all.empty()) {
            int index = pick(all.size());
            
            int total = master.guess(wordlist[all[index]]);
            if (total == N)
                return;
            
            vector<int> temp;
            for (int i = 0; i < all.size(); ++i)
                if (index != i && v[all[index]][all[i]] == total)
                    temp.push_back(all[i]);
            
            all.swap(temp);
        }
    }

private:
    int pick(int size) {
        return min(size - 1, 1); // yep
    }
    
    int count(const string& left, const string& right) {
        int total = 0;
        for (int i = 0; i < left.size(); ++i)
            if (left[i] == right[i])
                ++total;

        return total;
    }
};
