#include "header.h"
#include "timeris.h"

int main()
{
    int dydis = 100;
    string failas = "studentai" + to_string(dydis) + ".txt";
    int ndDydis = 5;

    vector<Studentas> A;

    cinEx();
    vector<Studentas> vargsiukai, galvociai;

    while (dydis < 10000000)
    {
        dydis *= 10;
        failas = "studentai" + to_string(dydis) + ".txt";
        testuotiKurima(failas, ndDydis, dydis);
    }

    while (true)
    {
        cout << "Kokio dydzio faila testuoti? ";
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
    double laikas = t.elapsed();
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
