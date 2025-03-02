#include "funkcijos.cpp"

int main()
{
    cinEx();
    double laikas = 0;
    while (true)
    {
        Studentas temp;
        int a = 0;

        cout << "Studento duomenu ivedimo pasirinkimai:" << endl;
        cout << "1 - ranka, 2 - generuoti pazymius, 3 - generuoti ir pazymius ir studentų vardus, pavardes, 4 - baigti ivedima/skaityti duomenis is failo" << endl;

        try
        {
            cin >> a;
        }
        catch (ios_base::failure &e)
        {
            cout << "Neteisinga ivestis" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (a <= 0 || a >= 5)
        {
            cout << "Neteisingas skaicius" << endl;
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

    string pasirinkimas = "";

    while (pasirinkimas != "t" && pasirinkimas != "n")
    {
        cout << "Skaityti duomenis is failo? (t/n)" << endl;
        cin >> pasirinkimas;
    }

    if (pasirinkimas == "t")
    {
        Timer t;
        skaitytiFaila();
        laikas = t.elapsed();
    }

    int variantas = 0;

    while (true)
    {
        cout << "Duomenis rusiuoti pagal:" << endl;
        cout << "1 - varda, 2 - pavarde, 3 - galutini (vid.), 4 - galutini (med.)" << endl;
        cin >> variantas;

        if (cin.fail() || variantas < 1 || variantas > 4)
        {
            cout << "Neteisinga ivestis\n"
                 << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        break;
    }

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

    string pasirinkimas2 = "";
    while (pasirinkimas2 != "t" && pasirinkimas2 != "n")
    {
        cout << "Rezultataus spausdinti ekrane? (t/n)" << endl;
        cin >> pasirinkimas2;
    }

    if (pasirinkimas2 == "t")
    {
        spausdinti();
    }
    else
    {
        rasytiIFaila();
    }

    if (pasirinkimas == "t")
    {
        cout << "Skaitymo is failo laikas: " << laikas << " s" << endl;
        issaugotiLaika(laikas);
        vidutinisLaikas();
    }
    return 0;
}
