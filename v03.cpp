#include "funkcijos.cpp"



int main(){
    char n;
    vector<stud> studentas;
    string failas="duom.txt";
    string ifailas="rez.txt";
    klausimas(n, "Ar nuskaityti duomenis is failo? (T/N)");
    if (n=='T'||n=='t')
    skaitymas(studentas, failas);
    if (n=='N'||n=='n')
    ivestis(studentas);
    isvedimas(studentas);
    return 0;
}
