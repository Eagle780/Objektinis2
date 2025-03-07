#include "funkcijos.cpp"

int main()
{
    cinEx();

    vector<Studentas> vargsiukai, galvociai;

    testuotiKurima();

    Timer t;
    skaitytiFaila();
    double laikas = t.elapsed();

    int variantas = 0;

    rasytiIFaila("rezultatai.txt", A);

    cout << "Skaitymo is failo laikas: " << laikas << " s\n";
    issaugotiLaika(laikas);
    vidutinisLaikas();

    rusiuotiStudentus(vargsiukai, galvociai);
    return 0;
}
