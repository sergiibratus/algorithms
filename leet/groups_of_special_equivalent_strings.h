class Solution {
    public:
        int numSpecialEquivGroups(vector<string>& A) {
            struct S {
                map<char, int> odds;
                map<char, int> evens;

                bool operator< (const S& right) const {
                    if (this->odds < right.odds)
                        return true;
                    
                    if (this->odds > right.odds)
                        return false;
                    
                    return this->evens < right.evens;
                }
            };

            map<S, int> s;

            for (const auto& val : A) {
                S word;
                for (int i = 0; i < val.size(); i++) {
                    if (i % 2) {
                        word.odds[val[i]]++;
                    } else {
                        word.evens[val[i]]++;
                    }
                }
                s[word]++;
            }


            return s.size();
        }
};


