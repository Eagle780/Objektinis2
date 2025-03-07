#include "header.h"
#include "timeris.h"

int main()
{
    int dydis = 1000;
    string failas = "studentai" + to_string(dydis) + ".txt";
    int ndDydis = 5;

    vector<Studentas> A;

    cinEx();
    vector<Studentas> vargsiukai, galvociai;

    testuotiKurima(failas, ndDydis, dydis);

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
    cout << dydis << " studentu programos veikimo (be failo generavimo) laikas: " << visasLaikas << "\n";

    cout << "Paspauskite \"Enter\", kad iseitumete...";
    cin.get();

    return 0;
}
