#include "gtest.h"
#include "TSquareMatrix.h"

TEST(TTriangleDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TTriangleDynamicMatrix<int> m(5));
}

TEST(TTriangleDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TTriangleDynamicMatrix<int> m(-5));
}

TEST(TTriangleDynamicMatrix, can_create_copied_matrix)
{
  TTriangleDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TTriangleDynamicMatrix<int> m1(m));
}

TEST(TTriangleDynamicMatrix, can_get_size)
{
  TTriangleDynamicMatrix<int> m(4);

  EXPECT_EQ(4, m.size());
}

TEST(TTriangleDynamicMatrix, compare_equal_matrices_return_true)
{
  TTriangleDynamicMatrix<int> m1(2), m2(2);
  m1 = m2;
  EXPECT_TRUE(m1 == m2);
}

TEST(TTriangleDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TTriangleDynamicMatrix<int> m1(2);
  EXPECT_TRUE(m1 == m1);
}

TEST(TTriangleDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TTriangleDynamicMatrix<int> m1(2), m2(4);
  EXPECT_TRUE(m1 != m2);
}

TEST(TTriangleDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 + m2);
}

TEST(TTriangleDynamicMatrix, can_add_matrices_with_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 + m2;
  EXPECT_EQ(m3[0][0], 3);
}

TEST(TTriangleDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 - m2);
}

TEST(TTriangleDynamicMatrix, can_subtract_matrixes_with_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(2), m3(2);
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

TEST(TTriangleDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 * m2);
}

TEST(TTriangleDynamicMatrix, can_equate_matrixes)
{
  TTriangleDynamicMatrix<int> m1(2), m2(4);
  ASSERT_NO_THROW(m1 = m2);
}

TEST(TTriangleDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
  TTriangleDynamicMatrix<int> m1(2), m2(2), m3(2);
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

TEST(TTriangleDynamicMatrix, can_multiply_matrix_by_vector)
{
  TTriangleDynamicMatrix<int> m1(2);
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

TEST(TTriangleDynamicMatrix, cant_multiply_matrix_by_vector_with_not_equal)
{
  TTriangleDynamicMatrix<int> m1(2);
  TDynamicVector<int> v(3);
  ASSERT_ANY_THROW(m1 * v);
}

TEST(TTriangleDynamicMatrix, can_multiply_matrix_by_scalar)
{
  TTriangleDynamicMatrix<int> mat(2);
  mat[0][0] = 2;
  mat[1][0] = 3;
  mat[1][1] = 5;
  TTriangleDynamicMatrix<int> res = mat * 2;
  EXPECT_EQ(res[0][0], 4);
  EXPECT_EQ(res[1][0], 6);
  EXPECT_EQ(res[1][1], 10);
}
TEST(TSquareDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TSquareDynamicMatrix<int> m(5));
}

TEST(TSquareDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TSquareDynamicMatrix<int> m(-5));
}

TEST(TSquareDynamicMatrix, can_create_copied_matrix)
{
  TSquareDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TSquareDynamicMatrix<int> m1(m));
}

TEST(TSquareDynamicMatrix, can_get_size)
{
  TSquareDynamicMatrix<int> m(4);

  EXPECT_EQ(4, m.size());
}

TEST(TSquareDynamicMatrix, compare_equal_matrices_return_true)
{
  TSquareDynamicMatrix<int> m1(2), m2(2);
  m1 = m2;
  EXPECT_TRUE(m1 == m2);
}

TEST(TSquareDynamicMatrix, compare_matrix_with_itself_return_true)
{
  TSquareDynamicMatrix<int> m1(2);
  EXPECT_TRUE(m1 == m1);
}

TEST(TSquareDynamicMatrix, matrices_with_different_size_are_not_equal)
{
  TSquareDynamicMatrix<int> m1(2), m2(4);
  EXPECT_TRUE(m1 != m2);
}

TEST(TSquareDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 + m2);
}

TEST(TSquareDynamicMatrix, can_add_matrices_with_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 + m2;
  EXPECT_EQ(m3[0][0], 3);
}

TEST(TSquareDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 - m2);
}

TEST(TSquareDynamicMatrix, can_subtract_matrixes_with_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(2), m3(2);
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

TEST(TSquareDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(4);
  ASSERT_ANY_THROW(m1 * m2);
}

TEST(TSquareDynamicMatrix, can_equate_matrixes)
{
  TSquareDynamicMatrix<int> m1(2), m2(4);
  ASSERT_NO_THROW(m1 = m2);
}

TEST(TSquareDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
  TSquareDynamicMatrix<int> m1(2), m2(2), m3(2);
  m1[0][0] = 1;
  m1[0][1] = 1;
  m1[1][0] = 1;
  m1[1][1] = 1;
  m2[0][0] = 2;
  m2[0][1] = 2;
  m2[1][0] = 2;
  m2[1][1] = 2;
  m3 = m1 * m2;
  EXPECT_EQ(m3[0][0], 4);
  EXPECT_EQ(m3[1][0], 4);
}

TEST(TSquareDynamicMatrix, can_multiply_matrix_by_vector)
{
  TSquareDynamicMatrix<int> m1(2);
  TDynamicVector<int> v(2), vres;
  m1[0][0] = 1;
  m1[0][1] = 3;
  m1[1][0] = 2;
  m1[1][1] = 4;
  v[0] = 1;
  v[1] = 2;
  vres = m1 * v;
  EXPECT_EQ(vres[0], 7);
  EXPECT_EQ(vres[1], 10);
}

TEST(TSquareDynamicMatrix, cant_multiply_matrix_by_vector_with_not_equal)
{
  TSquareDynamicMatrix<int> m1(2);
  TDynamicVector<int> v(3);
  ASSERT_ANY_THROW(m1 * v);
}

TEST(TSquareDynamicMatrix, can_multiply_matrix_by_scalar)
{
  TSquareDynamicMatrix<int> mat(2);
  mat[0][0] = 2;
  mat[1][0] = 3;
  mat[1][1] = 5;
  TSquareDynamicMatrix<int> res = mat * 2;
  EXPECT_EQ(res[0][0], 4);
  EXPECT_EQ(res[1][0], 6);
  EXPECT_EQ(res[1][1], 10);
}