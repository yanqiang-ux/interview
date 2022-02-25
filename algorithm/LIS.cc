//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       std::vector<int> dp;
       dp.resize(nums.size(), 1);
       uint32_t mxL = 0;
       for (uint32_t i = 0; i < nums.size(); i++) {
           for (uint32_t j = 0; j < i; j++) {
              if (nums[i] > nums[j]) {
                dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
              }
           }
           if (dp[i] > mxL)
              mxL = dp[i];
       }
       return mxL;
    }
};

//second solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       std::vector<int> dp;
       for (auto &i : nums) {
           if (!dp.size()) {
               dp.emplace_back(i);
           } else {
               std::vector<int>::iterator it = std::lower_bound(dp.begin(), dp.end(), i);
               if (it == dp.end()) {
                   dp.emplace_back(i);
               } else {
                   *it = i;
               }
           }
       }
       return dp.size();
    }
};
