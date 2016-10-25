#include <algorithm>
#include <iostream>
#include <vector>

int LIS(const std::vector<int>& v) {
  std::vector<int> longest_ending_at(v.size(), 1);

  for (unsigned i = 1; i < v.size(); ++i) {
    for (unsigned j = 0; j < i; ++j) {
      if (v[i] > v[j]) {
        longest_ending_at[i] =
            std::max(longest_ending_at[i], longest_ending_at[j] + 1);
      }
    }
  }

  const auto max_length =
      std::max_element(longest_ending_at.begin(), longest_ending_at.end());
  return *max_length;
}

int main() {
  std::vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
  std::cout << LIS(v) << std::endl;
}
