#include "header.h"

int main()
{
    vector<Studentas> A;

    while (true)
    {
        Studentas temp;
        int a = 0;
        int n = 0;

        cout << "Studento duomenu ivedimo pasirinkimai:" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentų vardus, pavardes, 4 - baigti ivedima" << endl;
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
            cout << "Iveskite varda: ";
            cin >> temp.vardas;
            cout << "Iveskite pavarde: ";
            cin >> temp.pavarde;

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

            A.push_back(temp);
        }

        else if (a == 2)
        {
            cout << "Iveskite varda: ";
            cin >> temp.vardas;
            cout << "Iveskite pavarde: ";
            cin >> temp.pavarde;

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

            srand(time(0));

            for (int i = 0; i < n; i++)
            {
                a = 1 + rand() % 10;
                temp.nd.push_back(a);
            }

            temp.egz = 1 + rand() % 10;

            A.push_back(temp);
        }

        else if (a == 3)
        {
            vector<string> Vardai = {"Jonas", "Antanas", "Petras", "Dovydas", "Tomas"};
            vector<string> Pavardes = {"Jonaitis", "Petrauskas", "Kazlauskas", "Antanaitis", "Ivanauskas"};

            srand(time(0));

            temp.vardas = Vardai[rand() % Vardai.size()];
            temp.pavarde = Pavardes[rand() % Pavardes.size()];

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

            srand(time(0));

            for (int i = 0; i < n; i++)
            {
                a = 1 + rand() % 10;
                temp.nd.push_back(a);
            }

            temp.egz = 1 + rand() % 10;

            A.push_back(temp);
        }

        else
        {
            break;
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