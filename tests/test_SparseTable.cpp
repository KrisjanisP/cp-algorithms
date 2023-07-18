#include <gtest/gtest.h>
#include "../src/sparse-table.hpp"

TEST(SparseTable, Basic) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  SparseTable st(v);
  EXPECT_EQ(st.query(0, 4), 1);
  EXPECT_EQ(st.query(0, 3), 1);
  EXPECT_EQ(st.query(0, 2), 1);
  EXPECT_EQ(st.query(0, 1), 1);
  EXPECT_EQ(st.query(0, 0), 1);
  EXPECT_EQ(st.query(1, 4), 2);
  EXPECT_EQ(st.query(1, 3), 2);
  EXPECT_EQ(st.query(1, 2), 2);
  EXPECT_EQ(st.query(1, 1), 2);
  EXPECT_EQ(st.query(2, 4), 3);
  EXPECT_EQ(st.query(2, 3), 3);
  EXPECT_EQ(st.query(2, 2), 3);
  EXPECT_EQ(st.query(3, 4), 4);
  EXPECT_EQ(st.query(3, 3), 4);
  EXPECT_EQ(st.query(4, 4), 5);
}
