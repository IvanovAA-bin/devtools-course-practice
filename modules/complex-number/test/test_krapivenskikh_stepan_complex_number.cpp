// Copyright 2022 Krapivenskikh Stepan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Stepakrap_ComplexNumberTest, Can_Create_Real_Nubmer) {
  double re = 14.0;
  double im = 0.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Stepakrap_ComplexNumberTest, Can_Imaginary_Nubmer) {
  double re = 0.0;
  double im = 7.0;

  ComplexNumber z(re, im);

  EXPECT_EQ(re, z.getRe());
  EXPECT_EQ(im, z.getIm());
}

TEST(Stepakrap_ComplexNumberTest, MultiplyTest) {
  ComplexNumber cn1(8, 4);
  ComplexNumber cn2(6, 3);

  ComplexNumber cn3 = cn1 * cn2;

  ASSERT_EQ(cn3.getRe(), 36);
  ASSERT_EQ(cn3.getIm(), 48);
}
