#include <iostream>
#include <vector>

class Solution {
public:
    void init_dp_map(std::vector<std::vector<int>> &dp_map_, int k, int n) {
      std::vector<int> sub_d;
      sub_d.resize(n+1, 0);
      dp_map_.emplace_back(sub_d);
      for (int t = 0; t <= k; t++) {
          std::vector<int> sub_dp;
          sub_dp.resize(n+1, 0);
          if (t == 0) {

          } else if (t == 1) {
            for (int j = 1; j <= n; j++) {
              sub_dp[j] = j;
            }
          } else {
              sub_dp[1] = 1;
          }
          dp_map_.emplace_back(sub_dp);
      }
    }

    int superEggDrop(int k, int n) {
      std::vector<std::vector<int>> dp_map;
      //dp_map.resize();
      // init_dp_map(dp_map, k, n);
      for (int t = 0; t <= k; t++) {
        std::vector<int> sub_dp;
        sub_dp.resize(n+1, 0);
        if (t == 0) {

        } else if (t == 1) {
          for (int j = 1; j <= n; j++) {
            sub_dp[j] = j;
          }
        } else {
          sub_dp[1] = 1;
        }
        dp_map.emplace_back(sub_dp);
      }

      for (int i = 0; i <= k; i ++) {
        for (int j = 0; j <= n; j++) {
          std::cout << dp_map[i][j] << " ";
        }
        std::cout << "\n" << std::endl;
      }
      // for (int h = 2; h <= k; h++) {
      //   for (int m = 2; m <= n; m ++) {
      //     //start from t floor
      //     int local_min = 0;
      //     for (int t = 1; t <= m; t++) {
      //       int max = dp_map[h-1][t-1] > dp_map[h][m-t] ? dp_map[h-1][t-1] + 1 : dp_map[h][m-t] + 1;
      //       if (!local_min)
      //         local_min = max;
      //       if (local_min > max) {
      //         local_min = max;
      //       }
      //     }
      //     dp_map[h][m] = local_min;
      //   }
      // }
      // optimize logn * k * n
      for (int h = 2; h <= k; h++) {
        for (int m = 2; m <= n; m ++) {
          int start = 1;
          int end = m;
          int mid = 0;
          while (start < end) {
            mid = start + (end - start + 1) / 2;
            if (dp_map[h-1][mid-1] > dp_map[h][m-mid]) {
              end = mid -1;
            } else {
              start = mid;
            }
          }
          dp_map[h][m] = dp_map[h-1][start-1] > dp_map[h][m-start] ? dp_map[h-1][start-1] +1 : dp_map[h][m-start] + 1;
        }
      }
      return dp_map[k][n];
    }
};

int main () {
  Solution* slo = new Solution();
  std::cout << slo->superEggDrop(2, 6) << std::endl;
}
