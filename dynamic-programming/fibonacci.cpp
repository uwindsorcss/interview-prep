#include <iostream>
#include <vector>

int bottom_up_fib(int n) {
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  return dp[n];
}

int top_down_fib(int n, std::vector<int>& dp) {
  if (dp[n] != -1) {
    return dp[n];
  } else if (n == 0 || n == 1) {
    return n;
  }

  int solution = top_down_fib(n - 1, dp) + top_down_fib(n - 2, dp);
  dp[n] = solution;
  return solution;
}

int top_down_fib(int n) {
  std::vector<int> dp(n + 1, -1);
  return top_down_fib(n, dp);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << "Bottom up: " << bottom_up_fib(n) << std::endl;
  std::cout << "Top down: " << top_down_fib(n) << std::endl;
  return 0;
}
