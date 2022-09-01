#include <cstdio>

#include "Node.h"

void delBinaryTree(Node *&head);

int main() {
  Node *head = new Node(5);
  head->left = new Node(3);
  head->right = new Node(8);
  head->left->left = new Node(2);
  head->left->right = new Node(4);
  head->left->left->left = new Node(1);
  head->right->left = new Node(7);
  head->right->left->left = new Node(6);
  head->right->right = new Node(10);
  head->right->right->left = new Node(9);
  head->right->right->right = new Node(11);

  // recursive
  printf("==============recursive==============\n");
  printf("pre-order: ");
  Node::preOrderRecur(head);
  printf("\n");
  printf("in-order: ");
  Node::inOrderRecur(head);
  printf("\n");
  printf("pos-order: ");
  Node::posOrderRecur(head);
  printf("\n");

  // unrecursive
  printf("\n============unrecursive=============\n");
  Node::preOrderUnRecur(head);
  Node::inOrderUnRecur(head);
  Node::posOrderUnRecur(head);

  delBinaryTree(head);
  printf("The binary tree is deleted successfully...\n");

  return 0;
}
