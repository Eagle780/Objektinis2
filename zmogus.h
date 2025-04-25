#ifndef ZMOGUS_H
#define ZMOGUS_H

#include <string>

using std::string;

class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    Zmogus() {}
    Zmogus(string v, string p)
    {
        vardas = v;
        pavarde = p;
    };
    void setVarPav(string v, string p)
    {
        vardas = v;
        pavarde = p;
    }
    virtual string getVardas() const = 0;
    virtual string getPavarde() const = 0;
    virtual ~Zmogus() {}
};

#endif