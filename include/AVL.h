/* 
 * @file                AVL.h
 * @description         AVL agac header
 *data                  08/23/2022
 * @author              MAHMOUD ALABDOLLA
*/


#ifndef AVL_HEADER
#define AVL_HEADER

#include <functional>
#include <iostream>

class AVL {
public:
  int key;
  AVL *left;
  AVL *right;
  int height;

  const int getHeight(const AVL *node) const;
  AVL* newNode(const int& anahtar);
  AVL *rightRotate(AVL *node);
  AVL *leftRotate(AVL *node);
  const int getBalance(AVL*& node);
  AVL* insert(AVL*& node, const int& anahtar);
  void preOrder(AVL *root, const std::function<void(int, bool)>& fn, const bool& yukari);
};

#endif /* AVL_HEADER */
