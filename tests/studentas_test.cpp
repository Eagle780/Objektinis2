#define TESTAI1
#include "../header.h"
#include "gtest/gtest.h"

TEST(StudentasTest, KopijavimoTest)
{
    Studentas temp1("vardas", "pavarde", {10, 8, 10}, 10);
    Studentas temp2 = temp1;

    EXPECT_EQ(temp1.getVardas(), temp2.getVardas());
    EXPECT_EQ(temp1.getPavarde(), temp2.getPavarde());
    EXPECT_EQ(temp1.getNd(), temp2.getNd());
    EXPECT_EQ(temp1.getEgz(), temp2.getEgz());
}

TEST(StudentasTest, PerkelimoTest)
{
    string vardas = "vardas";
    string pavarde = "pavarde";
    Studentas temp1(vardas, pavarde, {10, 8, 10}, 10);
    Studentas temp2 = move(temp1);

    EXPECT_EQ(temp2.getVardas(), vardas);
    EXPECT_EQ(temp2.getPavarde(), pavarde);
}

TEST(StudentasTest, KopijavimoOpTest)
{
    Studentas temp1("vardas", "pavarde", {10, 8, 10}, 10);
    Studentas temp2;
    temp2 = temp1;

    EXPECT_EQ(temp1.getVardas(), temp2.getVardas());
    EXPECT_EQ(temp1.getPavarde(), temp2.getPavarde());
    EXPECT_EQ(temp1.getNd(), temp2.getNd());
    EXPECT_EQ(temp1.getEgz(), temp2.getEgz());
}

TEST(StudentasTest, PerkelimoOpTest)
{
    string vardas = "vardas";
    string pavarde = "pavarde";
    Studentas temp1(vardas, pavarde, {10, 8, 10}, 10);
    Studentas temp2;
    temp2 = move(temp1);

    EXPECT_EQ(temp2.getVardas(), vardas);
    EXPECT_EQ(temp2.getPavarde(), pavarde);
}

TEST(StudentasTest, DestruktoriausTest)
{
    Studentas *temp = new Studentas("vardas", "pavarde", {10, 8, 10}, 10);
    EXPECT_NO_THROW(delete temp);
}

TEST(StudentasTest, IvedimoTest)
{
    std::stringstream ss("vardas pavarde 10 8 10 10");
    vector<int> nd = {8, 10, 10};
    Studentas temp;
    ss >> temp;

    EXPECT_EQ(temp.getVardas(), "vardas");
    EXPECT_EQ(temp.getPavarde(), "pavarde");
    EXPECT_EQ(temp.getNd(), nd);
    EXPECT_EQ(temp.getEgz(), 10);
}

TEST(StudentasTest, IsvedimoTest)
{
    Studentas temp("vardas", "pavarde", {10, 8, 10}, 10);
    std::stringstream out;
    out << temp;
    string result = out.str();

    EXPECT_NE(result.find("vardas"), string::npos);
    EXPECT_NE(result.find("pavarde"), string::npos);
}