#include "header.h"
#include "timeris.h"

int main()
{
    int dydis = 100;
    string failas = "studentai" + to_string(dydis) + ".txt";
    int ndDydis = 5;
    double laikas = 0;
    int k = 0;
    string pas;

    cinEx();

    Vector<Studentas> A;
    deque<Studentas> B;
    list<Studentas> C;

    Vector<Studentas> vargsiukai, galvociai;
    deque<Studentas> vargsiukaiB, galvociaiB;
    list<Studentas> vargsiukaiC, galvociaiC;

    while (dydis < 10000000)
    {
        dydis *= 10;
        failas = "studentai" + to_string(dydis) + ".txt";
        testuotiKurima(failas, ndDydis, dydis);
    }

    char test;
    while (true)
    {
        cout << "ar atlikti klases testa? (t/n)\n";
        try
        {
            cin >> test;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (test != 't' && test != 'n')
        {
            cout << "Neteisinga ivestis\n";
            continue;
        }
        break;
    }

    if (test == 't')
    {
        TEST_MODE = true;
        Zmogus *temp = new Studentas();
        cout << temp << "\n";
        delete temp;

        Studentas temp1;
        cin >> temp1;
        cout << temp1;
        cout << "---\n";

        Studentas temp2 = temp1;
        cout << "pradinis temp1: " << temp1;
        cout << "nukopijuotas temp2: " << temp2;
        cout << "---\n";

        Studentas temp3 = move(temp2);
        cout << "perkeltas temp3: " << temp3;
        cout << "perkeltas temp2: " << temp2;
        cout << "---\n";

        Studentas temp4("vardas", "pavarde", {10, 10, 10}, 8);
        cout << "sukurtas temp4: " << temp4;
        cout << "---\n";

        temp2 = temp4;
        temp3 = move(temp4);
        cout << "nukopijuotas temp2: " << temp2;
        cout << "perkeltas temp3: " << temp3;
        cout << "perkeltas temp4: " << temp4;
    }
    TEST_MODE = false;
    cout << "\n";

    while (true)
    {
        cout << "Koki konteineri naudoti duomenu saugojimui?\n";
        cout << "1 - Vector, 2 - deque, 3 - list\n";
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
                 { return a.getVardas() < b.getVardas(); });
        }

        else if (variantas == 2)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getPavarde() < b.getPavarde(); });
        }

        else if (variantas == 3)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getGalV() > b.getGalV(); });
        }

        else if (variantas == 4)
        {
            sort(A.begin(), A.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getGalM() > b.getGalM(); });
        }
    }
    else if (k == 2)
    {
        if (variantas == 1)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getVardas() < b.getVardas(); });
        }

        else if (variantas == 2)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getPavarde() < b.getPavarde(); });
        }

        else if (variantas == 3)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getGalV() > b.getGalV(); });
        }

        else if (variantas == 4)
        {
            sort(B.begin(), B.end(), [](const Studentas &a, const Studentas &b)
                 { return a.getGalM() > b.getGalM(); });
        }
    }
    else if (k == 3)
    {
        if (variantas == 1)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.getVardas() < b.getVardas(); });
        }

        else if (variantas == 2)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.getPavarde() < b.getPavarde(); });
        }

        else if (variantas == 3)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.getGalV() > b.getGalV(); });
        }

        else if (variantas == 4)
        {
            C.sort([](const Studentas &a, const Studentas &b)
                   { return a.getGalM() > b.getGalM(); });
        }
    }
    laikas = t3.elapsed();
    cout << dydis << " studentu konteinerio rusiavimo laikas: " << laikas << "\n";

    int var2 = 0;

    while (true)
    {
        cout << "Koki duomenu rusiavimo buda naudoti?\n";
        cout << "1 - vargsiuku ir galvociu, 2 - tik vargsiuku, 3 - greitesni su algoritmais\n";

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

        if (var2 < 1 || var2 > 4)
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
            pas = rusiuotiStudentus(A, vargsiukai, galvociai, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 2)
        {
            Timer t4;
            pas = rusiuotiStudentus(B, vargsiukaiB, galvociaiB, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 3)
        {
            Timer t4;
            pas = rusiuotiStudentus(C, vargsiukaiC, galvociaiC, variantas);
            laikas = t4.elapsed();
        }
        cout << dydis << " studentu surusiavimo i 2 konteinerius laikas: " << laikas << "\n";
    }
    else if (var2 == 2)
    {
        if (k == 1)
        {
            Timer t4;
            pas = rusiuotiStudentus(A, vargsiukai, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 2)
        {
            Timer t4;
            pas = rusiuotiStudentus(B, vargsiukaiB, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 3)
        {
            Timer t4;
            pas = rusiuotiStudentus(C, vargsiukaiC, variantas);
            laikas = t4.elapsed();
        }
        cout << dydis << " studentu surusiavimo i 1 konteineri laikas: " << laikas << "\n";
    }
    else if (var2 == 3)
    {
        if (k == 1)
        {
            Timer t4;
            pas = rusiuotiStudentus3(A, vargsiukai, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 2)
        {
            Timer t4;
            pas = rusiuotiStudentus3(B, vargsiukaiB, variantas);
            laikas = t4.elapsed();
        }
        else if (k == 3)
        {
            Timer t4;
            pas = rusiuotiStudentus3(C, vargsiukaiC, variantas);
            laikas = t4.elapsed();
        }
        cout << dydis << " studentu surusiavimo greitesniu budu su algoritmais laikas: " << laikas << "\n";
    }

    Timer t2;
    if (var2 == 1)
    {
        if (k == 1)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukai, pas);
            rasytiIFaila("galvociai.txt", galvociai, pas);
        }
        else if (k == 2)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukaiB, pas);
            rasytiIFaila("galvociai.txt", galvociaiB, pas);
        }
        else if (k == 3)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukaiC, pas);
            rasytiIFaila("galvociai.txt", galvociaiC, pas);
        }
    }
    else if (var2 == 2 || var2 == 3)
    {
        if (k == 1)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukai, pas);
            rasytiIFaila("galvociai.txt", A, pas);
        }
        else if (k == 2)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukaiB, pas);
            rasytiIFaila("galvociai.txt", B, pas);
        }
        else if (k == 3)
        {
            rasytiIFaila("vargsiukai.txt", vargsiukaiC, pas);
            rasytiIFaila("galvociai.txt", C, pas);
        }
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
