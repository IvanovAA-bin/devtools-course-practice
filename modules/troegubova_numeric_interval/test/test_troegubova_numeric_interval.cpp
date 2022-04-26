// Copyright 2022 Troegubova Alexandra

#include <gtest/gtest.h>
#include <vector>

#include "include/numeric_interval.h"

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctness_Of_The_Default_Constructor) {
    ASSERT_NO_THROW(NamericInterval a);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctnes_Of_The_Constructor_With_Parameters_1) {
    ASSERT_NO_THROW(NamericInterval a(1, 7, true, true));
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctnes_Of_The_Constructor_With_Parameters_2) {
    ASSERT_NO_THROW(NamericInterval a(-7, 7, false, true));
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctnes_Of_The_Constructor_With_Parameters_3) {
    ASSERT_NO_THROW(NamericInterval a(-15, -3, true, false));
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_The_Border_Points_1) {
    int a = 1;
    int b = 20;
    bool c = true;
    bool d = false;
    NamericInterval z(a, b, c, d);

    std::vector<int> res = z.getBorderPoint();

    ASSERT_TRUE(a == res[0] && b - 1 == res[1]);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_The_Border_Points_2) {
    int a = -10;
    int b = 20;
    bool c = true;
    bool d = true;
    NamericInterval z(a, b, c, d);

    std::vector<int> res = z.getBorderPoint();

    ASSERT_TRUE(a == res[0] && b == res[1]);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_The_Border_Points_3) {
    int a = -4;
    int b = 20;
    bool c = false;
    bool d = true;
    NamericInterval z(a, b, c, d);

    std::vector<int> res = z.getBorderPoint();

    ASSERT_TRUE(a + 1 == res[0] && b == res[1]);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_Can_Return_All_Integer_Points_1) {
    int a = 1;
    int b = 20;
    bool c = true;
    bool d = false;
    NamericInterval z(a, b, c, d);

    bool flag = true;
    std::vector<int> res = z.getAllIntegerPoint();
    int i = 0;
    int size = res.size();
    if (size == b - a) {
        for (int j = a; j < b; j++) {
            if (res[i++] != j) {
                flag = false;
            }
        }
    } else {
        flag = false;
    }

    ASSERT_TRUE(flag);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_Can_Return_All_Integer_Points_2) {
    int a = -10;
    int b = 0;
    bool c = true;
    bool d = true;
    NamericInterval z(a, b, c, d);

    bool flag = true;
    std::vector<int> res = z.getAllIntegerPoint();
    int i = 0;
    int size = res.size();
    if (size == b - a + 1) {
        for (int j = a; j <= b; j++) {
            if (res[i++] != j) {
                flag = false;
            }
        }
    } else {
        flag = false;
    }

    ASSERT_TRUE(flag);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Can_Return_Can_Return_All_Integer_Points_3) {
    int a = -6;
    int b = 3;
    bool c = false;
    bool d = true;
    NamericInterval z(a, b, c, d);

    bool flag = true;
    std::vector<int> res = z.getAllIntegerPoint();
    int i = 0;
    int size = res.size();
    if (size == b - a) {
        for (int j = a + 1; j <= b; j++) {
            if (res[i++] != j) {
                flag = false;
            }
        }
    } else {
        flag = false;
    }

    ASSERT_TRUE(flag);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Another_Interval_1) {
    NamericInterval a(3, 15, true, false);
    NamericInterval b(4, 9, false, false);

    bool res = a.containsInterval(b);

    ASSERT_TRUE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Another_Interval_2) {
    NamericInterval a(3, 8, true, true);
    NamericInterval b(4, 9, false, false);

    bool res = a.containsInterval(b);

    ASSERT_FALSE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Another_Interval_3) {
    NamericInterval a(4, 8, false, true);
    NamericInterval b(4, 5, true, true);

    bool res = a.containsInterval(b);

    ASSERT_FALSE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Another_Interval_4) {
    NamericInterval a(0, 5, true, false);
    NamericInterval b(4, 5, true, true);

    bool res = a.containsInterval(b);

    ASSERT_FALSE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Integer_Range_1) {
    NamericInterval a(3, 8, true, false);
    std::vector<int> range = { 5, 3, 6, 8 };

    bool res = a.containsIntegerRange(range);

    ASSERT_FALSE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Inclusion_Of_Integer_Range_2) {
    NamericInterval a(3, 8, true, false);
    std::vector<int> range = { 3, 6, 4, 5};

    bool res = a.containsIntegerRange(range);

    ASSERT_TRUE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Intersection_With_Another_Interval_1) {
    NamericInterval a(3, 8, true, false);
    NamericInterval b(1, 8, false, false);

    bool res = a.overlapsRange(b);

    ASSERT_TRUE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctly_Detects_The_Intersection_With_Another_Interval_2) {
    NamericInterval a(3, 8, true, false);
    NamericInterval b(8, 13, true, false);

    bool res = a.overlapsRange(b);

    ASSERT_FALSE(res);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctness_Of_The_Equality_Operator_1) {
    NamericInterval a(3, 8, true, false);
    NamericInterval b(3, 8, true, false);

    ASSERT_TRUE(a == b);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    Correctness_Of_The_Equality_Operator_2) {
    NamericInterval a(3, 8, true, false);
    NamericInterval b(3, 8, false, false);

    ASSERT_FALSE(a == b);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    The_Correctness_Of_The_Operator_Is_Not_Equality_1) {
    NamericInterval a(3, 8, true, false);
    NamericInterval b(-10, 8, false, false);

    ASSERT_TRUE(a != b);
}

TEST(Troegubova_Alexandra_Numeric_Interval_Test,
    The_Correctness_Of_The_Operator_Is_Not_Equality_2) {
    NamericInterval a(-3, 8, true, true);
    NamericInterval b(-3, 8, true, true);

    ASSERT_FALSE(a != b);
}
