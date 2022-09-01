//
// Created by zyf on 2022/9/1.
//

#include <cstdio>
#include <stack>

#include "Node.h"

using namespace std;

void Node::preOrderRecur(Node *head) {
  if (head == nullptr)
    return;
  printf("%d ", head->value);
  preOrderRecur(head->left);
  preOrderRecur(head->right);
}

void Node::inOrderRecur(Node *head) {
  if (head == nullptr)
    return;
  inOrderRecur(head->left);
  printf("%d ", head->value);
  inOrderRecur(head->right);
}

void Node::posOrderRecur(Node *head) {
  if (head == nullptr)
    return;
  posOrderRecur(head->left);
  posOrderRecur(head->right);
  printf("%d ", head->value);
}

void Node::preOrderUnRecur(Node *head) {
  printf("pre-order: ");
  if (head != nullptr) {
    auto *s = new stack<Node *>();
    s->push(head);
    while (!s->empty()) {
      head = s->top();
      s->pop();
      printf("%d ", head->value);

      if (head->right != nullptr)
        s->push(head->right);
      if (head->left != nullptr)
        s->push(head->left);
    }
    delete s;
  }
  printf("\n");
}

void Node::inOrderUnRecur(Node *head) {
  printf("in-order: ");
  if (head != nullptr) {
    auto *s = new stack<Node *>();
    while (!s->empty() || head != nullptr) {
      if (head != nullptr) {
        s->push(head);
        head = head->left;
      } else {
        head = s->top();
        s->pop();
        printf("%d ", head->value);
        head = head->right;
      }
    }
    delete s;
  }
  printf("\n");
}

void Node::posOrderUnRecur(Node *head) {
  printf("pos-order: ");
  if (head != nullptr) {
    auto *s1 = new stack<Node *>();
    auto *s2 = new stack<Node *>();
    s1->push(head);

    while (!s1->empty()) {
      head = s1->top();
      s1->pop();
      s2->push(head);
      if (head->left != nullptr)
        s1->push(head->left);
      if (head->right != nullptr)
        s1->push(head->right);
    }

    while (!s2->empty()) {
      printf("%d ", s2->top()->value);
      s2->pop();
    }

    delete s1;
    delete s2;
  }
  printf("\n");
}

void delBinaryTree(Node *&head) {
  if (head == nullptr)
    return;
  delBinaryTree(head->left);
  delBinaryTree(head->right);

  delete head;
  head = nullptr;
}

