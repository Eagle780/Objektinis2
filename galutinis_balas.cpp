#include "header.h"

int main()
{
    vector<Studentas> A;

    bool arTesti = true;
    while (arTesti)
    {
        Studentas temp;
        int a;
        int n = 0;

        cout << "Iveskite varda: ";
        cin >> temp.vardas;
        cout << "Iveskite pavarde: ";
        cin >> temp.pavarde;

        string ats = "";

        while (ats != "t" && ats != "n")
        {
            cout << "Sugeneruoti atsitiktinius pazymius? (t/n)" << endl;
            cin >> ats;
        }

        if (ats == "t")
        {
            while (n <= 0)
            {
                cout << "Iveskite pazymiu skaiciu: ";
                cin >> n;
            }

            srand(time(0));

            for (int i = 0; i < n; i++)
            {
                a = 1 + rand() % 10;
                temp.nd.push_back(a);
            }

            temp.egz = 1 + rand() % 10;
        }

        else
        {
            cout << "Iveskite pazymius (norint baigti pazymiu rasyma, irasykite 0):" << endl;
            while (true)
            {
                cin >> a;

                if (cin.fail())
                {
                    cout << "Neteisingas ivestis" << endl;
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
            while (a <= 0 || a > 10)
            {
                cout << "Iveskite egzamino pazymi: ";
                cin >> a;
            }
            temp.egz = a;
        }

        A.push_back(temp);

        cout << "Ivesti dar viena studenta? (t/n)" << endl;
        string pas = "";
        while (true)
        {
            cin >> pas;
            if (pas == "n")
            {
                arTesti = false;
                break;
            }
            else if (pas == "t")
            {
                break;
            }
            else
            {
                cout << "Neteisinga ivestis" << endl;
            }
        }
    }

    string pasirinkimas = "";
    while (pasirinkimas != "v" && pasirinkimas != "m")
    {
        cout << "Galutini pazymi skaiciuoti naudojant vidurki ar mediana? (v/m)" << endl;
        cin >> pasirinkimas;
    }

    if (pasirinkimas == "v")
    {
        cout << "Vardas     Pavardė        Galutinis (Vid.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiV(A[i]) << endl;
        }
    }

    else if (pasirinkimas == "m")
    {
        cout << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < A.size(); i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiM(A[i]) << endl;
        }
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