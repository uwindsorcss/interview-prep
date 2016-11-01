#include <iostream>
#include <vector>

int min_change(int k, const std::vector<int>& denominations) {
  std::vector<int> min_change_for(k + 1, k + 1);
  min_change_for[0] = 0;
  for (const auto& d : denominations) {
    min_change_for[d] = 1;
  }

  for (int i = 1; i <= k; ++i) {
    for (const auto& d : denominations) {
      if (i - d >= 0) {
        min_change_for[i] =
            std::min(min_change_for[i], 1 + min_change_for[i - d]);
      }
    }
  }

  return min_change_for[k];
}

int main() {
  std::vector<int> denominations{1, 10, 25};
  std::cout << min_change(30, denominations) << std::endl;
}
