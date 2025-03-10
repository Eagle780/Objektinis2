# 0.4 versija
Projekto Apžvalga

Ši programa sugeneruoja studentų duomenų failus, suskaičiuoja studentų galutinį balą pagal pasirinktą kriterijų suskirsto studentus į dvi kategorijas pagal jų galutinį balą ir matuoja užtruktą laiką kiekviename etape.
Įgyvendintos Funkcijos

### Failų generavimas:
- Sugeneruojami penki skirtingo dydžio studentų sąrašų failai (1,000, 10,000, 100,000, 1,000,000 ir 10,000,000 įrašų).
### Studentų rūšiavimas:
- Studentai skirstomi į dvi grupes:
  - „Vargšiukai“ – Galutinis balas < 5.0
  - „Galvočiai“ – Galutinis balas ≥ 5.0
### Matuojamas laikas:
- Failo sukūrimui
- Duomenų nuskaitymui
- Studentų rūšiavimui
- Surūšiuotų duomenų išvedimui į naujus failus
- Bendram programos veikimo laikui


## Kaip Paleisti Programą

Klonuokite repozitoriją:

    git clone https://github.com/Eagle780/Objektinis.git

Pereikite į v0.4 šaką:

    git checkout v0.4

Sukompiliuokite ir paleiskite:

    g++ -O3 -o main galutinis_balas.cpp funkcijos.cpp
    ./main.exe

Pirmą kartą paleidus programą bus sugeneruojami visi 5 testavimo failai. Visi sekantys paleidimai naudos tuos pačius 5 failus. Naujas failas bus sukurtas tik tada, jei jis bus ištrintas.

## Spartos Testavimo Rezultatai

Programa buvo testuojama Release režimu, siekiant gauti tikslius laiko matavimus. Žemiau pateikiama rezultatų lentelė:

| Failo dydis      | Failo sukūrimas    |  Duomenų skaitymas  |  Rūšiavimas  |  Išvedimas į failus  | Bendras laikas  |
|------------------|--------------------|---------------------|--------------|----------------------|-----------------|
| 1,000 įrašų      |  0.00329           |  0.00181            | 0.000361     |  0.00463             |  0.541          |
| 10,000 įrašų     |  0.0268            |  0.0161             | 0.00395      |  0.0232              |  1.167          |
| 100,000 įrašų    |  0.125             |  0.216              | 0.0314       |  0.257               |  1.670          |
| 1,000,000 įrašų  |  1.357             |  1.952              | 0.375        |  2.688               |  5.540          |
| 10,000,000 įrašų | 10.271             | 18.039              | 5.729        | 20.416               | 45.468          |

## Nuotraukos
Programos veikimo pavyzdys:

![Main.exe](https://github.com/user-attachments/assets/c54a3221-0ab9-416e-bfbb-7bade756ac15)

Sukurto failo pavyzdys:

![studentai100000.txt](https://github.com/user-attachments/assets/e4ceb57f-0443-41df-8f86-f0cd351c4745)

Išrūšiuoto failo pavyzdys:

![galvociai.txt](https://github.com/user-attachments/assets/836a7daf-61e7-4ca1-aeed-b88ee36ba257)


