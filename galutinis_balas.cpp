#include "header.h"

vector<Studentas> A;

void skaitytiFaila();
void rasytiIFaila(string pas);
void spausdinti(string pas);

int main()
{
    while (true)
    {
        Studentas temp;
        int a = 0;
        int n = 0;

        cout << "Studento duomenu ivedimo pasirinkimai:" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentų vardus, pavardes, 4 - baigti ivedima/skaityti duomenis is failo" << endl;
        cin >> a;

        if (cin.fail() || a < 1 || a > 4)
        {
            cout << "Neteisinga ivestis\n"
                 << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (a == 1)
        {
            temp = irasytiVarda(temp);
            temp = irasytiPazymius(temp);

            A.push_back(temp);
        }

        else if (a == 2)
        {
            temp = irasytiVarda(temp);
            temp = generuotiPazymius(temp);

            A.push_back(temp);
        }

        else if (a == 3)
        {
            temp = generuotiVardus(temp);
            temp = generuotiPazymius(temp);

            A.push_back(temp);
        }

        else
        {
            break;
        }
    }

    string pasirinkimas = "";

    while (pasirinkimas != "t" && pasirinkimas != "n")
    {
        cout << "Skaityti duomenis is failo? (t/n)" << endl;
        cin >> pasirinkimas;
    }

    if (pasirinkimas == "t")
    {
        skaitytiFaila();
    }

    while (pasirinkimas != "v" && pasirinkimas != "m")
    {
        cout << "Galutini pazymi skaiciuoti naudojant vidurki ar mediana? (v/m)" << endl;
        cin >> pasirinkimas;
    }

    string pasirinkimas2 = "";
    while (pasirinkimas2 != "t" && pasirinkimas2 != "n")
    {
        cout << "Rezultataus spausdinti ekrane? (t/n)" << endl;
        cin >> pasirinkimas2;
    }

    if (pasirinkimas2 == "t")
    {
        spausdinti(pasirinkimas);
    }
    else
    {
        rasytiIFaila(pasirinkimas);
    }

    return 0;
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
    int n;
    int a;
    while (true)
    {
        cout << "Iveskite pazymiu skaiciu: ";
        cin >> n;

        if (cin.fail() || n <= 0)
        {
            cout << "Neteisinga ivestis" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
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
    cout << "Iveskite pazymius (norint baigti pazymiu rasyma, irasykite 0):" << endl;
    while (true)
    {
        cin >> a;

        if (cin.fail())
        {
            cout << "Neteisinga ivestis" << endl;
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
                cout << "Iveskite bent viena pazymi" << endl;
            else
                break;
        }
        else
            cout << "Neteisingas pazymys" << endl;
    }

    a = 0;
    while (true)
    {
        cout << "Iveskite egzamino pazymi: ";
        cin >> a;

        if (cin.fail() || a <= 0 || a > 10)
        {
            cout << "Neteisinga ivestis" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        else
            break;
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

void skaitytiFaila()
{
    ifstream fd("Studentai10000.txt");
    fd.ignore(210, '\n');
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

void rasytiIFaila(string pas)
{
    ofstream fr("rezultatai.txt");
    if (pas == "v")
    {
        fr << "Vardas     Pavardė        Galutinis (Vid.)" << endl;
        fr << "--------------------------------------------------" << endl;
        for (Studentas i : A)
        {
            fr << left << setw(11) << i.vardas << setw(16) << i.pavarde;
            fr << fixed << setprecision(2) << SkaiciuotiV(i) << endl;
        }
    }
    else
    {
        fr << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        fr << "--------------------------------------------------" << endl;
        for (Studentas i : A)
        {
            fr << left << setw(11) << i.vardas << setw(16) << i.pavarde;
            fr << fixed << setprecision(2) << SkaiciuotiM(i) << endl;
        }
    }
}

void spausdinti(string pas)
{
    if (pas == "v")
    {
        cout << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (Studentas i : A)
        {
            cout << left << setw(11) << i.vardas << setw(16) << i.pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiV(i) << endl;
        }
    }

    else if (pas == "m")
    {
        cout << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (Studentas i : A)
        {
            cout << left << setw(11) << i.vardas << setw(16) << i.pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiM(i) << endl;
        }
    }
}