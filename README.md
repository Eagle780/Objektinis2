# 2.0 versija

Projekto Apžvalga

Ši programa sugeneruoja studentų duomenų failus, suskaičiuoja studentų galutinį balą pagal pasirinktą kriterijų suskirsto studentus į dvi kategorijas pagal jų galutinį balą ir matuoja užtruktą laiką kiekviename etape.

Šioje versijoje taip pat pridėta galimybė pasirinkti, kokio tipo konteinerį (vector, deque ar list) ir kokią strategiją norite naudoti.

## Praeitų versijų aprašymai

- v0.1: programa leidžia įrašyti arba sugeneruoti savus studentus, o rezultatus rodo ekrane,
- v0.2: pridėtas skaitymas iš failo/ surašymas į failą,
- v0.3: funkcijos ir struktūros perkeltos į atskirus failus, pridėtas išimčių valdymas, leidžiantis sumažinti programos užstigimų šansą,
- v0.4: programa pati generuoja reikiamus failus, kuriuos naudoja tolimesniems skaičiavimams, pridėti laiko matavimai,
- v1.0: programa papildyta dar dviem konteineriais ir 3-jomis strategijomis,
- v1.1: "Studentas" pakeistas iš stuktūros į klasę,
- v1.2: Sukurti Studento klasės kopijavimo ir perkėlimo konstruktoriai ir metodai ir perdengtos įvesties ir išvesties operacijos.
- v1.5: Sukurta bazinė (abstrakti) klasė "Žmogus", o "Studentas" padaryta "Žmogaus" išvestine klase

## Platesnis programos aprašymas

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

Aplanke atsidarykite terminalą ir įrašykite:

    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release

Paleidžiamasis failas (GalutinisBalas.exe) atsiras build/Release aplanke.
Pirmą kartą paleidus programą bus sugeneruojami visi 5 testavimo failai. Visi sekantys paleidimai naudos tuos pačius 5 failus. Naujas failas bus sukurtas tik tada, jei senasis bus ištrintas.

## Naudojimosi instrukcija

Pradžioje Jūsų bus klausiama, ar norite atlikti metodų testą, po to bus prašoma pasirinkti norimą konteinerį, po to pateiktas meniu leis išsirinkti naujų studentų įrašymų būdą. Baigus įrašymą (arba norint iškart skaityti studentus iš failo) pasirenkamas 4-tas meniu variantas. Tada galėsite pasirinkti, pagal ką norite rūšiuoti pagrindinį konteinerį. Po rūšiavimo liks pasirinkti būdą, kuriuo norite suskirstyti "vargšiukus" ir "galvočius" į skirtingus konteinerius.
Baigus darbą spaudžiama "Enter".

### Duomenų išvedimas/įvedimas

Naudojant ne vien .exe programą, o ir patį kodą, "studentas.h" galima rasti perdengtus >> (įvedimo) ir << (išvedimo) metodus. Jie leidžia patogiau ir greičiau naudotis klase. Jei norite pamatyti paprastą pavyzdį, kaip jie veikia, paleidus .exe failą paleiskite testą (įrašykite t raidę).

Iškart po raidės t įvedimo jums reikės suvesti studento duomenis, pvz:

    vardas pavarde 10 9 10 10

Paskutinis pažimys bus nuskaitytas kaip egzamino rezultatas.

Įvedimo operatorių galima naudoti ne vien rankiniam įvedimui, bet ir nukaitymui iš failo, kadangi perdengtas operatorius kaip kintamąjį taip pat turi ir įvedimo būdą.

Studentą taip pat galima ir išvesti, panaudojus praeito pavyzdžio duomenis, bus išvedama

    vardas pavarde 9.86667 10

Išvestis taip pat, kaip ir įvestis, gali būti naudojama ir darbui su failais, kadangi operacija kaip kintamąjį paima išvesties metodą.

## Vector klasės funkcijos

Šioje versijoje buvo realizuota nuosava vektoriaus klasė, čia pateiksiu kelių funkcijų implementacijos pavyzdžius:

