#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <limits>
#include <chrono>
#include <numeric>

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
using std::time;
using std::vector;

class Timer
{
private:
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
    std::chrono::time_point<hrClock> start;

public:
    Timer() : start{hrClock::now()} {}
    void reset()
    {
        start = hrClock::now();
    }
    double elapsed() const
    {
        return durationDouble(hrClock::now() - start).count();
    }
};

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

Studentas generuotiPazymius(Studentas temp);
Studentas generuotiVardus(Studentas temp);
Studentas irasytiPazymius(Studentas temp);
Studentas irasytiVarda(Studentas temp);

StudentasC *generuotiPazymius(StudentasC *naujiStudentai, int m, int temp[100]);
StudentasC *generuotiVardus(StudentasC *naujiStudentai, int m);
StudentasC *irasytiPazymius(StudentasC *naujiStudentai, int m, int temp[100]);
StudentasC *irasytiVarda(StudentasC *naujiStudentai, int m);

float SkaiciuotiV(Studentas A);
float SkaiciuotiM(Studentas A);

float SkaiciuotiV(StudentasC A, int m);
float SkaiciuotiM(StudentasC A, int m);

void skaitytiFaila();
void rasytiIFaila();
void spausdinti();