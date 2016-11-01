#include <algorithm>
#include <iostream>
#include <vector>

int edit_distance(std::string a, std::string b) {
  std::vector<std::vector<int>> dp(a.size() + 1,
                                   std::vector<int>(b.size() + 1, 0));

  // edit distance between empty strings 0.

  for (uint32_t i = 0; i <= a.size(); ++i) {
    for (uint32_t j = 0; j <= b.size(); ++j) {
      if (i == 0) {
        dp[i][j] = j;
      } else if (j == 0) {
        dp[i][j] = i;
      } else if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
      }
    }
  }

  return dp[a.size()][b.size()];
}

int main() {
  std::string a, b;
  std::cin >> a >> b;
  std::cout << edit_distance(a, b) << std::endl;
  return 0;
}
