#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

/*
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
*/

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