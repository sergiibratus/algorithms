class Solution {
    public:
        vector<int> splitIntoFibonacci(string S) {
            vector<int> fib;

            for (int ii = 0; ii < S.size() - 2; ++ii) {
                int first = makenum(S, 0, ii);
                if (first == -1)
                    continue;

                fib.push_back(first);

                for (int jj = ii + 1; jj < S.size() - 1; ++jj) {
                    int second = makenum(S, ii + 1, jj);
                    if (second == -1)
                        continue;

                    fib.push_back(second);
                    if (solve(fib, S, jj + 1)) {
                        return fib;
                    }
                    fib.pop_back();
                }

                fib.pop_back();
            }

            return fib;
        }

    private:
        bool solve(vector<int>& fib, const string& s, int start) {
            if (start == s.size())
                return true;

            for (int j = start; j < s.size(); ++j) {
                int num = makenum(s, start, j);                

                if (num == -1 || num != (fib[fib.size() - 1] + fib[fib.size() - 2]))
                    continue;

                fib.push_back(num);
                if (solve(fib, s, j + 1)) {
                    return true;
                }
                fib.pop_back();
            }

            return false;
        }

        int makenum(const string& s, int start, int end) {
            if (start < 0 || end >= s.size())
                return -1;

            if (s[start] == '0') {
                if (end == start)
                    return 0;
                return -1;
            }

            long long ret = 0;
            for (int i = start; i <= end; ++i) {
                ret *= 10;
                ret += s[i] - '0';

                if (ret > INT_MAX)
                    return -1;
            }

            return ret;
        }
};
