#include <iostream>
#include <unordered_map>
#include <queue>

struct trie_node {
  bool word_end = false;
  std::unordered_map<char, trie_node*> children;
};

class trie {
public:
  trie() : root(new trie_node()) {}

  void insert(const std::string& s) {
    trie_node* cur = root;
    for (const char& c : s) {
      if (cur->children.find(c) == cur->children.end()) {
        cur->children.insert({c, new trie_node()});
      }
      cur = cur->children[c];
    }
    cur->word_end = true;
  }

  // Determines if s is in the trie.
  bool contains(const std::string& s) const {
    trie_node* cur = root;
    for (const char& c : s) {
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return true;
  }

  // Determines if there are any complete words in the trie that are a prefix of
  // s.
  bool has_prefix(const std::string& s) const {
    trie_node* cur = root;
    for (const char& c : s) {
      if (cur->word_end) {
        return true;
      }
      if (cur->children.find(c) == cur->children.end()) {
        return false;
      }
      cur = cur->children[c];
    }
    return false;
  }

  // Performs a breadth-first search of the trie and deletes all of the nodes.
  ~trie() {
    std::queue<trie_node*> q;
    q.push(root);
    while (!q.empty()) {
      trie_node* front = q.front();
      q.pop();
      for (auto p : front->children) {
        q.push(p.second);
      }
      delete front;
    }
  }
private:
  trie_node* root;
};

int main() {
  trie t;

  t.insert("abcd");
  t.insert("abc");

  std::cout << t.contains("b") << " " << t.contains("abcd") << std::endl;
  std::cout << t.has_prefix("abcd") << std::endl;

  return 0;
}
