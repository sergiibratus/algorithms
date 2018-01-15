#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

bool check(const vector<vector<int>>& v, vector<int>& nums) {

    for (int i = 0; i < 5; ++i) {
        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            sum += nums[v[i][j] - 'a'];
        }
        if (sum != v[i][5]) {
            return false;
        }
    }

    for (int j = 0; j < 5; ++j) {
        int sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += nums[v[i][j] - 'a'];
        }

        if (sum != v[5][j]) {
            return false;
        }
    }

    return true;
}

bool solve(const vector<vector<int>>& v, vector<int>& nums, int index) {
    if (index == nums.size())
        return check(v, nums);

    for (int i = index; i < nums.size(); ++i) {
        swap(nums[index], nums[i]);
        if (solve(v, nums, index + 1))
            return true;
        swap(nums[index], nums[i]);
    }

    return false;
}

int main(int argc, char * argv[0]) {
    ifstream ifs (argv[1], ifstream::in);
    vector<vector<int>> v(6, vector<int>(6, 0));
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            if (i == 5) {
                if (j == 5) {
                    v[i][j] = 0;
                    break;
                }
                ifs >> v[i][j];
                continue;
            }

            if (j == 5)
                ifs >> v[i][j];
            else {
                char c;
                ifs >> c;
                v[i][j] = c;
            }
        }
    }

    vector<int> nums(9, 0);
    for (int i = 1; i <= 9; ++i)
        nums[i - 1] = i;

    if (solve(v, nums, 0))
        for (int i = 0; i < 9; ++i)
            cout << nums[i];

    cout << endl << "Done" << endl;

    return 0;
}

