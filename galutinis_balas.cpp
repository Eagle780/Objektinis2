#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

/*
using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;
*/

const int CMax = 5;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
};

void Skaityti(int &n, Studentas A[]);
float Skaiciuoti(Studentas A);

int main()
{
    int n;
    Studentas A[CMax];
    Skaityti(n, A);
    cout << "Vardas     Pavardė      Galutinis (Vid. )" << endl;
    cout << "--------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(12) << A[i].vardas << setw(14) << A[i].pavarde;
        cout << Skaiciuoti(A[i]) << endl;
    }
    return 0;
}

void Skaityti(int &n, Studentas A[])
{
    ifstream fd("U1.txt");
    fd >> n;
    for (int i = 0; i < n; i++)
    {
        fd >> A[i].vardas >> A[i].pavarde;
        for (int j = 0; j < CMax; j++)
        {
            int a;
            fd >> a;
            A[i].nd.push_back(a);
        }
        fd >> A[i].egz;
    }
    fd.close();
}

float Skaiciuoti(Studentas A)
{
    int s = 0;
    for (int i = 0; i < CMax; i++)
    {
        s += A.nd[i];
    }
    float galutinis = 0.4 * (1.0 * s / CMax) + 0.6 * A.egz;
    return galutinis;
}
