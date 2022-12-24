#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

std::ostream& operator<<(std::ostream &out, const Node &a) {
  out << a.data;
  return out;
}
#endif