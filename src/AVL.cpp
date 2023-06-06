#include "../include/AVL.h"

const int AVL::getHeight(const AVL*node) const {
  return node == NULL ? 0 : node->height;
}


AVL* AVL::newNode(const int& anahtar) {
  AVL* node = new AVL();
  node->key = anahtar;
  node->right = NULL;
  node->left = NULL;
  node->height = !0;
  return node;
}

AVL* AVL::rightRotate(AVL *node) {
  AVL *side1 = node->left;
  AVL *side2 = side1->right;

  side1->right = node;
  node->left = side2;

  node->height = std::max(getHeight(node->left),
      getHeight(node->right)) + 1;
  side1->height = std::max(getHeight(side1->left),
      getHeight(side1->right)) + 1;

  return side1;
}

AVL* AVL::leftRotate(AVL *node) {
  AVL *side2 = node->right;
  AVL *side1 = side2->left;

  side2->left = node;
  node->right = side1;

  node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
  side2->height = std::max(getHeight(side2->left), getHeight(side2->right)) + 1;

  return side2;
}

const int AVL::getBalance(AVL*& node) {
  return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
}

AVL* AVL::insert(AVL*& node, const int& anahtar) {
  if (node == NULL) return newNode(anahtar);

  if (anahtar < node->key) node->left = insert(node->left, anahtar);
  else if (anahtar > node->key) node->right = insert(node->right, anahtar);
  else return node;

  node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;

  int balance = getBalance(node);
  bool bigger = balance > 1;
  bool smaller = balance < -1;

  if (bigger && anahtar < node->left->key) {
    return rightRotate(node);
  }

  else if (smaller && anahtar > node->right->key) {
    return leftRotate(node);
  }

  else if (bigger && anahtar > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (smaller && anahtar < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void AVL::preOrder(AVL *root, const std::function<void(int, bool)>& fn, const bool& yukari) {
  if(root != NULL) {
    fn(root->key, yukari);
    preOrder(root->left, fn, true);
    preOrder(root->right, fn, false);
  }
}

