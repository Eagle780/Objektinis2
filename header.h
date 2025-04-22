#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <numeric>
#include <chrono>
#include <filesystem>
#include <list>
#include <deque>

using std::accumulate;
using std::cin;
using std::cout;
using std::deque;
using std::exception;
using std::fixed;
using std::getline;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::istringstream;
using std::left;
using std::list;
using std::numeric_limits;
using std::ofstream;
using std::partition;
using std::rand;
using std::setprecision;
using std::setw;
using std::sort;
using std::srand;
using std::streamsize;
using std::string;
using std::time;
using std::to_string;
using std::vector;

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;

public:
    Studentas() : egz(0) {}
    Studentas(string v, string p, vector<int> n, int e)
    {
        vardas = v;
        pavarde = p;
        nd = n;
        egz = e;
    };
    void setVarPav(string v, string p)
    {
        vardas = v;
        pavarde = p;
    }
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline int getEgz() const { return egz; }
    inline vector<int> getNd() const { return nd; }
    float SkaiciuotiV() const
    {
        int s = 0;
        for (int i = 0; i < nd.size(); i++)
        {
            s += nd[i];
        }
        float galutinis = 0.4 * (1.0 * s / nd.size()) + 0.6 * egz;
        return galutinis;
    }
    float SkaiciuotiM() const
    {
        float paz;
        sort(nd.begin(), nd.end());

        if (nd.size() % 2 == 0)
        {
            paz = 1.0 * (nd[nd.size() / 2 - 1] + nd[nd.size() / 2]) / 2;
        }
        else
        {
            paz = nd[nd.size() / 2];
        }

        float galutinis = 0.4 * paz + 0.6 * egz;
        return galutinis;
    }
};

void cinEx();
Studentas generuotiPazymius(Studentas temp);
Studentas generuotiVardus(Studentas temp);
Studentas irasytiPazymius(Studentas temp);
Studentas irasytiVarda(Studentas temp);

template <typename T>
void rasytiIFaila(string pav, T &v, string pas)
{
    if (pas == "v")
    {
        sort(v.begin(), v.end(), [](const Studentas &a, const Studentas &b)
             { return SkaiciuotiV(a) > SkaiciuotiV(b); });
    }
    else if (pas == "m")
    {
        sort(v.begin(), v.end(), [](const Studentas &a, const Studentas &b)
             { return SkaiciuotiM(a) > SkaiciuotiM(b); });
    }
    ofstream fr(pav);
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (const Studentas &i : v)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
    }
}

void rasytiIFaila(string pav, list<Studentas> &v, string pas);

template <typename T>
void skaitytiFaila(string failas, T &A)
{

    vector<int> nd;
    try
    {
        ifstream fd(failas);

        if (!fd)
        {
            throw std::ios_base::failure("Nepavyko atidaryti failo");
        }

        fd.ignore(numeric_limits<streamsize>::max(), '\n');

        string vardas, pavarde;
        while (fd >> vardas >> pavarde)
        {
            int egz = 0;
            nd.clear();
            Studentas temp;
            temp.vardas = vardas;
            temp.pavarde = pavarde;

            string eilute;
            getline(fd, eilute);
            istringstream iss(eilute);

            vector<int> visiPazymiai;
            int pazimys;
            while (iss >> pazimys)
            {
                visiPazymiai.push_back(pazimys);
            }

            egz = visiPazymiai.back();
            visiPazymiai.pop_back();
            nd = visiPazymiai;

            Studentas temp(vardas, pavarde, nd, egz);
            A.push_back(temp);
        }
        fd.close();
    }
    catch (ios_base::failure &e)
    {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
}

bool generuotiFaila(string &failas, int ndDydis, int &dydis);

template <typename T>
string rusiuotiStudentus(T &A, T &v, T &g, int var)
{
    string pas = "";

    if (var == 3)
    {
        pas = "v";
    }
    else if (var == 4)
    {
        pas = "m";
    }

    while (pas != "v" && pas != "m")
    {
        cout << "Studentus rusiuoti pagal vidurki ar mediana? (v/m)\n";
        cin >> pas;
    }

    if (pas == "v")
    {
        for (Studentas st : A)
        {
            st.galutinis = SkaiciuotiV(st);
            if (st.galutinis < 5.0)
                v.push_back(st);
            else
                g.push_back(st);
        }
    }
    else
    {
        for (Studentas st : A)
        {
            st.galutinis = SkaiciuotiM(st);
            if (st.galutinis < 5.0)
                v.push_back(st);
            else
                g.push_back(st);
        }
    }
    return pas;
}

template <typename T>
string rusiuotiStudentus(T &A, T &v, int var)
{
    string pas = "";

    if (var == 3)
    {
        pas = "v";
    }
    else if (var == 4)
    {
        pas = "m";
    }

    while (pas != "v" && pas != "m")
    {
        cout << "Studentus rusiuoti pagal vidurki ar mediana? (v/m)\n";
        cin >> pas;
    }

    if (pas == "v")
    {
        for (int i = A.size() - 1; i >= 0; --i)
        {
            if (SkaiciuotiV(A[i]) < 5.0)
            {
                v.push_back(A[i]);
                A.erase(A.begin() + i);
            }
        }
    }
    else
    {
        for (int i = A.size() - 1; i >= 0; --i)
        {
            if (SkaiciuotiM(A[i]) < 5.0)
            {
                v.push_back(A[i]);
                A.erase(A.begin() + i);
            }
        }
    }
    return pas;
}

string rusiuotiStudentus(list<Studentas> &A, list<Studentas> &v, int var);

template <typename T>
string rusiuotiStudentus3(T &A, T &v, int var)
{
    string pas = "";

    if (var == 3)
    {
        pas = "v";
    }
    else if (var == 4)
    {
        pas = "m";
    }

    while (pas != "v" && pas != "m")
    {
        cout << "Studentus rusiuoti pagal vidurki ar mediana? (v/m)\n";
        cin >> pas;
    }

    if (pas == "v")
    {
        A.erase(remove_if(A.begin(), A.end(), [&](const Studentas &st)
                          {
                       if (SkaiciuotiV(st) < 5.0)
                       {
                           v.push_back(st);
                           return true;
                       }
                       return false; }),
                A.end());
    }
    else
    {
        A.erase(remove_if(A.begin(), A.end(), [&](const Studentas &st)
                          {
                       if (SkaiciuotiM(st) < 5.0)
                       {
                           v.push_back(st);
                           return true;
                       }
                       return false; }),
                A.end());
    }
    return pas;
}

string rusiuotiStudentus3(list<Studentas> &A, list<Studentas> &v, int var);

void testuotiKurima(string &failas, int ndDydis, int &dydis);

#endif