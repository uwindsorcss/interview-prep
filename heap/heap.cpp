#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template <class T, class Compare = std::less<T>>
class BinaryHeap {
 public:
  BinaryHeap() : compare_(Compare()) {}

  void push(T n) {
    heap_.push_back(n);
    bubble_up(heap_.size() - 1);
  }

  T top() const { return heap_[0]; }

  void pop() {
    std::swap(heap_.front(), heap_.back());
    heap_.pop_back();
    bubble_down(0);
  }

  void print_heap() const {
    std::copy(heap_.begin(), heap_.end(),
              std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
  }

  void build_heap() {
    for (std::size_t i = heap_.size() / 2; i > 0; --i) {
      bubble_up(i - 1);
    }
  }

 private:
  std::vector<T> heap_;
  Compare compare_;

  void bubble_down(std::size_t i) {
    std::size_t left = 2 * i + 1, right = 2 * i + 2;
    std::size_t k = i;

    if ((left < heap_.size()) && (compare_(heap_[left], heap_[i]))) k = left;
    if ((right < heap_.size()) && (compare_(heap_[right], heap_[k]))) k = right;

    if (k != i) {
      std::swap(heap_[i], heap_[k]);
      bubble_down(k);
    }
  }

  void bubble_up(std::size_t i) {
    std::size_t parent = i / 2;
    while (i > 0 && compare_(heap_[i], heap_[parent])) {
      std::swap(heap_[i], heap_[parent]);
      i = parent;
      parent = i / 2;
    }
  }
};

int main() {
  BinaryHeap<int, std::greater<int>> h;
  // BinaryHeap<int> h;
  int n;
  std::cin >> n;

  while (n--) {
    int tmp;
    std::cin >> tmp;
    h.push(tmp);
  }

  h.print_heap();

  std::cout << h.top() << std::endl;
  h.pop();

  h.print_heap();
  return 0;
}
