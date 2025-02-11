#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::vector;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

struct StudentasC
{
    string vardas;
    string pavarde;
    int *nd;
    int ndSk;
    int egz;
};

float SkaiciuotiV(Studentas A);
float SkaiciuotiM(Studentas A);

float SkaiciuotiV(StudentasC A, int m);
float SkaiciuotiM(StudentasC A, int m);