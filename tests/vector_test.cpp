#define TESTAI2
#include "../header.h"
#include "gtest/gtest.h"

TEST(VektoriausTest, PushBackTest)
{
    Vector<int> v;
    v.Push_back(5);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v[0], 5);
}

TEST(VektoriausTest, PopBackTest)
{
    Vector<int> v{1, 2, 3};
    v.Pop_back();
    EXPECT_EQ(v.Size(), 2);
}

TEST(VektoriausTest, EmplaceTest)
{
    Vector<int> v;
    v.Emplace_back(1);
    v.Emplace_back(3);
    v.Emplace(1, 2);

    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VektoriausTest, ResizeTest)
{
    Vector<int> v;
    v.Push_back(1);
    v.Resize(5);

    EXPECT_EQ(v.Size(), 5);
    EXPECT_EQ(v[0], 1);
    for (int i = 1; i < 5; ++i)
    {
        EXPECT_EQ(v[i], 0);
    }
}

TEST(VektoriausTest, LyguTest)
{
    Vector<int> a, b;
    a.Push_back(1);
    a.Push_back(2);

    b.Push_back(1);
    b.Push_back(2);

    EXPECT_TRUE(a == b);
    b.Push_back(3);
    EXPECT_FALSE(a == b);
}

TEST(VektoriausTest, AtTest)
{
    Vector<int> v;
    v.Push_back(1);

    EXPECT_NO_THROW(v.At(0));
    EXPECT_THROW(v.At(1), std::out_of_range);
}

TEST(VektoriausTest, ClearTest)
{
    Vector<int> v;
    v.Push_back(1);
    v.Push_back(2);

    v.Clear();
    EXPECT_EQ(v.Size(), 0);
    EXPECT_TRUE(v.isEmpty());
}

TEST(VektoriausTest, CopyKonstruktoriusTest)
{
    Vector<int> temp1;
    temp1.Push_back(42);

    Vector<int> temp2(temp1);
    EXPECT_EQ(temp2.Size(), 1);
    EXPECT_EQ(temp2[0], 42);
}