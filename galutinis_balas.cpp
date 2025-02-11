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

const int CMax = 5;

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

int main()
{
    int n;
    Studentas A[CMax];
    Skaityti(n, A);
    string pasirinkimas;
    cout << "Vidurskis ar mediana? (v/m)" << endl;
    cin >> pasirinkimas;
    if (pasirinkimas == "v")
    {
        cout << "Vardas     Pavardė        Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << setprecision(2) << SkaiciuotiV(A[i]) << endl;
        }
    }
    else if (pasirinkimas == "m")
    {
        cout << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << setprecision(2) << SkaiciuotiM(A[i]) << endl;
        }
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

float SkaiciuotiV(Studentas A)
{
    int s = 0;
    for (int i = 0; i < CMax; i++)
    {
        s += A.nd[i];
    }
    float galutinis = 0.4 * (1.0 * s / CMax) + 0.6 * A.egz;
    return galutinis;
}

float SkaiciuotiM(Studentas A)
{
    sort(A.nd.begin(), A.nd.end());

    if (A.nd.size() % 2 == 0)
    {
        float paz = 1.0 * (A.nd[A.nd.size() / 2 - 1] + A.nd[A.nd.size() / 2]);
        return paz;
    }
    else
    {
        return A.nd[A.nd.size() / 2];
    }
}