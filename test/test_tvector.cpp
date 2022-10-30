#include "gtest.h"
#include "TTriangleMatrix.h"

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
  TDynamicVector<int> v1(4);
  v1[2] = 2;
  TDynamicVector<int> v2 = v1;
  EXPECT_NE(&v1, &v2);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
  TDynamicVector<int> v1(2), v2(4);
  v2 = v1;
  EXPECT_EQ(v1.size(), v2.size());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
  TDynamicVector<int> v1(2), v2(2);
  v1 = v2;
  EXPECT_TRUE(v1 == v2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
  TDynamicVector<int> v1(2);
  v1[0] = 2;
  v1[1] = 2;
  EXPECT_TRUE(v1 == v1);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
  TDynamicVector<int> v1(2), v2(4);
  EXPECT_TRUE(v1 != v2);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
  TDynamicVector<int> v1(2), v2(4);
  ASSERT_ANY_THROW(v1 * v2);
}

TEST(TDynamicVector, can_resize_vector)
{
  TDynamicVector<int> v(5);
  v.Resize(8);
  EXPECT_EQ(8, v.size());
}

TEST(TDynamicVector, cant_resize_vector_to_negative_size)
{
  TDynamicVector<int> v1(2);
  ASSERT_ANY_THROW(v1.Resize(-2));
}

TEST(TDynamicVector, cant_found_element_with_negative_index)
{
  TDynamicVector<int> v1(2);
  ASSERT_ANY_THROW(v1[-1]);
}

TEST(TDynamicVector, can_found_element_with_positive_index)
{
  TDynamicVector<int> v1(2);
  ASSERT_NO_THROW(v1[1]);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
  TDynamicVector<int> v1(2);
  int b = 4;
  ASSERT_NO_THROW(v1 + b);
}

TEST(TDynamicVector, can_substract_scalar_from_vector)
{
  TDynamicVector<int> v1(2);
  double b = 4.0;
  ASSERT_NO_THROW(v1 - b);
}

TEST(TDynamicVector, can_multiply_vector_by_scalar)
{
  TDynamicVector<int> v1(2);
  v1[0] = 2;
  v1[1] = 2;
  double b = 4.0;
  TDynamicVector<int> v2(2);
  v2[0] = 8;
  v2[1] = 8;
  ASSERT_NO_THROW(v1 * b);
  EXPECT_TRUE(v2 == (v1 * b));
}

TEST(TDynamicVector, can_sum_vectors)
{
  TDynamicVector<int> v1(2);
  v1[0] = 2;
  v1[1] = 2;
  TDynamicVector<int> v2(2);
  v2[0] = 8;
  v2[1] = 8;
  ASSERT_NO_THROW(v1 + v2);
}

TEST(TDynamicVector, can_substact_vectors)
{
  TDynamicVector<int> v1(2);
  v1[0] = 2;
  v1[1] = 2;
  TDynamicVector<int> v2(2);
  v2[0] = 8;
  v2[1] = 8;
  ASSERT_NO_THROW(v1 - v2);
}

TEST(TDynamicVector, can_equate_vector)
{
  TDynamicVector<int> v1(2);
  v1[0] = 2;
  v1[1] = 2;
  TDynamicVector<int> v2(2);
  v2[0] = 8;
  v2[1] = 8;
  v2 = v1;
  EXPECT_TRUE(v2 == v1);
  EXPECT_EQ(v2[0], 2);
}
