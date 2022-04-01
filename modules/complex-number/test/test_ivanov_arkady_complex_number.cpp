// Copyright 2022 Ivanov Arkady

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(ivanov_arkady_complex_number_test, correct_init_constructor) {
    const double real = 0.32, im = 42.231;
    ComplexNumber c(real, im);

    EXPECT_DOUBLE_EQ(real, c.getRe());
    EXPECT_DOUBLE_EQ(im, c.getIm());
}

TEST(ivanov_arkady_complex_number_test, correct_copy_constructor) {
    const double real = 0.32, im = 42.231;
    ComplexNumber c1(real, im);
    ComplexNumber c2(c1);

    EXPECT_DOUBLE_EQ(c1.getRe(), c2.getRe());
    EXPECT_DOUBLE_EQ(c1.getIm(), c2.getIm());
}

TEST(ivanov_arkady_complex_number_test, correct_eq_operator_1) {
    const double real = 0.32, im = 42.231;
    ComplexNumber c1(real, im);
    ComplexNumber c2(c1);

    EXPECT_TRUE(c1 == c2);
}

TEST(ivanov_arkady_complex_number_test, correct_eq_operator_2) {
    const double r1 = 0.32, im1 = 42.231;
    const double r2 = 0.320001, im2 = 42.2310001;
    ComplexNumber c1(r1, im1);
    ComplexNumber c2(r2, im2);

    EXPECT_FALSE(c1 == c2);
}

TEST(ivanov_arkady_complex_number_test, correct_setters) {
    const double real = 0.32, im = 42.231;
    ComplexNumber c;

    c.setRe(real);
    c.setIm(im);

    EXPECT_DOUBLE_EQ(real, c.getRe());
    EXPECT_DOUBLE_EQ(im, c.getIm());
}

TEST(ivanov_arkady_complex_number_test, correct_substr) {
    const double r1 = 0.32, im1 = 42.231;
    const double r2 = 53.53, im2 = 53.422;
    ComplexNumber c1(r1, im1);
    ComplexNumber c2(r2, im2);

    ComplexNumber c3 = c2 - c1;

    EXPECT_DOUBLE_EQ(r2 - r1, c3.getRe());
    EXPECT_DOUBLE_EQ(im2 - im1, c3.getIm());
}

TEST(ivanov_arkady_complex_number_test, correct_addit) {
    const double r1 = 0.32, im1 = 42.231;
    const double r2 = 53.53, im2 = 53.422;
    ComplexNumber c1(r1, im1);
    ComplexNumber c2(r2, im2);

    ComplexNumber c3 = c2 + c1;

    EXPECT_DOUBLE_EQ(r2 + r1, c3.getRe());
    EXPECT_DOUBLE_EQ(im2 + im1, c3.getIm());
}

TEST(ivanov_arkady_complex_number_test, correct_multip) {
    const double r1 = 0.32, im1 = 42.231;
    const double r2 = 53.53, im2 = 53.422;
    ComplexNumber c1(r1, im1);
    ComplexNumber c2(r2, im2);

    ComplexNumber c3 = c2 * c1;

    EXPECT_DOUBLE_EQ(r1 * r2 - im1 * im2, c3.getRe());
    EXPECT_DOUBLE_EQ(r1 * im2 + r2 * im1, c3.getIm());
}
