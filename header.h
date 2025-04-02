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

struct Studentas
{
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float galutinis;
};

void cinEx();
float SkaiciuotiV(Studentas A);
float SkaiciuotiM(Studentas A);
Studentas generuotiPazymius(Studentas temp);
Studentas generuotiVardus(Studentas temp);
Studentas irasytiPazymius(Studentas temp);
Studentas irasytiVarda(Studentas temp);

template <typename T>
void rasytiIFaila(string pav, T &v)
{
    ofstream fr(pav);
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (const Studentas &i : v)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
    }
}

template <typename T>
void skaitytiFaila(string failas, T &A)
{
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

            temp.egz = visiPazymiai.back();
            visiPazymiai.pop_back();
            temp.nd = visiPazymiai;

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

double rusiuotiStudentus(vector<Studentas> &A, vector<Studentas> &v, vector<Studentas> &g, int var);
double rusiuotiStudentus(deque<Studentas> &A, deque<Studentas> &v, deque<Studentas> &g, int var);
double rusiuotiStudentus(list<Studentas> &A, list<Studentas> &v, list<Studentas> &g, int var);

void testuotiKurima(string &failas, int ndDydis, int &dydis);

#endif