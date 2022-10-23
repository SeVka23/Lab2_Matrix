#include "gtest.h"
#include "TMatrix.h"

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, can_get_size)
{
  TDynamicMatrix<int> m(4);

  EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
  TDynamicMatrix<int> m1(2), m2(2);
  m1 = m2;
  EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TDynamicMatrix<int> m1(2);
  EXPECT_TRUE(m1 == m1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TDynamicMatrix<int> m1(2), m2(4);
  EXPECT_TRUE(m1 != m2);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 + m2;
  EXPECT_EQ(m3[0][0], 3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_subtract_matrixes_with_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 - m2;
  ASSERT_NO_THROW(m1 - m2);
  EXPECT_EQ(m3[0][0], -1);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 * m2);
}

TEST(TDynamicMatrix, can_equate_matrixes)
{
  TDynamicMatrix<int> m1(2), m2(4);
  ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
  TDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 * m2;
  EXPECT_EQ(m3[0][0], 2);
  EXPECT_EQ(m3[1][0], 4);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_vector)
{
  TDynamicMatrix<int> m1(2);
  TDynamicVector<int> v(2), vres;
  m1[0][0] = 1;
  m1[1][0] = 2;
  m1[1][1] = 4;
  v[0] = 1;
  v[1] = 2;
  vres = m1 * v;
  EXPECT_EQ(vres[0], 5);
  EXPECT_EQ(vres[1], 8);
}

TEST(TDynamicMatrix, cant_multiply_matrix_by_vector_with_not_equal)
{
  TDynamicMatrix<int> m1(2);
  TDynamicVector<int> v(3);
  ASSERT_ANY_THROW(m1 * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_by_scalar)
{
  TDynamicMatrix<int> mat(2);
  mat[0][0] = 2;
  mat[1][0] = 3;
  mat[1][1] = 5;
  TDynamicMatrix<int> res = mat * 2;
  EXPECT_EQ(res[0][0], 4);
  EXPECT_EQ(res[1][0], 6);
  EXPECT_EQ(res[1][1], 10);
}
