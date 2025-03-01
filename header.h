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
#include "studentas.h"
#include "timeris.h"

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::getline;
using std::ifstream;
using std::ios;
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
using std::vector;

Studentas generuotiPazymius(Studentas temp);
Studentas generuotiVardus(Studentas temp);
Studentas irasytiPazymius(Studentas temp);
Studentas irasytiVarda(Studentas temp);

float SkaiciuotiV(Studentas A);
float SkaiciuotiM(Studentas A);

void skaitytiFaila();
void rasytiIFaila();
void spausdinti();
void issaugotiLaika(double laikas);
void vidutinisLaikas();