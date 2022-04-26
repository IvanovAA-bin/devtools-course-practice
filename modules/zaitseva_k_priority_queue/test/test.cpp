// Copyright 2022 Zaitseva Ksenia

#include <gtest/gtest.h>
#include <vector>

#include "include/priority_queue.h"

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    default_constractor) {
    ASSERT_NO_THROW(PriorityQueue<float> Q{});
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    copy_empty_priority_queue) {
    PriorityQueue<int> Q1;
    ASSERT_NO_THROW(PriorityQueue<int>(Q1));
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_push) {
    PriorityQueue<int> Q;
    ASSERT_NO_THROW(Q.push(1));
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_pop_correctly) {
    PriorityQueue<int> Q;
    Q.push(-3);
    EXPECT_EQ(Q.pop(), -3);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    is_empty) {
    PriorityQueue<int> Q;

    ASSERT_TRUE(Q.isEmpty());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    is_not_empty) {
    PriorityQueue<int> Q;

    Q.push(0);

    ASSERT_FALSE(Q.isEmpty());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_not_pop_form_empty_queue) {
    PriorityQueue<int> Q;

    ASSERT_ANY_THROW(Q.pop());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_copy_correctly) {
    PriorityQueue<int> Q1;
    PriorityQueue<int> Q2;

    Q1.push(1);
    Q2 = Q1;

    EXPECT_EQ(Q1.pop(), Q2.pop());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_get_size) {
    PriorityQueue<int> Q1;

    Q1.push(1);
    Q1.push(2);

    EXPECT_EQ(Q1.size(), 2);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, can_assign_queue_to_itself) {
    PriorityQueue<int> Q;

    Q.push(1);
    Q.push(2);

    ASSERT_NO_THROW(Q = Q);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_assign_queue_of_different_size_correctly) {
    PriorityQueue<double> Q1;
    PriorityQueue<double> Q2;

    Q1.push(0.9);
    Q1.push(0.5);
    Q2 = Q1;

    EXPECT_DOUBLE_EQ(Q1.pop(), Q2.pop());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, can_push_bigger_number) {
    PriorityQueue<int> Q;

    Q.push(1);
    Q.push(9);

    EXPECT_EQ(Q.pop(), 9);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, can_push_lesser_number) {
    PriorityQueue<int> Q;

    Q.push(9);
    Q.push(1);

    EXPECT_EQ(Q.pop(), 9);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, can_push_equal_number) {
    PriorityQueue<int> Q;

    Q.push(9);
    Q.push(9);

    EXPECT_EQ(Q.pop(), 9);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, pop_equal_number) {
    PriorityQueue<int> Q;

    Q.push(9);
    Q.push(9);
    Q.pop();

    ASSERT_FALSE(Q.isEmpty());
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests, can_pop_in_right_order) {
    PriorityQueue<int> Q;
    std::vector<int> res;
    std::vector<int> expected_res{9, 4, 1, 0, -2, -3};

    Q.push(1);
    Q.push(-2);
    Q.push(9);
    Q.push(-3);
    Q.push(4);
    Q.push(0);
    while (!Q.isEmpty()) {
        res.push_back(Q.pop());
    }

    EXPECT_EQ(res, expected_res);
}

TEST(Zaitseva_Ksenia_Priority_Queue_Tests,
    can_pop_in_right_order_with_equal_numbers) {
    PriorityQueue<int> Q;
    std::vector<int> res;
    std::vector<int> expected_res{ 10, 7, 3, 1, 0, 0 };

    Q.push(1);
    Q.push(3);
    Q.push(0);
    Q.push(7);
    Q.push(0);
    Q.push(10);
    while (!Q.isEmpty()) {
        res.push_back(Q.pop());
    }

    EXPECT_EQ(res, expected_res);
}
