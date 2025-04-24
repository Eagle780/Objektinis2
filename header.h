#ifndef HEADER_H
#define HEADER_H

#include "Studentas.h"
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
             { return a.SkaiciuotiV() > b.SkaiciuotiV(); });
    }
    else if (pas == "m")
    {
        sort(v.begin(), v.end(), [](const Studentas &a, const Studentas &b)
             { return a.SkaiciuotiM() > b.SkaiciuotiM(); });
    }
    ofstream fr(pav);
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (const Studentas &i : v)
    {
        fr << left << setw(12) << i.getVardas() << setw(16) << i.getPavarde();
        fr << fixed << setw(17) << setprecision(2) << i.SkaiciuotiV() << i.SkaiciuotiM() << "\n";
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
            st.setGal(st.SkaiciuotiV());
            if (st.getGal() < 5.0)
                v.push_back(st);
            else
                g.push_back(st);
        }
    }
    else
    {
        for (Studentas st : A)
        {
            st.setGal(st.SkaiciuotiM());
            if (st.getGal() < 5.0)
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
            if (A[i].SkaiciuotiV() < 5.0)
            {
                v.push_back(A[i]);
                A.pop_back();
            }
        }
    }
    else
    {
        for (int i = A.size() - 1; i >= 0; --i)
        {
            if (A[i].SkaiciuotiM() < 5.0)
            {
                v.push_back(A[i]);
                A.pop_back();
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
                       if (st.SkaiciuotiV() < 5.0)
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
                       if (st.SkaiciuotiM() < 5.0)
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