#include "header.h"

int main()
{
    StudentasC *A = nullptr;
    int m = 0;

    while (true)
    {
        int a = 0;
        int temp[100];
        int n = 0;

        StudentasC *naujiStudentai = new StudentasC[m + 1];

        for (int i = 0; i < m; i++)
        {
            naujiStudentai[i] = A[i];
        }

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
            cin >> naujiStudentai[m].vardas;
            cout << "Iveskite pavarde: ";
            cin >> naujiStudentai[m].pavarde;

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
                    temp[n] = a;
                    n++;
                }
                else if (a == 0)
                {
                    if (n == 0)
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

            naujiStudentai[m].nd = new int[n];
            naujiStudentai[m].ndSk = n;

            for (int i = 0; i < n; i++)
            {
                naujiStudentai[m].nd[i] = temp[i];
            }

            naujiStudentai[m].egz = a;

            delete[] A;
            A = naujiStudentai;
            m++;
        }

        else if (a == 2)
        {
            cout << "Iveskite varda: ";
            cin >> naujiStudentai[m].vardas;
            cout << "Iveskite pavarde: ";
            cin >> naujiStudentai[m].pavarde;

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
                temp[i] = 1 + rand() % 10;
            }

            a = 1 + rand() % 10;

            naujiStudentai[m].nd = new int[n];
            naujiStudentai[m].ndSk = n;

            for (int i = 0; i < n; i++)
            {
                naujiStudentai[m].nd[i] = temp[i];
            }

            naujiStudentai[m].egz = a;

            delete[] A;
            A = naujiStudentai;
            m++;
        }

        else if (a == 3)
        {
            int v = 5, p = 5;
            string Vardai[] = {"Jonas", "Antanas", "Petras", "Dovydas", "Tomas"};
            string Pavardes[] = {"Jonaitis", "Petrauskas", "Kazlauskas", "Antanaitis", "Ivanauskas"};

            srand(time(0));

            naujiStudentai[m].vardas = Vardai[rand() % v];
            naujiStudentai[m].pavarde = Pavardes[rand() % p];

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
                temp[i] = 1 + rand() % 10;
            }

            a = 1 + rand() % 10;

            naujiStudentai[m].nd = new int[n];
            naujiStudentai[m].ndSk = n;

            for (int i = 0; i < n; i++)
            {
                naujiStudentai[m].nd[i] = temp[i];
            }

            naujiStudentai[m].egz = a;

            delete[] A;
            A = naujiStudentai;
            m++;
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
        for (int i = 0; i < m; i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiV(A[i], m) << endl;
        }
    }

    else if (pasirinkimas == "m")
    {
        cout << "Vardas     Pavardė        Galutinis (Med.)" << endl;
        cout << "--------------------------------------------------" << endl;
        for (int i = 0; i < m; i++)
        {
            cout << left << setw(11) << A[i].vardas << setw(14) << A[i].pavarde;
            cout << fixed << setprecision(2) << SkaiciuotiM(A[i], m) << endl;
        }
    }

    return 0;
}

float SkaiciuotiV(StudentasC A, int m)
{
    int s = 0;
    for (int i = 0; i < A.ndSk; i++)
    {
        s += A.nd[i];
    }
    float galutinis = 0.4 * (1.0 * s / A.ndSk) + 0.6 * A.egz;
    return galutinis;
}

float SkaiciuotiM(StudentasC A, int m)
{
    float paz;
    sort(A.nd, A.nd + A.ndSk);

    if (A.ndSk % 2 == 0)
    {
        paz = 1.0 * (A.nd[A.ndSk / 2 - 1] + A.nd[A.ndSk / 2]) / 2;
    }
    else
    {
        paz = A.nd[A.ndSk / 2];
    }

    float galutinis = 0.4 * paz + 0.6 * A.egz;
    return galutinis;
}