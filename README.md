# 1.0 versija

Projekto Apžvalga

Ši programa sugeneruoja studentų duomenų failus, suskaičiuoja studentų galutinį balą pagal pasirinktą kriterijų suskirsto studentus į dvi kategorijas pagal jų galutinį balą ir matuoja užtruktą laiką kiekviename etape.

Šioje versijoje taip pat pridėta galimybė pasirinkti, kokio tipo konteinerį (vector, deque ar list) norite naudoti.

## Įgyvendintos Funkcijos

### Failų generavimas:

- Sugeneruojami penki skirtingo dydžio studentų sąrašų failai (1,000, 10,000, 100,000, 1,000,000 ir 10,000,000 įrašų).

### Studentų rūšiavimas:

- Studentai skirstomi į dvi grupes:
  - „Vargšiukai“ – Galutinis balas < 5.0
  - „Galvočiai“ – Galutinis balas ≥ 5.0

### Matuojamas laikas:

- Failo sukūrimui
- Duomenų nuskaitymui
- Duomenų failo rūšiavimui
- Studentų rūšiavimui
- Surūšiuotų duomenų išvedimui į naujus failus
- Bendram programos veikimo laikui

## Kaip Paleisti Programą

Klonuokite repozitoriją:

    git clone https://github.com/Eagle780/Objektinis.git

Pereikite į v1.0 šaką:

    git checkout v1.0

Sukompiliuokite ir paleiskite:

    g++ -O3 -o main galutinis_balas.cpp funkcijos.cpp
    ./main.exe

Pirmą kartą paleidus programą bus sugeneruojami visi 5 testavimo failai. Visi sekantys paleidimai naudos tuos pačius 5 failus. Naujas failas bus sukurtas tik tada, jei senasis bus ištrintas.

## Spartos Testavimo Rezultatai

Programa buvo testuojama Release režimu, siekiant gauti tikslius laiko matavimus. Žemiau pateikiamos rezultatų lentelės:

### vector

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00190           | 0.0020             | 0.00164             |
| 10,000 įrašų     | 0.01694           | 0.0303             | 0.0276              |
| 100,000 įrašų    | 0.354             | 0.376              | 0.354               |
| 1,000,000 įrašų  | 1.937             | 4.932              | 4.205               |
| 10,000,000 įrašų | 18.483            | 77.137             | 58.095              |

### deque

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00169           | 0.00215            | 0.00154             |
| 10,000 įrašų     | 0.0148            | 0.0252             | 0.0268              |
| 100,000 įrašų    | 0.179             | 0.387              | 0.374               |
| 1,000,000 įrašų  | 1.952             | 5.101              | 4.349               |
| 10,000,000 įrašų | 18.483            | 75.658             | 60.246              |

### list

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00196           | 0.00169            | 0.00111             |
| 10,000 įrašų     | 0.0178            | 0.0382             | 0.0231              |
| 100,000 įrašų    | 0.185             | 0.342              | 0.275               |
| 1,000,000 įrašų  | 2.093             | 5.427              | 3.029               |
| 10,000,000 įrašų | 18.732            | 77.154             | 36.575              |

## Testavimo sistemos parametrai

- CPU - AMD Ryzen 5 5600H, 3.30GHz
- RAM - 2x8GB 3200MT/s
- SSD - 512GB M.2, NVMe PCIe gen 3

## Nuotraukos

Programos veikimo pavyzdys:

![main.exe](https://github.com/user-attachments/assets/642ae5f5-f374-4dbd-ac13-bc1a3fdd41b5)
