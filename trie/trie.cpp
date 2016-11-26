#include <iostream>
#include <memory>
#include <queue>
#include <unordered_map>

struct trie_node {
  bool word_end = false;
  std::unordered_map<char, std::unique_ptr<trie_node>> children;
};

class trie {
 public:
  trie() : root(new trie_node()) {}

  void insert(const std::string& s) {
    trie_node* cur = root.get();
    for (const char& c : s) {
      if (cur->children.find(c) == cur->children.end()) {
        cur->children.emplace(c, new trie_node());
      }
      cur = cur->children[c].get();
    }
    cur->word_end = true;
  }

  // Determines if s is in the trie.
  bool contains(const std::string& s) const {
    trie_node* cur = root.get();
    for (const char& c : s) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c].get();
    }
    return true;
  }

  // Determines if there are any complete words in the trie that are a prefix of
  // s.
  bool has_prefix(const std::string& s) const {
    trie_node* cur = root.get();
    for (const char& c : s) {
      if (cur->word_end) {
        return true;
      }
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c].get();
    }
    return false;
  }

 private:
  std::unique_ptr<trie_node> root;
};

int main() {
  trie t;

  t.insert("abcd");
  t.insert("abc");

  std::cout << t.contains("b") << " " << t.contains("abcd") << std::endl;
  std::cout << t.has_prefix("abcd") << std::endl;

  return 0;
}
