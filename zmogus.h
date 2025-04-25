#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using std::cout;
using std::istream;
using std::move;
using std::ostream;
using std::string;

class Studentas
{
private:
    string vardas;
    string pavarde;

public:
    Studentas() = default;
    Studentas(string v, string p)
    {
        vardas = v;
        pavarde = p;
    };
    Studentas(const Studentas &st)
    {
        cout << "Zmogaus kopijavimo konstruktorius\n";
        vardas = st.vardas;
        pavarde = st.pavarde;
    }
    Studentas &operator=(const Studentas &st)
    {
        cout << "Zmogaus kopijavimo operacija\n";
        if (this == &st)
            return *this;

        vardas = st.vardas;
        pavarde = st.pavarde;

        return *this;
    }
    Studentas(Studentas &&st) noexcept
    {
        cout << "Zmogaus perkelimo konstruktorius\n";
        vardas = move(st.vardas);
        pavarde = move(st.pavarde);
    }
    Studentas &operator=(Studentas &&st) noexcept
    {
        cout << "Zmogaus perkelimo operacija\n";
        if (this == &st)
            return *this;

        vardas = move(st.vardas);
        pavarde = move(st.pavarde);

        return *this;
    }
    friend ostream &operator<<(ostream &os, const Studentas &st)
    {
        os << st.vardas << " " << st.pavarde << "\n";
        return os;
    }
    friend istream &operator>>(istream &is, Studentas &st)
    {
        is >> st.vardas >> st.pavarde;

        return is;
    }
    void setVarPav(string v, string p)
    {
        vardas = v;
        pavarde = p;
    }
    // void setPaz(vector<int> n, int e) {}
    void setGal(int g) {}
    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }
    inline int getEgz() const {}
    // inline vector<int> getNd() const {}
    inline int getGal() const {}
    float SkaiciuotiV() const
    {
    }
    float SkaiciuotiM() const
    {
    }
    ~Studentas()
    {
        cout << "Zmogaus destruktorius\n";
        vardas.clear();
        pavarde.clear();
    }
};

#endif