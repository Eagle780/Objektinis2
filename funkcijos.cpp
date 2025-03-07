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
    int n;
    int a;
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
    try
    {
        ifstream fd(failas);

        if (!fd)
        {
            throw std::ios_base::failure("Nepavyko atidaryti failo");
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
    catch (ios_base::failure &e)
    {
        cout << "Nepavyko atidaryti failo\n";
        return;
    }
}

void rasytiIFaila()
{
    ofstream fr("rezultatai.txt");
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (Studentas i : A)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
    }
}

void spausdinti()
{
    cout << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    cout << "--------------------------------------------------\n";
    for (Studentas i : A)
    {
        cout << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        cout << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
    }
}

void issaugotiLaika(double laikas)
{
    ofstream fr("laikai.txt", ios::app);
    fr << failas << " " << laikas << "\n";
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
    cout << "Vidutinis laikas su \"" << failas << "\" yra: " << (visasLaikas / Laikai.size()) << " s\n";
}

void generuotiFaila()
{
    int b = 1;
    string failasSt = "studentai" + to_string(b) + ".txt";

    while (std::filesystem::exists(failasSt))
    {
        b++;
        failasSt = "studentai" + to_string(b) + ".txt";
    }

    ofstream fr(failasSt);
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
}