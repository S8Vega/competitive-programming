class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int sz = nums.size();
        int ans = abs(nums[0] - nums[sz - 1]);
        for (int i = 0; i < sz - 1; i++) {
            ans = max(ans, abs(nums[i] - nums[i + 1]));
        }
        return ans;
    }
};