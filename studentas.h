/**
 * @file studentas.h
 * @author Eglė
 * @brief  Studento klasė
 * @version 0.1
 * @date 2025-05-07
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef STUDENT_H
#define STUDENT_H

#include "zmogus.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>

using std::cout;
using std::istream;
using std::istringstream;
using std::move;
using std::ostream;
using std::sort;
using std::string;
using std::vector;

inline bool TEST_MODE = false;

class Studentas : public Zmogus
{
private:
    string vardas;
    string pavarde;
    vector<int> nd;
    int egz;
    float galutinisV;
    float galutinisM;

public:
    /**
     * @brief Tuščias studento konstruktorius
     *
     */
    Studentas() : egz(0) {}
    /**
     * @brief Pilnas studento konstruktorius
     *
     * @param v Vardas
     * @param p Pavardė
     * @param n Namų darbų pažymiai (vektorius)
     * @param e Egzamino pažymys
     */
    Studentas(string v, string p, vector<int> n, int e)
    {
        vardas = v;
        pavarde = p;
        nd = n;
        egz = e;
        galutinisV = SkaiciuotiV();
        galutinisM = SkaiciuotiM();
    };
    /**
     * @brief Kopijavimo konstruktorius
     *
     * @param st Studentas, kurio duomenis norima kopijuoti
     */
    Studentas(const Studentas &st)
    {
        if (TEST_MODE)
            cout << "Studento kopijavimo konstruktorius\n";
        vardas = st.vardas;
        pavarde = st.pavarde;
        nd.resize(st.nd.size());
        copy(st.nd.begin(), st.nd.end(), nd.begin());
        egz = st.egz;
        galutinisV = st.galutinisV;
        galutinisM = st.galutinisM;
    }
    /**
     * @brief Kopijavimo operacija
     *
     * @param st Studentas, kurio duomenis norima kopijuoti
     * @return Studentas, į kurį buvo nukopijuoti duomenys
     */
    Studentas &operator=(const Studentas &st)
    {
        if (TEST_MODE)
            cout << "Studento kopijavimo operacija\n";
        if (this == &st)
            return *this;

        if (!nd.empty())
            nd.clear();

        vardas = st.vardas;
        pavarde = st.pavarde;
        nd.resize(st.nd.size());
        copy(st.nd.begin(), st.nd.end(), nd.begin());
        egz = st.egz;
        galutinisV = st.galutinisV;
        galutinisM = st.galutinisM;

        return *this;
    }
    /**
     * @brief Studento perkelimo konstruktorius
     *
     * @param st Studentas, kurio duomenis norima perkelti
     */
    Studentas(Studentas &&st) noexcept
    {
        if (TEST_MODE)
            cout << "Studento perkelimo konstruktorius\n";
        vardas = move(st.vardas);
        pavarde = move(st.pavarde);
        nd = move(st.nd);
        egz = st.egz;
        galutinisV = st.galutinisV;
        galutinisM = st.galutinisM;
        st.clear();
    }
    /**
     * @brief Studento perkelimo operacija
     *
     * @param st Studentas, kurio duomenis norima perkelti
     * @return Studentas, į kurį buvo perkelti duomenys
     */
    Studentas &operator=(Studentas &&st) noexcept
    {
        if (TEST_MODE)
            cout << "Studento perkelimo operacija\n";
        if (this == &st)
            return *this;

        vardas = move(st.vardas);
        pavarde = move(st.pavarde);
        nd = move(st.nd);
        egz = st.egz;
        galutinisV = st.galutinisV;
        galutinisM = st.galutinisM;
        st.clear();

        return *this;
    }
    /**
     * @brief Studento išvedimo operacija
     *
     * @param os Būdas, kuriuo išvedama
     * @param st Išvedamas studentas
     * @return ostream&
     */
    friend ostream &operator<<(ostream &os, const Studentas &st)
    {
        os << st.vardas << " " << st.pavarde << " " << st.galutinisV << " " << st.galutinisM << "\n";
        return os;
    }
    /**
     * @brief Studento įvedimo operacija
     *
     * @param is Būdas, kuriuo įvedama
     * @param st Įvedamas studentas
     * @return istream&
     */
    friend istream &operator>>(istream &is, Studentas &st)
    {
        is >> st.vardas >> st.pavarde;
        st.nd.clear();

        string eilute;
        getline(is, eilute);
        istringstream iss(eilute);

        vector<int> visiPazymiai;
        int paz;

        while (iss >> paz)
        {
            visiPazymiai.push_back(paz);
        }

        st.egz = visiPazymiai.back();
        visiPazymiai.pop_back();
        st.nd = visiPazymiai;
        st.galutinisV = st.SkaiciuotiV();
        st.galutinisM = st.SkaiciuotiM();

        return is;
    }
    /**
     * @brief Studento vardo ir pavardės set'eris
     *
     * @param v Vardas
     * @param p Pavardė
     */
    void setVarPav(string v, string p)
    {
        vardas = v;
        pavarde = p;
    }
    /**
     * @brief Studento namų darbų ir egzamino pažymių set'eris
     *
     * @param n namų darbų pažymių vektorius
     * @param e egzamino pažymys
     */
    void setPaz(vector<int> n, int e)
    {
        nd = n;
        egz = e;
        galutinisV = SkaiciuotiV();
        galutinisM = SkaiciuotiM();
    }
    inline string getVardas() const override { return vardas; }
    inline string getPavarde() const override { return pavarde; }
    inline int getEgz() const { return egz; }
    inline vector<int> getNd() const { return nd; }
    inline int getGalV() const { return galutinisV; }
    inline int getGalM() const { return galutinisM; }
    /**
     * @brief Skaičiuojamas studento galutinis balas pagal vidurkį
     *
     * @return Grąžinama suskaičiuota galutinio balo reikšmė, kuri išsaugoma "galutinisV"
     */
    float SkaiciuotiV()
    {
        int s = 0;
        for (int i = 0; i < nd.size(); i++)
        {
            s += nd[i];
        }
        float galutinis = 0.4 * (1.0 * s / nd.size()) + 0.6 * egz;
        return galutinis;
    }
    /**
     * @brief Skaičiuojamas studento galutinis balas pagal medianą
     *
     * @return Grąžinama suskaičiuota galutinio balo reikšmė, kuri išsaugoma "galutinisM"
     */
    float SkaiciuotiM()
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
    /**
     * @brief funkcija, kuri iškviečiama iškvietus destruktorių
     *
     */
    void clear()
    {
        if (TEST_MODE)
            cout << "Studento destruktorius\n";
        vardas.clear();
        pavarde.clear();
        nd.clear();
        egz = 0;
        galutinisV = 0;
        galutinisM = 0;
    }
    ~Studentas() { clear(); }
};

#endif