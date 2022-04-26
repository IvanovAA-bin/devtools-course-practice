// Copyright 2022 Gordeev Viktor
#include <gtest/gtest.h>

#include "include/AVLTree.h"

TEST(Gordeev_Viktor_AVLTree, AVLTree_Create_No_Throw) {
    ASSERT_NO_THROW(AVLTree());
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Create_Node_No_Throw) {
    ASSERT_NO_THROW(AVLTree::node(4));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Insert_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    ASSERT_NO_THROW(avlTree.insert(&p, 4));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Create_With_Nodes) {
    AVLTree avlTree = AVLTree();
    AVLTree::node node1 = AVLTree::node(4);
    AVLTree::node node2 = AVLTree::node(5);
    AVLTree::node node3 = AVLTree::node(6);
    AVLTree::node node4 = AVLTree::node(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;
    avlTree.height(&node1);
    ASSERT_NO_THROW(AVLTree());
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Rotate_Right) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    AVLTree::node q = AVLTree::node(2);
    AVLTree::node c = AVLTree::node(5);
    AVLTree::node a = AVLTree::node(1);
    AVLTree::node b = AVLTree::node(3);
    p.left = &q;
    p.right = &c;
    q.left = &a;
    q.right = &b;
    ASSERT_NO_THROW(avlTree.rotateright(&p));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Rotate_Right_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    AVLTree::node q = AVLTree::node(2);
    AVLTree::node c = AVLTree::node(5);
    AVLTree::node a = AVLTree::node(1);
    AVLTree::node b = AVLTree::node(3);
    p.left = &q;
    p.right = &c;
    q.left = &a;
    q.right = &b;
    avlTree.rotateright(&p);
    ASSERT_EQ(p.left->key, 3);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Rotate_Left) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    AVLTree::node q = AVLTree::node(2);
    AVLTree::node c = AVLTree::node(5);
    AVLTree::node a = AVLTree::node(1);
    AVLTree::node b = AVLTree::node(3);
    p.left = &b;
    p.right = &c;
    q.left = &a;
    q.right = &p;
    ASSERT_NO_THROW(avlTree.rotateleft(&q));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Rotate_Left_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    AVLTree::node q = AVLTree::node(2);
    AVLTree::node c = AVLTree::node(5);
    AVLTree::node a = AVLTree::node(1);
    AVLTree::node b = AVLTree::node(3);
    p.left = &b;
    p.right = &c;
    q.left = &a;
    q.right = &p;
    avlTree.rotateleft(&q);
    ASSERT_EQ(q.right->key, 3);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Balance_Tree) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    ASSERT_NO_THROW(avlTree.balance(&p));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Balance_Tree_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);

    ASSERT_EQ(avlTree.height(&p), 3);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Fix_Height_Tree_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);
    p.height = 5;
    avlTree.fixheight(&p);

    ASSERT_EQ(avlTree.height(&p), 3);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Balance_Factor_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);

    ASSERT_EQ(avlTree.bfactor(&p), 0);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Find_Min_Correct) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);

    ASSERT_EQ(avlTree.findmin(&p)->key, 1);
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Remove_Min) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);
    ASSERT_NO_THROW(avlTree.removemin(&p));
}

TEST(Gordeev_Viktor_AVLTree, AVLTree_Can_Remove) {
    AVLTree avlTree = AVLTree();
    AVLTree::node p = AVLTree::node(4);
    avlTree.insert(&p, 4);
    avlTree.insert(&p, 2);
    avlTree.insert(&p, 5);
    avlTree.insert(&p, 1);
    avlTree.insert(&p, 3);
    avlTree.balance(&p);
    avlTree.remove(nullptr, 5);
    avlTree.remove(&p, 1);
    avlTree.remove(&p, 2);
    ASSERT_NO_THROW();
}
