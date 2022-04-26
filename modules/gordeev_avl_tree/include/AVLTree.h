// Copyright 2022 Gordeev Viktor

#ifndef MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_
#define MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_

#include <iostream>

class AVLTree {
 public:
    // struct to image tree knots and root
    struct node {
        node() {
            left = right = nullptr;
            height = 1;
        }

        int key{};
        unsigned char height;
        node *left;
        node *right;

        explicit node(int k) {
            key = k;
            left = right = nullptr;
            height = 1;
        }
    };

    AVLTree() = default;;

    // Height of the tree
    unsigned char height(node *root);

    // Calculate balance factor
    int bfactor(node *root);

    void fixheight(node *root);

    node *rotateright(node *root);

    node *rotateleft(node *root);

    node *balance(node *root);

    node *insert(node *root, int k);

    node *findmin(node *root);

    node *removemin(node *root);

    node *remove(node *root, int k);
};

#endif  // MODULES_GORDEEV_AVL_TREE_INCLUDE_AVLTREE_H_
