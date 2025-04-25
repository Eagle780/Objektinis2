#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::move;
using std::sort;
using std::string;
using std::vector;

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    int galutinis;

public:
    Studentas() : egz(0) {}
    Studentas(string v, string p, vector<int> n, int e)
    {
        vardas = v;
        pavarde = p;
        nd = n;
        egz = e;
    };
    Studentas(const Studentas &st)
    {
        cout << "Studento kopijavimo konstruktorius\n";
        vardas = st.vardas;
        pavarde = st.pavarde;
        nd = st.nd;
        egz = st.egz;
        galutinis = st.galutinis;
    }
    Studentas &operator=(const Studentas &st)
    {
        cout << "Studento kopijavimo operacija\n";
        if (this == &st)
            return *this;

        if (!nd.empty())
            nd.clear();

        vardas = st.vardas;
        pavarde = st.pavarde;
        nd = st.nd;
        egz = st.egz;
        galutinis = st.galutinis;

        return *this;
    }
    Studentas(Studentas &&st) noexcept
    {
        vardas = move(st.vardas);
        pavarde = move(st.pavarde);
        nd = move(st.nd);
        egz = st.egz;
        galutinis = st.galutinis;
    }
    Studentas &operator=(Studentas &&st) noexcept
    {
        vardas = move(st.vardas);
        pavarde = move(st.pavarde);
        nd = move(st.nd);
        egz = st.egz;
        galutinis = st.galutinis;

        return *this;
    }
    void setVarPav(string v, string p)
    {
        vardas = v;
        pavarde = p;
    }
    void setPaz(vector<int> n, int e)
    {
        nd = n;
        egz = e;
    }
    void setGal(int g)
    {
        galutinis = g;
    }
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline int getEgz() const { return egz; }
    inline vector<int> getNd() const { return nd; }
    inline int getGal() const { return galutinis; }
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
        vector<int> nd2 = nd;
        float paz;
        sort(nd2.begin(), nd2.end());

        if (nd2.size() % 2 == 0)
        {
            paz = 1.0 * (nd2[nd2.size() / 2 - 1] + nd2[nd2.size() / 2]) / 2;
        }
        else
        {
            paz = nd2[nd2.size() / 2];
        }

        float galutinis = 0.4 * paz + 0.6 * egz;
        return galutinis;
    }
    ~Studentas()
    {
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0;
        galutinis = 0;
    }
};

#endif