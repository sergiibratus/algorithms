class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, 0, nums.size() - 1, target);
    }
private:
    bool search(vector<int>& nums, int l, int h, int target) {
        if (l > h)
            return false;
        
        int m = (l + h) / 2;
        if (nums[m] == target)
            return true;
        
        if (nums[l] == nums[m] && nums[l] == nums[h])
            return (search(nums, l, m-1, target) || search(nums, m + 1, h, target));

        if (nums[l] <= nums[m]) {
            if (target >= nums[l] && target <= nums[m])
                return search(nums, l, m - 1, target);
            
            return search(nums, m + 1, h, target);
        }
        
        if (target >= nums[m] && target <= nums[h])
            return search(nums, m + 1, h, target);

        return search(nums, l, m - 1, target);
    } 
};