1.  Push_back(elementas)

    Jei vektoriaus viduje esancio masyvo dydis yra mažesnis už talpą, prie masyvo galo pridedamas naujas elementas, o kintamasis, kuris nurodo masyvo dydi, padidinamas vienetu.

    Jei vektorias viduje esančio masyvo dydis yra lygus talpai, tai pirma visi elementai perkopijuojami į nauja masyvą, kurio talpa būtų dvigubai didesnė už praeito, senasis masyvas ištrinamas, o prie naujojo galo pridedamas naujas elementas.

    Pvz:

        Vector<int> v;
        v.Push_back(10);
        v.Push_back(20);
        cout << v[0] << " " << v[1] << endl;

    Terminale gausite

        10 20

2.  Shrink_to_fit()

    Naudojamas norint sumažinti vektoriaus viduje esančio masyvo talpą, kad ji būtų lygi masyvo dydžiui.

    Jei dydis jau yra lygus talpai, grįžtama iš funkcijos ir niekas neįvykta.

    Kitu atveju sukuriamas naujas masyvas, kurio talpa būtu lygi senojo masyvo dydžiui, į jį nukopijuojami visi elementai, esantys senajame masyve, senasis ištrinamas, o naujasis masyvas tampa vektoriaus masyvu.

    Pvz:

        Vector<int> v;
        v.Push_back(10);
        v.Push_back(20);
        v.Push_back(30);
        cout << v.Capacity() << endl;
        v.Shrink_to_fit();
        cout << v.Capacity() << endl;

    Terminale gausite

        4
        3

3.  == operatorius

    Lygina, ar kiekvienas pirmojo vektoriaus elementas yra lygus antrojo vektoriaus elementui tame pačiame indekse.

    Jei dydžiai skiriasi, grąžinama false.

    Jei bent vienas elementas iš primojo vektoriaus neatitinka tame pačiame indekse esančio elemento iš antrojo vektoriaus, grąžinama false.

    Kitu atveju grąžinama true.

    Pvz:

        Vector<int> a{1, 2, 3}, b{1, 2, 3}, c{1, 2, 3, 4};
        cout << (a == b) << " " << (a == c) << endl;

    Terminale gausite

        1 0

4.  Resize(naujas_dydis(, reikšmė))

    Keičia vektoriaus viduje esančio masyvo dydį.

    Jei naujasis dydis lygus esamam dydžiui, grįžtama.

    Jei naujas dydis yra mažesnis už esamą, masyvo dydį rodančiam kintamajui priskiriama naujojo dydžio reikšmė.

    Jei naujas dydis didesnis už esamą, kuriamas naujas masyvas, kuriam rezervuojama didesnė reikšmė tarp naujojo dydžio ir talpos\*2. Į jį nukopijuojami visi senojo masyvo elementai ir nuo pabaigos iki norimo dydžio indeksų pridedama tuščio konstruktoriaus sukurtas elementas (jei nėra reikšmės) arba norima reikmė (jei ji yra).

    Pvz:

        Vector<int> d = {1, 2, 3};
        for (int i = 0; i < d.Size(); ++i)
        {
            cout << d[i] << " ";
        }
        cout << endl;
        d.Resize(5);
        for (int i = 0; i < d.Size(); ++i)
        {
            cout << d[i] << " ";
        }
        cout << endl;
        d.Resize(2);
        for (int i = 0; i < d.Size(); ++i)
        {
            cout << d[i] << " ";
        }
        cout << endl;
        d.Resize(6, 4);
        for (int i = 0; i < d.Size(); ++i)
        {
            cout << d[i] << " ";
        }
        cout << endl;

    Terminale gausime

        1 2 3
        1 2 3 0 0
        1 2
        1 2 4 4 4 4

5.  = operatorius

    Nukopijuoja visus antrojo vektoriaus elementus ir kintamuosius į pirmąjį.

    Pvz:

        Vector<int> a{1, 2, 3};
        Vector<int> b;
        b = a;
        for (int i=0; i < b.Size(); ++i)
            cout << b[i] << " ";
        cout << endl;

    Terminale gausite

        1 2 3

## Dokumentacija

Dokumentacijos failai yra docs/ aplanke. Ten rasite html/ ir latex/ aplankus taip pat ir jau pilnai sugeneruotą .pdf pavidalo dokumentaciją. Norint dokumentaciją matyti naršyklėje, html/ aplanke susiraskite failą "index.html" ir atidarykite jį naudodamiesi "Live Server" ar kitu .html failų paleidimo būdu.

