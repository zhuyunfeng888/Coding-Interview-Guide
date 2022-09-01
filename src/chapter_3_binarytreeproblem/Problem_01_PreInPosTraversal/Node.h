//
// Created by zyf on 2022/9/1.
//

#ifndef PROBLEM_01_PREINPOSTRAVERSAL__NODE_H_
#define PROBLEM_01_PREINPOSTRAVERSAL__NODE_H_

class Node {
 public:
  Node() = default;

  explicit Node(int data)
      : value(data) {}

  ~Node() = default;

  static void preOrderRecur(Node *head);
  static void inOrderRecur(Node *head);
  static void posOrderRecur(Node *head);

  static void preOrderUnRecur(Node *head);
  static void inOrderUnRecur(Node *head);
  static void posOrderUnRecur(Node *head);

  int value{};
  Node *left{};
  Node *right{};
};

#endif //PROBLEM_01_PREINPOSTRAVERSAL__NODE_H_
