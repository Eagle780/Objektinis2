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

using std::accumulate;
using std::cin;
using std::cout;
using std::exception;
using std::fixed;
using std::getline;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::istringstream;
using std::left;
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
void skaitytiFaila(string failas, vector<Studentas> &A);
void rasytiIFaila(string pav, vector<Studentas> &v);
bool generuotiFaila(string &failas, int ndDydis, int &dydis);
double rusiuotiStudentus(vector<Studentas> &A, vector<Studentas> &v, vector<Studentas> &g);
void testuotiKurima(string &failas, int ndDydis, int &dydis);

#endif