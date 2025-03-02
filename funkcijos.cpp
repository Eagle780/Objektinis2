#include "timeris.h"

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
    ifstream fd;

    try
    {
        fd.exceptions(ios::failbit | ios::badbit);
        fd.open(failas);
    }
    catch (ios_base::failure &e)
    {
        cout << "Nepavyko atidaryti failo" << endl;
        return;
    }

    fd.ignore(numeric_limits<streamsize>::max(), '\n');

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

void rasytiIFaila()
{
    ofstream fr("rezultatai.txt");
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)" << endl;
    fr << "--------------------------------------------------" << endl;
    for (Studentas i : A)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << endl;
    }
}

void spausdinti()
{
    cout << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)" << endl;
    cout << "--------------------------------------------------" << endl;
    for (Studentas i : A)
    {
        cout << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        cout << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << endl;
    }
}

void issaugotiLaika(double laikas)
{
    ofstream fr("laikai.txt", ios::app);
    fr << failas << " " << laikas << endl;
    fr.close();
}

void vidutinisLaikas()
{
    vector<double> Laikai;
    double l;
    string pav;
    ifstream fd("laikai.txt");
    while (fd >> pav >> l)
    {
        if (pav == failas)
        {
            Laikai.push_back(l);
        }
    }
    fd.close();

    double visasLaikas = accumulate(Laikai.begin(), Laikai.end(), 0.0);
    cout << "Vidutinis laikas su \"" << failas << "\" yra: " << (visasLaikas / Laikai.size()) << " s" << endl;
}