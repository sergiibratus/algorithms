class Solution {
public:
    string pushDominoes(string dominoes) {
        string result;
        
        int i = 0;
        for (; i < dominoes.size(); ++i) {
            if (dominoes[i] != '.')
                break;
        }
        
        if (i == dominoes.size())
            return dominoes;
        
        for (int m = 0; m < i; ++m)
            result += dominoes[i] == 'L' ? 'L' : '.';
        
        for (; i < dominoes.size(); ++i) {
            if (dominoes[i] == 'L')
                result += 'L';
            else if (dominoes[i] == 'R')
                result += 'R';
            else if (dominoes[i] == '.') {
                int m = i;
                for (; m < dominoes.size(); ++m) {
                    if (dominoes[m] != '.')
                        break;
                }
                
                if (m == dominoes.size()) {
                    if (dominoes[i - 1] == 'L') {
                        for (m = i; m < dominoes.size(); ++m)
                            result += '.';
                        
                        return result;
                    } else {
                        for (m = i; m < dominoes.size(); ++m)
                            result += 'R';
                        
                        return result;
                    }
                }
                
                if (dominoes[i - 1] == dominoes[m]) {
                    for (int k = i; k < m; ++k) {
                        result += dominoes[m];
                    }
                    
                    i = m - 1;
                }
                else {
                    
                    if (dominoes[i - 1] == 'L') {
                        for (int k = i; k < m; ++k) {
                            result += '.';
                        }
                    
                        i = m - 1;
                    }
                    else {
                        
                        
                        for (int k = 0; k < (m - i) / 2; ++k) {
                            result += 'R';
                        }
                        if ((m - i) % 2)
                            result += '.';
                        for (int k = 0; k < (m - i) / 2; ++k) {
                            result += 'L';
                        }
                        i = m - 1;
                    }
                    
                }
            }
        }
        
        return result;
    }
};
