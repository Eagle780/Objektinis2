#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::ifstream;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

void Skaityti(int &n, Studentas A[]);
float SkaiciuotiV(Studentas A);
float SkaiciuotiM(Studentas A);