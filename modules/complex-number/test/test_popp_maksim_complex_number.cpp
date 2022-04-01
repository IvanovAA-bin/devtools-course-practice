// Copyright 2022 Popp Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Popp_Maksim_ComplexNumberTest, Operation_Plus) {
    ComplexNumber complexNum1(3, 2);
    ComplexNumber complexNum2(2, 3);

    ComplexNumber complexNum3 = complexNum1 + complexNum2;

    ASSERT_EQ(complexNum3.getRe(), 5);
    ASSERT_EQ(complexNum3.getIm(), 5);
}

TEST(Popp_Maksim_ComplexNumberTest, Operation_Minus) {
    ComplexNumber complexNum1(3, 2);
    ComplexNumber complexNum2(2, 3);

    ComplexNumber complexNum3 = complexNum1 - complexNum2;

    ASSERT_EQ(complexNum3.getRe(), 1);
    ASSERT_EQ(complexNum3.getIm(), -1);
}

TEST(Popp_Maksim_ComplexNumberTest, Operation_Multiply) {
    ComplexNumber complexNum1(3, 2);
    ComplexNumber complexNum2(2, 3);

    ComplexNumber complexNum3 = complexNum1 * complexNum2;

    ASSERT_EQ(complexNum3.getRe(), 0);
    ASSERT_EQ(complexNum3.getIm(), 13);
}

TEST(Popp_Maksim_ComplexNumberTest, Operation_Divide) {
    ComplexNumber complexNum1(1, 1);
    ComplexNumber complexNum2(1, 1);

    ComplexNumber complexNum3 = complexNum1 / complexNum2;

    ASSERT_EQ(complexNum3.getRe(), 1);
    ASSERT_EQ(complexNum3.getIm(), 0);
}
