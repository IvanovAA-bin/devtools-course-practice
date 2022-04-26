// Copyright 2022 Gordeev Viktor

#include "include/AVLTree.h"

unsigned char AVLTree::height(node *root) {
    return root ? root->height : 0;
}

int AVLTree::bfactor(node *root) {
    return height(root->right) - height(root->left);
}

void AVLTree::fixheight(node *root) {
    unsigned char hl = height(root->left);
    unsigned char hr = height(root->right);
    root->height = (hl > hr ? hl : hr) + 1;
}

AVLTree::node *AVLTree::rotateright(node *root) {
    node *q = root->left;
    root->left = q->right;
    q->right = root;
    fixheight(root);
    fixheight(q);
    return q;
}

AVLTree::node *AVLTree::rotateleft(node *tmp) {
    node *root = tmp->right;
    tmp->right = root->left;
    root->left = tmp;
    fixheight(tmp);
    fixheight(root);
    return root;
}

AVLTree::node *AVLTree::balance(node *root) {
    fixheight(root);
    return root;
}

AVLTree::node *AVLTree::insert(node *root, int k) {
    if (!root) return new node(k);
    if (k < root->key)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);
    return balance(root);
}

AVLTree::node *AVLTree::findmin(node *root) {
    return root->left ? findmin(root->left) : root;
}

AVLTree::node *AVLTree::removemin(node *root) {
    if (root->left == 0)
        return root->right;
    root->left = removemin(root->left);
    return balance(root);
}

AVLTree::node *AVLTree::remove(node *root, int k) {
    if (!root) {
        return nullptr;
    }
    if (k < root->key) {
        root->left = remove(root->left, k);
    } else {
        node *q = root->left;
        node *r = root->right;
        delete root;
        if (!r) return q;
        node *min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(root);
}
