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

void rasytiIFaila(string pav, vector<Studentas> &v)
{
    ofstream fr(pav);
    fr << "Vardas      Pavardė        Galutinis (Vid.)  Galutinis (Med.)\n";
    fr << "--------------------------------------------------\n";
    for (Studentas i : v)
    {
        fr << left << setw(12) << i.vardas << setw(16) << i.pavarde;
        fr << fixed << setw(17) << setprecision(2) << SkaiciuotiV(i) << SkaiciuotiM(i) << "\n";
    }
}

void issaugotiLaika(double laikas)
{
    ofstream fr("laikai.txt", ios::app);
    fr << failas << " " << laikas << "\n";
    fr.close();
}

bool generuotiFaila()
{
    string failasSt = "studentai" + to_string(dydis) + ".txt";

    if (std::filesystem::exists(failasSt))
    {
        cout << "Toks failas jau egzistuoja\n";
        return false;
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
    return true;
}

double rusiuotiStudentus(vector<Studentas> &v, vector<Studentas> &g)
{
    string pas = "";

    while (pas != "v" && pas != "m")
    {
        cout << "Studentus rusiuoti pagal vidurki ar mediana? (v/m)\n";
        cin >> pas;
    }

    Timer t;

    if (pas == "v")
    {
        for (Studentas st : A)
        {
            st.galutinis = SkaiciuotiV(st);
            if (st.galutinis < 5.0)
                v.push_back(st);
            else
                g.push_back(st);
        }
    }
    else
    {
        for (Studentas st : A)
        {
            st.galutinis = SkaiciuotiM(st);
            if (st.galutinis < 5.0)
                v.push_back(st);
            else
                g.push_back(st);
        }
    }
    double laikas = t.elapsed();
    return laikas;
}

void testuotiKurima()
{
    Timer t;
    bool arEgzistuoja = generuotiFaila();
    double laikas = t.elapsed();
    if (!arEgzistuoja)
    {
        cout << "Bandoma kurti faila, kuris egzistuoja, skaiciavimas nutraukiamas\n";
        return;
    }
    cout << dydis << " studentu failo generavimo laikas: " << laikas << "\n";
}

void testuotiApdorojima()
{
}