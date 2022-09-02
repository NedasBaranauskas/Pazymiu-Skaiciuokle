# Pazymiu-Skaiciuokle

Programa pagal įvestus arba iš failo nuskaitytus studentų vardų, pavardžių, namų darbų pažymių bei egzaminų rezultątų duomenis išveda lentelę, kurioje surašyti studentų vardai, pavardės, jų namų darbų pažymių vidurkiai arba medianos ir galutiniai pažymiai.

* [Funkcijos](#funkcijos)
* [Įdiegimo instrukcija](#įdiegimo-instrukcija-)
* [Naudojimosi instrukcija](#naudojimosi-instrukcija-)

## Funkcijos
Programoje vartotojas gali : 

- Pasirinkti ar programa nuskaitys duomenis ar duomenys bus įvesti
- Pasirinkti ar išvesti medianą, ar vidurkį
- Pasirinkti kiek studentų norės įvesti arba vesti po vieną
- Pasirinkti kiek namų darbų pažymių norės įvesti kiekvienam studentui arba vesti juos po vieną
- Pasirinkti ar nori pats įvesti namų darbų pažymį, ar nori, kad būtų įvedami atsitiktinai sugeneruoti pažymiai(bei pasirinkti ar šie bus sugeneruojami po vieną(su galimybe bet kada nutraukti jų generavimą), ar visus kartu)
- Pasirinkti atsitiktinai sugeneruotą egzamino rezultatą arba įvesti pačiam

Kitos programos funkcijos :

- Įvesties funkcijos "pagauna" įvairias įvesties klaidas (pvz.: jei įvedama raidė ar simbolis ten, kur turi būti pažymys, vartotojui išmetama klaida bei prašoma bandyti dar kartą.)
- Programos klausimų funkcija nėra case sensitive (nėra skirtumo jei atsakinėsite didžiosiomis ar mažosiomis raidėmis)

## Įdiegimo instrukcija :

Atsisiuntus programos kodą, reikia jį sukompiliuoti pasinaudojant komandine eilute
```
g++ -o programa main.cpp
```
Sukompiliavus programą, reikia ją paleisti
```
./programa
```

## Naudojimosi instrukcija :

Programa suprogramuota taip, kad vartotojas galėtų ja lengvai naudotis sekant jos nurodymus atidarius programą.
