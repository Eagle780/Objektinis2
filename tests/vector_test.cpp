#define TESTAI2
#include "../header.h"
#include "gtest/gtest.h"

TEST(VektoriausTest, PushBackTest)
{
    Vector<int> v;
    v.push_back(5);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 5);
}

TEST(VektoriausTest, PopBackTest)
{
    Vector<int> v{1, 2, 3};
    v.pop_back();
    EXPECT_EQ(v.size(), 2);
}

TEST(VektoriausTest, ReserveIrShrinkTest)
{
    Vector<int> v{1, 2, 3};
    v.reserve(5);
    EXPECT_EQ(v.capacity(), 5);
    EXPECT_FALSE(v.size() == v.capacity());
    v.shrink_to_fit();
    EXPECT_EQ(v.size(), v.capacity());
}

TEST(VektoriausTest, EmplaceTest)
{
    Vector<int> v;
    v.emplace_back(1);
    v.emplace_back(3);
    v.emplace(1, 2);

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(VektoriausTest, ResizeTest)
{
    Vector<int> v;
    v.push_back(1);
    v.resize(5);

    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v[0], 1);
    for (int i = 1; i < 5; ++i)
    {
        EXPECT_EQ(v[i], 0);
    }
}

TEST(VektoriausTest, LyguTest)
{
    Vector<int> a, b;
    a.push_back(1);
    a.push_back(2);

    b.push_back(1);
    b.push_back(2);

    EXPECT_TRUE(a == b);
    b.push_back(3);
    EXPECT_FALSE(a == b);
}

TEST(VektoriausTest, NelygybiuTest)
{
    Vector<int> a{1, 2, 3}, b{1, 2, 4}, c{1, 2, 3, 4};

    EXPECT_TRUE(a <= b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a < c);
    EXPECT_FALSE(a >= c);
    EXPECT_TRUE(b > c);
}

TEST(VektoriausTest, AtTest)
{
    Vector<int> v;
    v.push_back(1);

    EXPECT_NO_THROW(v.at(0));
    EXPECT_THROW(v.at(1), std::out_of_range);
}

TEST(VektoriausTest, EraseTest)
{
    Vector<int> v{1, 2, 3};

    EXPECT_EQ(v.size(), 3);
    v.erase(v.begin() + 1);
    EXPECT_EQ(v.size(), 2);
    EXPECT_FALSE(v[1] == 2);
}

TEST(VektoriausTest, ClearTest)
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.clear();
    EXPECT_EQ(v.size(), 0);
    EXPECT_TRUE(v.empty());
}

TEST(VektoriausTest, AssingTest)
{
    Vector<int> v;
    v.push_back(1);
    v.assign(5, 'b');

    EXPECT_EQ(v.size(), 5);
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(v[i], 'b');
    }
}

TEST(VektoriausTest, KopijavimoTest)
{
    Vector<int> temp1;
    temp1.push_back(42);

    Vector<int> temp2(temp1);
    EXPECT_EQ(temp2.size(), 1);
    EXPECT_EQ(temp2[0], 42);
}

TEST(VektoriausTest, KopijavimoOpTest)
{
    Vector<int> temp1;
    temp1.push_back(42);

    Vector<int> temp2;
    temp2 = temp1;
    EXPECT_EQ(temp2.size(), 1);
    EXPECT_EQ(temp2[0], 42);
}

TEST(VektoriausTest, PerkelimoTest)
{
    Vector<int> temp1;
    temp1.push_back(42);

    Vector<int> temp2 = move(temp1);
    EXPECT_EQ(temp2.size(), 1);
    EXPECT_EQ(temp2[0], 42);
}

TEST(VektoriausTest, PerkelimoOpTest)
{
    Vector<int> temp1;
    temp1.push_back(42);

    Vector<int> temp2;
    temp2 = move(temp1);
    EXPECT_EQ(temp2.size(), 1);
    EXPECT_EQ(temp2[0], 42);
}