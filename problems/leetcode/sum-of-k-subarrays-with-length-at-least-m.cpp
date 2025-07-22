class Solution {
public:
    int maxSum(std::span<const int> nums, int64_t k, int64_t m) {
        const int64_t n = nums.size();

        std::array<int, 2001> prefix;
        prefix[0] = 0;
        for (int64_t i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        auto dp_prev = std::make_unique<int[]>(n + 1);
        auto dp_curr = std::make_unique_for_overwrite<int[]>(n + 1);

        for (int64_t subarrays = 1; subarrays <= k; ++subarrays) {
            const int64_t start = subarrays * m;
            int max_prev = dp_prev[start - m] - prefix[start - m];
            dp_curr[start] = prefix[start] + max_prev;

            for (int64_t j = start + 1; j <= n; ++j) {
                max_prev = std::max(max_prev, dp_prev[j - m] - prefix[j - m]);
                dp_curr[j] = std::max(dp_curr[j - 1], prefix[j] + max_prev);
            } 

            // roll forward
            std::swap(dp_prev, dp_curr);
        }

        return dp_prev[n];
    }
};