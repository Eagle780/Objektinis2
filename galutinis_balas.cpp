#include "header.h"
#include "timeris.h"

int main()
{
    int dydis = 100;
    string failas = "studentai" + to_string(dydis) + ".txt";
    int ndDydis = 5;
    double laikas = 0;
    int k = 0;
    cinEx();

    vector<Studentas> A;
    deque<Studentas> B;
    list<Studentas> C;

    vector<Studentas> vargsiukai, galvociai;
    deque<Studentas> vargsiukaiB, galvociaiB;
    list<Studentas> vargsiukaiC, galvociaiC;

    while (dydis < 10000000)
    {
        dydis *= 10;
        failas = "studentai" + to_string(dydis) + ".txt";
        testuotiKurima(failas, ndDydis, dydis);
    }

    while (true)
    {
        cout << "Koki konteineri naudoti duomenu saugojimui?\n";
        cout << "1 - vector, 2 - deque, 3 - list\n";
        try
        {
            cin >> k;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (k <= 0 || k >= 4)
        {
            cout << "Neteisingas skaicius\n";
            continue;
        }
        break;
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
    if (k == 1)
    {
        skaitytiFaila(failas, A);
    }
    else if (k == 2)
    {
        skaitytiFaila(failas, B);
    }
    else if (k == 3)
    {
        skaitytiFaila(failas, C);
    }
    laikas = t.elapsed();
    cout << dydis << " studentu failo nuskaitymo laikas: " << laikas << "\n";

    int variantas = 0;

    while (true)
    {
        cout << "Duomenis rusiuoti pagal:\n";
        cout << "1 - varda, 2 - pavarde, 3 - galutini (vid.), 4 - galutini (med.)\n";

        try
        {
            cin >> variantas;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (variantas < 1 || variantas > 4)
        {
            cout << "Neteisingas skaicius\n";
            continue;
        }
        break;
    }

    Timer t3;
    if (k == 1)
    {
        if (variantas == 1)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return a.vardas < b.vardas; });
        }

        else if (variantas == 2)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return a.pavarde < b.pavarde; });
        }

        else if (variantas == 3)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return SkaiciuotiV(a) > SkaiciuotiV(b); });
        }

        else if (variantas == 4)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return SkaiciuotiM(a) > SkaiciuotiM(b); });
        }
    }
    else if (k == 2)
    {
        if (variantas == 1)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.vardas < b.vardas; });
        }

        else if (variantas == 2)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.pavarde < b.pavarde; });
        }

        else if (variantas == 3)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return SkaiciuotiV(a) > SkaiciuotiV(b); });
        }

        else if (variantas == 4)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return SkaiciuotiM(a) > SkaiciuotiM(b); });
        }
    }
    else if (k == 3)
    {
        if (variantas == 1)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.vardas < b.vardas; });
        }

        else if (variantas == 2)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.pavarde < b.pavarde; });
        }

        else if (variantas == 3)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return SkaiciuotiV(a) > SkaiciuotiV(b); });
        }

        else if (variantas == 4)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return SkaiciuotiM(a) > SkaiciuotiM(b); });
        }
    }
    laikas = t3.elapsed();
    cout << dydis << " studentu konteinerio rusiavimo laikas: " << laikas << "\n";

    int var2 = 0;

    while (true)
    {
        cout << "Koki duomenu rusiavimo buda naudoti?\n";
        cout << "1 - vargsiuku ir galvociu, 2 - tik vargsiuku\n";

        try
        {
            cin >> var2;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (var2 < 1 || var2 > 3)
        {
            cout << "Neteisingas skaicius\n";
            continue;
        }
        break;
    }

    if (var2 == 1)
    {
        if (k == 1)
        {
            Timer t4;
            rusiuotiStudentus(A, vargsiukai, galvociai, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 2)
        {
            Timer t4;
            rusiuotiStudentus(B, vargsiukaiB, galvociaiB, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 3)
        {
            Timer t4;
            rusiuotiStudentus(C, vargsiukaiC, galvociaiC, variantas);
            laikas = t4.elapsed();
        }
        cout << dydis << " studentu surusiavimo i 2 konteinerius laikas: " << laikas << "\n";
    }
    else if (var2 == 2)
    {
        if (k == 1)
        {
            Timer t4;
            rusiuotiStudentus(A, vargsiukai, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 2)
        {
            Timer t4;
            rusiuotiStudentus(B, vargsiukaiB, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 3)
        {
            Timer t4;
            rusiuotiStudentus(C, vargsiukaiC, variantas);
            laikas = t4.elapsed();
        }
        cout << dydis << " studentu surusiavimo i 1 konteineri laikas: " << laikas << "\n";
    }

    Timer t2;
    if (k == 1)
    {
        rasytiIFaila("vargsiukai.txt", vargsiukai);
        rasytiIFaila("galvociai.txt", galvociai);
    }
    else if (k == 2)
    {
        rasytiIFaila("vargsiukai.txt", vargsiukaiB);
        rasytiIFaila("galvociai.txt", galvociaiB);
    }
    else if (k == 2)
    {
        rasytiIFaila("vargsiukai.txt", vargsiukaiC);
        rasytiIFaila("galvociai.txt", galvociaiC);
    }
    laikas = t2.elapsed();
    cout << dydis << " surusiuotu studentu irasymo laikas: " << laikas << "\n";

    double visasLaikas = tmain.elapsed();
    cout << dydis << " studentu programos veikimo (nuo failo pasirinkimo) laikas: " << visasLaikas << "\n";

    cout << "Paspauskite \"Enter\", kad iseitumete...";
    cin.get();
    cin.get();

    return 0;
}
