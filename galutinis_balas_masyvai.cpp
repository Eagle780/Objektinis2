#include "header.h"

int main()
{
    StudentasC *A = nullptr;
    int m = 0;
    int a;

    bool arTesti = true;
    while (arTesti)
    {
        StudentasC *naujiStudentai = new StudentasC[m + 1];

        for (int i = 0; i < m; i++)
        {
            naujiStudentai[i] = A[i];
        }

        cout << "Iveskite varda: ";
        cin >> naujiStudentai[m].vardas;
        cout << "Iveskite pavarde: ";
        cin >> naujiStudentai[m].pavarde;

        cout << "Iveskite pazymius (norint baigti pazymiu rasyma, irasykite 0):" << endl;

        int temp[100];
        int n = 0;

        while (true)
        {
            cin >> a;
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

        naujiStudentai[m].nd = new int[n];
        naujiStudentai[m].ndSk = n;
        for (int i = 0; i < n; i++)
        {
            naujiStudentai[m].nd[i] = temp[i];
        }

        a = 0;
        while (a <= 0 || a > 10)
        {
            cout << "Iveskite egzamino pazymi: ";
            cin >> a;
        }
        naujiStudentai[m].egz = a;

        delete[] A;
        A = naujiStudentai;
        m++;

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