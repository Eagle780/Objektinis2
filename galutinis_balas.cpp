#include "header.h"
#include "timeris.h"

int main()
{
    int dydis = 100;
    string failas = "studentai" + to_string(dydis) + ".txt";
    int ndDydis = 5;
    double laikas = 0;
    cinEx();

    vector<Studentas> A;

    vector<Studentas> vargsiukai, galvociai;
    // vector<Studentas> vargsiukaiB, galvociaiB;
    // vector<Studentas> vargsiukaiC, galvociaiC;

    while (dydis < 10000000)
    {
        dydis *= 10;
        failas = "studentai" + to_string(dydis) + ".txt";
        testuotiKurima(failas, ndDydis, dydis);
    }

    while (true)
    {
        Studentas temp;
        int a = 0;

        cout << "Studento duomenu ivedimo pasirinkimai:\n";
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentų vardus, pavardes, 4 - baigti ivedima/skaityti duomenis is failo\n";

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

        if (a <= 0 || a >= 5)
        {
            cout << "Neteisingas skaicius\n";
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

    while (true)
    {
        cout << "Kokio dydzio faila naudoti? ";
        try
        {
            cin >> dydis;
        }

        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (!std::filesystem::exists("studentai" + to_string(dydis) + ".txt"))
        {
            cout << "Tokio dydzio failo nera\n";
            continue;
        }
        failas = "studentai" + to_string(dydis) + ".txt";
        break;
    }

    Timer tmain;
    Timer t;
    skaitytiFaila(failas, A);
    laikas = t.elapsed();
    cout << dydis << " studentu failo nuskaitymo laikas: " << laikas << "\n";

    laikas = rusiuotiStudentus(A, vargsiukai, galvociai);
    cout << dydis << " studentu surusiavimo laikas: " << laikas << "\n";

    Timer t2;
    rasytiIFaila("vargsiukai.txt", vargsiukai);
    rasytiIFaila("galvociai.txt", galvociai);
    laikas = t2.elapsed();
    cout << dydis << " surusiuotu studentu irasymo laikas: " << laikas << "\n";

    double visasLaikas = tmain.elapsed();
    cout << dydis << " studentu programos veikimo (be failo pasirinkimo) laikas: " << visasLaikas << "\n";

    cout << "Paspauskite \"Enter\", kad iseitumete...";
    cin.get();
    cin.get();

    return 0;
}
