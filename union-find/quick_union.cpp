#include <cstdint>
#include <iostream>
#include <string>
#include <unordered_map>

// An implementation of a "quick union" union find data structure, which uses
// path compression to improve the performance of connected queries.
template <class T>
class quick_union {
 public:
  void init_vertex(const T& u) {
    if (parents.find(u) == parents.end()) {
      parents[u] = u;
      sizes[u] = 1;
    }
  }

  // Always add the smaller set to the larger set in order to minimize the depth
  // of the tree.
  void connect(const T& u, const T& v) {
    init_vertex(u);
    init_vertex(v);

    if (u == v) {
      return;
    }

    const T& root1 = root(u);
    const T& root2 = root(v);

    if (sizes[root1] > sizes[root2]) {
      parents[root2] = root1;
      sizes[root2] += sizes[root1];
    } else {
      parents[root1] = root2;
      sizes[root1] += sizes[root2];
    }
  }

  // Returns the root of the tree which U belongs to. Uses path compression in
  // order to speed up future queries.
  T root(const T& u) {
    auto iter = parents.find(u);
    if (iter->first != iter->second) {
      T ancestor = root(iter->second);
      iter->second = ancestor;
      return ancestor;
    }
    return iter->first;
  }

  // Checks if two objects are connected by compare the roots of their
  // respective sets.
  bool connected(const T& u, const T& v) {
    if (parents.find(u) == parents.end() || parents.find(v) == parents.end()) {
      return false;
    }
    return root(u) == root(v);
  }

 private:
  std::unordered_map<T, T> parents;
  std::unordered_map<T, std::uint32_t> sizes;
};

int main() {
  std::uint32_t n;
  std::cin >> n;

  quick_union<std::string> union_find{};

  for (std::uint32_t i = 0; i < n; ++i) {
    std::string u, v;
    std::cin >> u >> v;
    union_find.connect(u, v);
  }

  std::cin >> n;
  for (std::uint32_t i = 0; i < n; ++i) {
    std::string u, v;
    std::cin >> u >> v;
    std::cout << (union_find.connected(u, v) ? "yes" : "no") << std::endl;
  }

  return 0;
}
