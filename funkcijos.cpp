#include "header.h"
#include "timeris.h"

void cinEx()
{
    cin.exceptions(ios::failbit | ios::badbit);
}

Studentas generuotiPazymius(Studentas temp)
{
    Vector<int> nd;
    int n = 0;
    int a = 0;
    while (true)
    {
        cout << "Iveskite pazymiu skaiciu: ";

        try
        {
            cin >> n;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (n == 0)
        {
            cout << "Netinkamas skaicius\n";
            continue;
        }
        break;
    }

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        a = 1 + rand() % 10;
        nd.push_back(a);
    }

    int egz = 1 + rand() % 10;
    temp.setPaz(nd, egz);

    return temp;
}

Studentas generuotiVardus(Studentas temp)
{
    Vector<string> Vardai = {"Jonas", "Antanas", "Petras", "Dovydas", "Tomas"};
    Vector<string> Pavardes = {"Jonaitis", "Petrauskas", "Kazlauskas", "Antanaitis", "Ivanauskas"};

    srand(time(0));

    string vardas = Vardai[rand() % Vardai.Size()];
    string pavarde = Pavardes[rand() % Pavardes.Size()];
    temp.setVarPav(vardas, pavarde);

    return temp;
}

Studentas irasytiPazymius(Studentas temp)
{
    Vector<int> nd;
    int a;
    cout << "Iveskite pazymius (norint baigti pazymiu rasyma, irasykite 0):\n";
    while (true)
    {
        try
        {
            cin >> a;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (a > 0 && a <= 10)
        {
            nd.push_back(a);
        }
        else if (a == 0)
        {
            if (nd.Size() == 0)
                cout << "Iveskite bent viena pazymi\n";
            else
                break;
        }
        else
            cout << "Neteisingas pazymys\n";
    }

    a = 0;
    while (true)
    {
        cout << "Iveskite egzamino pazymi: ";
        try
        {
            cin >> a;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (a <= 10 && a > 0)
        {
            break;
        }
        else
        {
            cout << "Netinkamas skaicius\n";
        }
    }

    temp.setPaz(nd, a);

    return temp;
}

Studentas irasytiVarda(Studentas temp)
{
    string vardas, pavarde;
    cout << "Iveskite varda: ";
    cin >> vardas;
    cout << "Iveskite pavarde: ";
    cin >> pavarde;
    temp.setVarPav(vardas, pavarde);

    return temp;
}

void rasytiIFaila(string pav, list<Studentas> &v, string pas)
{
    if (pas == "v")
    {
        v.sort([](const Studentas &a, const Studentas &b)
               { return a.getGalV() > b.getGalV(); });
    }
    else if (pas == "m")
    {
        v.sort([](const Studentas &a, const Studentas &b)
               { return a.getGalM() > b.getGalM(); });
    }
    ofstream fr(pav);
    if (!fr.is_open())
    {
        std::cerr << "Nepavyko atidaryti failo: " << pav << "\n";
        return;
    }
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (const Studentas &i : v)
    {
        fr << left << setw(12) << i.getVardas() << setw(16) << i.getPavarde();
        fr << fixed << setw(17) << setprecision(2) << i.getGalV() << i.getGalM() << "\n";
    }
}

bool generuotiFaila(string &failas, int ndDydis, int &dydis)
{
    if (std::filesystem::exists(failas))
    {
        return false;
    }

    ofstream fr(failas);
    fr << left << setw(17) << "Vardas" << setw(18) << "Pavarde";
    for (int i = 0; i < ndDydis; i++)
    {
        fr << "ND" << setw(3) << i + 1;
    }
    fr << setw(5) << "Egz.\n";

    srand(time(0));
    for (int i = 0; i < dydis; i++)
    {
        fr << "VardasNR" << setw(9) << i + 1 << "PavardeNR" << setw(10) << i + 1;
        for (int j = 0; j < ndDydis + 1; j++)
        {
            fr << setw(5) << 1 + rand() % 10;
        }
        fr << "\n";
    }
    fr.close();
    return true;
}

string rusiuotiStudentus(list<Studentas> &A, list<Studentas> &v, int var)
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
        for (auto t = A.end(); t != A.begin();)
        {
            if (t->getGalV() < 5.0)
            {
                v.push_back(*t);
                t = A.erase(t);
            }
            else
            {
                --t;
            }
        }
    }
    else
    {
        for (auto t = A.end(); t != A.begin();)
        {
            if (t->getGalM() < 5.0)
            {
                v.push_back(*t);
                t = A.erase(t);
            }
            else
            {
                --t;
            }
        }
    }
    return pas;
}

string rusiuotiStudentus3(list<Studentas> &A, list<Studentas> &v, int var)
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
        A.remove_if([&](const Studentas &st)
                    {
            if (st.getGalV() < 5.0) {
                v.push_back(st);
                return true;
            }
            return false; });
    }
    else
    {
        A.remove_if([&](const Studentas &st)
                    {
            if (st.getGalM() < 5.0) {
                v.push_back(st);
                return true;
            }
            return false; });
    }
    return pas;
}

void testuotiKurima(string &failas, int ndDydis, int &dydis)
{
    Timer t;
    bool arEgzistuoja = generuotiFaila(failas, ndDydis, dydis);
    double laikas = t.elapsed();
    if (!arEgzistuoja)
    {
        return;
    }
    cout << dydis << " studentu failo generavimo laikas: " << laikas << "\n";
}