## Testavimo sistemos parametrai

- CPU - AMD Ryzen 5 5600H, 3.30GHz
- RAM - 2x8GB DDR4 3200MHz
- SSD - PCIe gen 3 NVMe M.2 512GB

## Spartos Testavimo Rezultatai

Programa buvo testuojama Release režimu, siekiant gauti tikslius laiko matavimus. Žemiau pateikiamos rezultatų lentelės:

### vector

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00169           | 0.00203            | 0.00154             |
| 10,000 įrašų     | 0.01694           | 0.0303             | 0.0268              |
| 100,000 įrašų    | 0.354             | 0.376              | 0.354               |
| 1,000,000 įrašų  | 1.937             | 4.932              | 4.205               |
| 10,000,000 įrašų | 18.483            | 76.858             | 4.717               |

### deque

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00178           | 0.00215            | 0.00164             |
| 10,000 įrašų     | 0.0148            | 0.0252             | 0.0276              |
| 100,000 įrašų    | 0.179             | 0.387              | 0.374               |
| 1,000,000 įrašų  | 1.952             | 5.101              | 4.349               |
| 10,000,000 įrašų | 18.483            | 77.137             | 4.821               |

### list

| Failo dydis      | Duomenų skaitymas | Duomenų rūšiavimas | Studentų rūšiavimas |
| ---------------- | ----------------- | ------------------ | ------------------- |
| 1,000 įrašų      | 0.00196           | 0.00169            | 0.00111             |
| 10,000 įrašų     | 0.0178            | 0.0382             | 0.0231              |
| 100,000 įrašų    | 0.185             | 0.342              | 0.275               |
| 1,000,000 įrašų  | 2.093             | 5.427              | 3.029               |
| 10,000,000 įrašų | 18.732            | 77.154             | 6.214               |

Kaip matome, laikai, naudojant vien tik skirtingus konteinerius, skiriasi, nors ir nežymiai. Vektorius vidutiniškai veikia greičiausiai, o list'as - lėčiausiai.

## Strategijos testavimo rezultatai

Testuojama buvo ne vien lyginant skirtingų konteinerių naudojimą, bet ir pritaikant skirtingas studentų rūšiavimo strategijas

1 strategija: Studentai rūšiuojami į du skirtingus to pačio tipo konteinerius,
2 strategija: Naudojamas tik vienas papildomas konteineris, o perkelti įrašai ištrinami iš pradinio konteinerio
3 strategija: Greitesnis iš 2-ų buvusių taip pat taikant ir bibliotekas

### vector

| Failo dydis      | 1 strategija | 2 strategija | 3 strategija |
| ---------------- | ------------ | ------------ | ------------ |
| 1,000 įrašų      | 0.00030      | 0.0055       | 0.00024      |
| 10,000 įrašų     | 0.0027       | 0.511        | 0.0018       |
| 100,000 įrašų    | 0.030        | 40.92        | 0.013        |
| 1,000,000 įrašų  | 0.457        | >1000        | 0.235        |
| 10,000,000 įrašų | 4.868        | -            | 5.268        |

### deque

| Failo dydis      | 1 strategija | 2 strategija | 3 strategija |
| ---------------- | ------------ | ------------ | ------------ |
| 1,000 įrašų      | 0.00039      | 0.00109      | 0.00023      |
| 10,000 įrašų     | 0.0027       | 0.1232       | 0.0019       |
| 100,000 įrašų    | 0.031        | 12.62        | 0.016        |
| 1,000,000 įrašų  | 0.427        | >1000        | 0.253        |
| 10,000,000 įrašų | 4.866        | -            | 5.411        |

### list

| Failo dydis      | 1 strategija | 2 strategija | 3 strategija |
| ---------------- | ------------ | ------------ | ------------ |
| 1,000 įrašų      | 0.00052      | 0.00023      | 0.00032      |
| 10,000 įrašų     | 0.0041       | 0.0020       | 0.0024       |
| 100,000 įrašų    | 0.043        | 0.025        | 0.029        |
| 1,000,000 įrašų  | 0.430        | 0.302        | 0.392        |
| 10,000,000 įrašų | 6.158        | 4.731        | 6.329        |

