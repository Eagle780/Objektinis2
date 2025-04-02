#include "header.h"
#include "timeris.h"

void cinEx()
{
    cin.exceptions(ios::failbit | ios::badbit);
}

float SkaiciuotiV(Studentas A)
{
    int s = 0;
    for (int i = 0; i < A.nd.size(); i++)
    {
        s += A.nd[i];
    }
    float galutinis = 0.4 * (1.0 * s / A.nd.size()) + 0.6 * A.egz;
    return galutinis;
}

float SkaiciuotiM(Studentas A)
{
    float paz;
    sort(A.nd.begin(), A.nd.end());

    if (A.nd.size() % 2 == 0)
    {
        paz = 1.0 * (A.nd[A.nd.size() / 2 - 1] + A.nd[A.nd.size() / 2]) / 2;
    }
    else
    {
        paz = A.nd[A.nd.size() / 2];
    }

    float galutinis = 0.4 * paz + 0.6 * A.egz;
    return galutinis;
}

Studentas generuotiPazymius(Studentas temp)
{
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
        temp.nd.push_back(a);
    }

    temp.egz = 1 + rand() % 10;

    return temp;
}

Studentas generuotiVardus(Studentas temp)
{
    vector<string> Vardai = {"Jonas", "Antanas", "Petras", "Dovydas", "Tomas"};
    vector<string> Pavardes = {"Jonaitis", "Petrauskas", "Kazlauskas", "Antanaitis", "Ivanauskas"};

    srand(time(0));

    temp.vardas = Vardai[rand() % Vardai.size()];
    temp.pavarde = Pavardes[rand() % Pavardes.size()];

    return temp;
}

Studentas irasytiPazymius(Studentas temp)
{
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
            temp.nd.push_back(a);
        }
        else if (a == 0)
        {
            if (temp.nd.size() == 0)
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

    temp.egz = a;

    return temp;
}

Studentas irasytiVarda(Studentas temp)
{
    cout << "Iveskite varda: ";
    cin >> temp.vardas;
    cout << "Iveskite pavarde: ";
    cin >> temp.pavarde;

    return temp;
}

void rasytiIFaila(string pav, list<Studentas> &v, string pas)
{
    if (pas == "v")
    {
        v.sort([](const Studentas &a, const Studentas &b)
               { return SkaiciuotiV(a) > SkaiciuotiV(b); });
    }
    else if (pas == "m")
    {
        v.sort([](const Studentas &a, const Studentas &b)
               { return SkaiciuotiM(a) > SkaiciuotiM(b); });
    }
    ofstream fr(pav);
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (const Studentas &i : v)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
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
        A.remove_if([&](const Studentas &st)
                    {
                if (SkaiciuotiV(st) < 5.0)
                {
                    v.push_back(st);
                    return true;
                }
                return false; });
    }
    else
    {
        A.remove_if([&](const Studentas &st)
                    {
                if (SkaiciuotiV(st) < 5.0)
                {
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