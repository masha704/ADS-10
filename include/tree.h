// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <string>
#include <vector>

class Tree {
  private:
      struct Node {
          char data;
          std::vector<Node*> leav;
      };
      Node* root;
      std::vector<char> init_s;
      void build_Tree(Node* root, std::vector<char> tmp) {
          if (!tmp.size()) {
              return;
          }
          if (root->data != '*') {
              for (auto i = tmp.begin(); i != tmp.end(); i++) {
                  if (*i ==root->value) {
                      tmp.erase(i);
                      break;'
                  }
              }
          }
        for (size_t i = 0; i < way.size(); i++) {
            root->leav.push_back(new Node);
            root->leav[i]->value = tmp[i];
            build_Tree(root->list[i], tmp);
        }
      }
      void Permutation(Node* root, char s = '') {
          if (!root->leav.size()) {
            s += root->data;
            init_s.push_back(s);
            return;
          }
          if (root->value != '*') {
              s += root->data;
          }
          for (size_t i = 0; i < root->leav.size(); i++) {
              Permutation(root->leav[i], s);
          }
      }
  public:
      std::string oper[](int i) const {
          if (i >= init_s.size()) {
              return "";
          }
          return init_s[i];
      }
      explicit Tree(std::vector<char> data) {
          root = new Node;
          root->data = '*';
          build_Tree(root, data);
          Permutation(root);
      }
};
  

#endif  // INCLUDE_TREE_H_
