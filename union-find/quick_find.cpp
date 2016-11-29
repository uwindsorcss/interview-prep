#include <cstdint>
#include <iostream>
#include <vector>

// A "quick_find" implementation of the union find data structure using a simple
// array of integer. This implementation is only meant to serve as a
// demonstration of the simplicity of the data structure, but the "quick union"
// implementation is preferred for performance reasons.
class quick_find {
 public:
  // When the union find is first initialized, each object is in it's own
  // connected component.
  quick_find(std::uint32_t n) : id_(n) {
    for (std::uint32_t i = 0; i < n; ++i) {
      id_[i] = i;
    }
  }

  // Simply check if both objects have the same id to see if they are connected.
  bool connected(std::uint32_t p, std::uint32_t q) { return id_[p] == id_[q]; }

  // In order to connect p and q, all objects with the same id as q should have
  // their ids set to that of p.
  void connect(std::uint32_t p, std::uint32_t q) {
    std::uint32_t p_id = id_[p];
    std::uint32_t q_id = id_[q];

    if (p_id == q_id) {
      return;
    }

    for (std::uint32_t i = 0; i < id_.size(); ++i) {
      if (id_[i] == q_id) {
        id_[i] = p_id;
      }
    }

    for (auto i : id_) std::cout << i << " ";
    std::cout << std::endl;
  }

 private:
  std::vector<std::uint32_t> id_;
};

int main() {
  std::uint32_t n;
  std::cin >> n;

  quick_find qf(n);
  std::cin >> n;
  while (n--) {
    std::uint32_t p, q;
    std::cin >> p >> q;
    qf.connect(p, q);
  }

  std::cin >> n;
  while (n--) {
    std::uint32_t p, q;
    std::cin >> p >> q;
    std::cout << qf.connected(p, q) << std::endl;
  }
  return 0;
}
