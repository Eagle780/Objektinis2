#include "funkcijos.cpp"

int main()
{
    Timer tmain;

    cinEx();
    vector<Studentas> vargsiukai, galvociai;

    testuotiKurima();

    Timer t;
    skaitytiFaila();
    double laikas = t.elapsed();
    cout << dydis << " studentu failo nuskaitymo laikas: " << laikas << "\n";

    laikas = rusiuotiStudentus(vargsiukai, galvociai);
    cout << dydis << " studentu surusiavimo laikas: " << laikas << "\n";

    Timer t2;
    rasytiIFaila("vargsiukai.txt", vargsiukai);
    rasytiIFaila("galvociai.txt", galvociai);
    laikas = t2.elapsed();
    cout << dydis << " surusiuotu studentu irasymo laikas: " << laikas << "\n";

    double visasLaikas = tmain.elapsed();
    cout << dydis << " studentu programos veikimo laikas: " << visasLaikas << "\n";

    return 0;
}
