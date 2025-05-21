#pragma once

#include "../header.h"
#include "gtest/gtest.h"

TEST(VektoriausTest, PushBackTest)
{
    Vector<Studentas> v{};
    Studentas temp1("vardas", "pavarde", {10, 8, 10}, 10);
    v.Push_back(temp1);
    Vector<int> nd = {8, 10, 10};

    EXPECT_EQ(v[0].getVardas(), "vardas");
    EXPECT_EQ(v[0].getPavarde(), "pavarde");
    EXPECT_EQ(v[0].getNd(), nd);
    EXPECT_EQ(v[0].getEgz(), 10);
}