Išbandžius visas strategijas su visais konteineriais, galime pastebėti įdomų dalyką, kad 3 startegija yra greičiausia su visais konteineriais išskyrus list'ą. Norint naudoti list'ą būtų geriausia taikyti 2 strategiją. 2 strategijos neefktyvumą, atsižvelgiant į vektorių ir deque laikus, galima paaiškinti tuo, kad atliekant kiekvieną perkėlimo operaciją, visi elementai turi būti perkopijuoti į naują vietą, neskaitant išmesto elemento. List'as nepatiria tokių minusų, nes jam reikia tik pakeisti rodykles į kitus narius. Tai taip pat iš dalies paaiškina, kodėl 2 strategija yra greitesnė nei 3, kai kalba eina apie list'ą.

## Struktūros ir klasės testavimo rezultatai

Šioje versijoje taip pat reikėjo palyginti realizacijos spartą naudojant struktūrą (v1.0) ir klasę (dabartinė, v1.1). Abi programos naudojo vektorių ir 3 strategiją:

### klasė

| Failo dydis     | Duomenų skaitymas | Rūšiavimas | Studentų rūšiavimas | Išvedimas į failus | Bendras laikas |
| --------------- | ----------------- | ---------- | ------------------- | ------------------ | -------------- |
| 100,000 įrašų   | 0.203             | 0.103      | 0.020               | 0.266              | 0.689          |
| 1,000,000 įrašų | 2.142             | 1.196      | 0.251               | 2.165              | 5.901          |

### struktūra

| Failo dydis     | Duomenų skaitymas | Rūšiavimas | Studentų rūšiavimas | Išvedimas į failus | Bendras laikas |
| --------------- | ----------------- | ---------- | ------------------- | ------------------ | -------------- |
| 100,000 įrašų   | 0.260             | 0.128      | 0.021               | 0.257              | 0.733          |
| 1,000,000 įrašų | 2.626             | 1.609      | 0.277               | 3.286              | 7.835          |

Iš rezultatų matome, kad, nors ir nežymiai, klasė veikia greičiau nei struktūra.

## Kompiliatoriaus flag'ų testavimo rezultatai

Programos greitis gali priklausyti ne vien nuo pačio kodo pateikimų, bet ir nuo paprasto flag'o (kompiliatoriaus optimizavimo lygio) pakeitimo kompiliuojant kodą. Testavimui naudotas 1,000,000 studentų failas bei vektorius ir 3 strategija:

### Klasė

| Flag    | Duomenų skaitymas | Rūšiavimas | Studentų rūšiavimas | Išvedimas į failus | Bendras laikas | dydis (KB) |
| ------- | ----------------- | ---------- | ------------------- | ------------------ | -------------- | ---------- |
| Be flag | 1.953             | 15.422     | 0.606               | 15.954             | 33.939         | 722        |
| O1      | 1.124             | 2.935      | 0.237               | 4.270              | 8.570          | 379        |
| O2      | 1.086             | 2.796      | 0.229               | 4.079              | 8.195          | 349        |
| O3      | 1.137             | 3.108      | 0.239               | 4.194              | 8.652          | 358        |

### Struktūra

| Flag    | Duomenų skaitymas | Rūšiavimas | Studentų rūšiavimas | Išvedimas į failus | Bendras laikas | dydis (KB) |
| ------- | ----------------- | ---------- | ------------------- | ------------------ | -------------- | ---------- |
| Be flag | 1.869             | 16.665     | 0.623               | 16.668             | 34.533         | 721        |
| O1      | 1.093             | 3.549      | 0.269               | 5.143              | 10.349         | 383        |
| O2      | 1.146             | 3.458      | 0.275               | 4.878              | 9.891          | 351        |
| O3      | 1.112             | 3.475      | 0.276               | 4.946              | 10.043         | 354        |

Kaip galima pastebėti iš rezultatų, greičiausias (ir mažiausiai vietos užimantis) flag'as yra ne O3, bet O2. Taip gali atsitikti todėl, nes O3 taiko sudėtingesnius kompiliavimo metodus, kurie parodo savo naudą naudojant dar daugiau duomenų, nei buvo naudojama dabar.

## Nuotraukos

Programos veikimo pavyzdys:

![GalutinisBalas.exe](https://github.com/user-attachments/assets/16aeabd3-fdcf-4e37-bdb8-f8606c23455a)
