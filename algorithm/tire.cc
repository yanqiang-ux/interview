#include <iostream>
#include <map>
#include <vector>
#include <cassert>
#include <queue>

class TireNode {
  std::map<uint8_t, TireNode*> childrens;
  uint64_t prefix = 0;
  uint64_t count = 0;
  public:
  TireNode() {};
  // TireNode(uint64_t _prefix) {}
  void insert(std::string node) {
    TireNode* cur = this;
    for (auto &c : node) {
      if (cur->childrens[c] == nullptr) {
        cur->childrens[c] = new TireNode();
        cur = cur->childrens[c];
        cur->prefix++;
      }
    }
    cur->count++;
  }

  bool search(std::string node) {
    TireNode* cur = this;
    for (auto &c : node) {
      if (cur->childrens[c] != nullptr) {
        cur = cur->childrens[c];
      } else {
        return false;
      }
    }
    if (cur->count) {
      return true;
    }
    return false;
  }

  uint64_t search_prefix(std::string pre) {
    TireNode* cur = this;
    for (auto &c : pre) {
      if (cur->childrens[c] == nullptr) {
        return 0;
      } else {
        cur = cur->childrens[c];
      }
    }
    return cur->prefix;
  }

  void delete_node(std::string node) {
    TireNode* cur = this;
    for (auto &c : node) {
      if (cur->childrens[c] == nullptr) {
        return;
      } else {
        TireNode* tmp = cur;
        cur = cur->childrens[c];
        cur->prefix--;
        if (!cur->prefix) {
          tmp->childrens.erase(tmp->childrens.find(c));
          recursive_delete(cur);
          return;
        }
      }
    }
  }
  void recursive_delete(TireNode* node) {
    std::queue<TireNode*> delete_queue;
    delete_queue.emplace(node);
    while(!delete_queue.empty()) {
      TireNode* tmp = delete_queue.front();
      for (auto &entry : tmp->childrens) {
        delete_queue.push(entry.second);
      }
      delete_queue.pop();
      delete tmp;
    }
  }
};

int main() {
  TireNode * root = new TireNode();
  std::vector<std::string> nodes = {"b", "string", "abcdef", "fghakldj"};
  for (int i = 0; i < nodes.size(); i++) {
    root->insert(nodes[i]);
  }
  assert(root->search("string"));
  std::cout << root->search_prefix("string") << std::endl;
  root->delete_node("string");
  assert(!root->search("string"));
}
