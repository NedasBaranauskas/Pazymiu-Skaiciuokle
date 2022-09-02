#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>
#include "laikas.h"

#define INT_MAX 2147483647
#define minpaz 0
#define maxpaz 10

using std::string;
using std::cin;
using std::cout;
using std::setw;
using std::sort;
using std::endl;
using std::left;
using std::setprecision;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::istringstream;
using std::to_string;

struct stud{
    string vardas;
    string pavarde;
    vector<double> nd;
    double egz;
};

char klausimas(char &ats, string boolklausimas){
    cout<<boolklausimas;
    cin>>ats;
    while (ats!='T'&&ats!='t'&&ats!='N'&&ats!='n'||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<boolklausimas;
        cin>>ats;
    }
    return ats;
};

double pazivestis(int s){
    int sk;
    cout<<"Iveskite "<<(s+1)<<"-aji pazymi: "<<endl;
    cin>>sk;
    while (sk<minpaz||sk>maxpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cout<<"Iveskite "<<(s+1)<<"-aji pazymi :"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin>>sk;
    }
    return sk;
};

double sivestis(string ivest){
    cout<<ivest;
    double n;
    cin>>n;
    while (n>maxpaz||n<minpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<ivest;
        cin>>n;
    }
    return n;
};

int pazskivestis(string ivest){
    int n;
    cout<<ivest;
    cin>>n;
    while (n<minpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<ivest;
        cin>>n;
    }
    return n;
};

void ivestis(vector<stud>& studentas){
    double v;
    int studsk;
    int ndsk;
    char ats;
    klausimas(ats, "Ar zinote studentu skaiciu? (T/N)");
    if (ats=='T'||ats=='t'){
        studsk=(pazskivestis("Iveskite studentu skaiciu : "));
        studentas.reserve(studsk);
        for (int i=0; i<studsk; i++){
            cout<<"Iveskite "<<i+1<<"-ojo studento varda :"<<endl;
            cin>>studentas[i].vardas;
            cout<<"Iveskite "<<i+1<<"-ojo studento pavarde :"<<endl;
            cin>>studentas[i].pavarde;
            klausimas (ats, "Ar zinote studento namu darbu pazymiu skaiciu? (T/N)");
            if (ats=='T'||ats=='t'){
                ndsk=pazskivestis("Iveskite studento namu darbu pazymiu skaiciu : ");
                klausimas (ats, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats=='T'||ats=='t'){
                    cout<<"Atsitiktinai sugeneruoti pazymiai :"<<endl;
                    for (int j=0; j<ndsk; j++){
                        v=rand()%11;
                        studentas[i].nd.push_back(v);
                        cout<<v<<endl;
                    }
                }
                if (ats=='N'||ats=='n'){
                    pazskivestis("Iveskite studento namu darbu pazymiu skaiciu : ");
                    for (int j=0; j<studentas[i].nd.size(); j++){
                    studentas[i].nd.push_back(pazivestis(j));
                    }
                }
            }
            if (ats=='N'||ats=='n'){
                klausimas (ats, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats=='T'||ats=='t'){
                    while (ats=='T'||ats=='t'){
                        v=rand()%11;
                        studentas[i].nd.push_back(v);
                        cout<<"Sugeneruotas pazymys : "<<v<<endl;
                        klausimas(ats, "Ar norite sugeneruoti dar viena pazymi? (T/N)");
                    }
                }
                if (ats=='N'||ats=='n'){
                    ats='T';
                    while (ats=='T'||ats=='t'){
                        studentas[i].nd.push_back(pazivestis(studentas[i].nd.size()));
                        klausimas(ats, "Ar norite ivesti dar viena pazymi? (T/N)");
                    }
                }
            }
            klausimas (ats, "Ar norite patys ivesti studento egzamino rezultata? (T/N)");
            if (ats=='T'||ats=='t'){
                sivestis("Iveskite studento egzamino rezultata : ");
            }
            if (ats=='N'||ats=='n'){
                studentas[i].egz=rand()%11;
                cout<<"Studento egzamino rezultato atsitiktinai sugeneruotas pazymys : "<<studentas[i].egz<<endl;
            }
        }
    }
    if (ats=='N'||ats=='n'){
        while(ats=='N'||ats=='n'){
            cout<<"Iveskite "<<studentas.size()+1<<"-ojo studento varda : "<<endl;
            cin>>studentas[studentas.size()].vardas;
            cout<<"Iveskite "<<studentas.size()+1<<"-ojo studento pavarde : "<<endl;
            cin>>studentas[studentas.size()].pavarde;
            klausimas (ats, "Ar zinote studento namu darbu pazymiu skaiciu? (T/N)");
            if (ats=='T'||ats=='t'){
                studentas[studentas.size()].nd.resize(pazskivestis("Iveskite studento namu darbu pazymiu skaiciu : "));
                klausimas (ats, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats=='T'||ats=='t'){
                    cout<<"Atsitiktinai sugeneruoti pazymiai :"<<endl;
                    for (int j=0; j<studentas[studentas.size()].nd.size(); j++){
                        v=rand()%11;
                        studentas[studentas.size()].nd.push_back(v);
                        cout<<v<<endl;
                    }
                }
                if (ats=='N'||ats=='n'){
                    for (int j=0; j<studentas[studentas.size()].nd.size(); j++){
                    studentas[studentas.size()].nd.push_back(pazivestis(studentas[studentas.size()].nd.size()));
                    }
                }
            }
            if (ats=='N'||ats=='n'){
                klausimas (ats, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats=='T'||ats=='t'){
                    while (ats=='T'||ats=='t'){
                        v=rand()%11;
                        studentas[studentas.size()].nd.push_back(v);
                        cout<<"Sugeneruotas pazymys : "<<studentas[studentas.size()].nd[studentas[studentas.size()].nd.size()]<<endl;
                        klausimas(ats, "Ar norite sugeneruoti dar viena pazymi? (T/N)");
                    }
                }
                if (ats=='N'||ats=='n'){
                    ats='T';
                    while (ats=='T'||ats=='t'){
                        studentas[studentas.size()].nd.push_back(pazivestis(studentas[studentas.size()].nd.size()));
                        klausimas(ats, "Ar norite ivesti dar viena pazymi? (T/N)");
                    }
                }
            }
            klausimas (ats, "Ar norite patys ivesti studento egzamino rezultata? (T/N)");
            if (ats=='T'||ats=='t'){
                studentas[studentas.size()].egz=(sivestis("Iveskite studento egzamino rezultata : "));
            }
            if (ats=='N'||ats=='n'){
                studentas[studentas.size()].egz=(rand()%11);
                cout<<"Studento egzamino rezultato atsitiktinai sugeneruotas pazymys : "<<studentas[studentas.size()].egz<<endl;
            }
            stud st;
            studentas.push_back(st);
            klausimas(ats, "Ar baigete ivesti studentus? (T/N)");
            }
        }
}

double vidurkis(vector<stud>& studentas, int sk){
    double vid=0;
    if (studentas[sk].nd.size()>0){
    vid=accumulate(studentas[sk].nd.begin(), studentas[sk].nd.end(), 0)/studentas[sk].nd.size();
    }
    return vid;
}

double mediana(vector<stud>& studentas, int sk){
    double med=0;
    int m=0;
    if (studentas[sk].nd.size()>0){
    sort(studentas[sk].nd.begin(), studentas[sk].nd.end());
    int m=studentas[sk].nd.size()/2;
    if (studentas[sk].nd.size()%2==0){
        med=(double)(studentas[sk].nd[m-1] + studentas[sk].nd[m])/2.0;
    }
    else {
        m=studentas[sk].nd.size()/2;
        med=studentas[sk].nd[m];
    }
    }
    return med;
}

void isvedimas(vector<stud>& studentas){
    char iats;
    klausimas(iats,"Ar norite, kad butu isvedamas vidurkis?(Jei ne, isvedama mediana) (T/N)");
    if (iats=='T'||iats=='t'){
        cout<<left<<setw(25)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Vidurkis"<<setw(15)<<"Galutinis"<<endl;
            for (int i=0; i<studentas.size(); i++){
            cout<<left<<setw(15)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<vidurkis(studentas, i)<<setw(15)<<setprecision(5)<<((vidurkis(studentas, i)*0.4)+((studentas[i].egz)*0.6))<<endl;
            }
        }
    if (iats=='N'||iats=='n'){
        cout<<left<<setw(25)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Mediana"<<setw(15)<<"Galutinis"<<endl;
            for (int i=0; i<studentas.size(); i++){
            cout<<left<<setw(15)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<mediana(studentas, i)<<setw(15)<<setprecision(5)<<((vidurkis(studentas, i)*0.4)+((studentas[i].egz)*0.6))<<endl;
            }
        }
}
void generavimas(vector<stud>& studentas, string failas){
    timer t;
    int n=0;
    n=pazskivestis("Iveskite kiek studentu norite, kad butu sugeneruota : ");
    ofstream f;
    t.reset();
    f.open(failas);
    if(f.fail()){
        cout<<"Ivyko klaida"<<endl;
        exit(1);
    }
    f<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";
    for (int i=1; i<16; i++){
        f<<setw(6)<<"ND"+to_string(i);
    }
    f<<endl;
    for (int i=1; i<n+1; i++){
        f<<setw(20)<<"Vardas"+to_string(i)<<setw(20)<<"Pavarde"+to_string(i)<<setw(20);
        for (int j=0; j<15; j++){
            f<<setw(6)<<rand()%11;
        }
        f<<endl;
    }
    f.close();
    cout<<"Failo kurimas ir jo uzdarymas uztruko : "<<t.elapsed()<<" sek."<<endl;
}

void skaitymas (vector<stud>& studentas, string &failas){
    timer t;
    ifstream f;
    t.reset();
    f.open(failas);
    if(f.fail()){
        cout<<"Ivyko klaida"<<endl;
        exit(1);
    }
    string eil;
    int paz;
    getline(f, eil);
    while (getline(f, eil)){
        stud student;
        istringstream iss(eil);
        iss>>student.vardas;
        iss>>student.pavarde;
        while(iss>>paz){
            student.nd.push_back(paz);
        }
        student.nd.pop_back();
        student.egz=paz;
        studentas.push_back(student);
    }
    f.close();
    cout<<"Duomenu nuskaitymas is failo uztruko : "<<t.elapsed()<<" sek."<<endl;
}

void rusiavimas(vector<stud>& studentas, string kiet, string varg){
    timer t;
    ofstream k;
    ofstream v;
    t.reset();
    k.open(kiet);
    v.open(varg);
    if(k.fail()||v.fail()){
        cout<<"Ivyko klaida"<<endl;
        exit(1);
    }
    k<<left<<setw(20)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Vidurkis"<<setw(10)<<"Mediana"<<"Galutinis"<<endl<<endl;
    v<<left<<setw(20)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Vidurkis"<<setw(10)<<"Mediana"<<"Galutinis"<<endl<<endl;
    for (int i=0; i<studentas.size(); i++){
        if (((vidurkis(studentas, i)*0.4)+((studentas[i].egz)*0.6))>=5)
        k<<left<<setw(20)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<vidurkis(studentas, i)<<setw(10)<<setprecision(5)<<mediana(studentas, i)<<setprecision(5)<<((vidurkis(studentas, i)*0.4)+((studentas[i].egz)*0.6))<<endl;
        else
        v<<left<<setw(20)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<vidurkis(studentas, i)<<setw(10)<<setprecision(5)<<mediana(studentas, i)<<setprecision(5)<<((vidurkis(studentas, i)*0.4)+((studentas[i].egz)*0.6))<<endl;
    }
    
    k.close();
    v.close();
    cout<<"Studentu rusiavimas i du naujus failus uztruko : "<<t.elapsed()<<" sek."<<endl;

}

int main(){
    char n;
    vector<stud> studentas;
    string failas="10000000.txt";
    string kiet="kietiakai.txt";
    string varg="vargsiukai.txt";
    klausimas(n, "Ar generuoti pazymius? (T/N)");
    if (n=='T'||n=='t'){
        generavimas(studentas, failas);
        klausimas(n, "Ar skirstyti studentus? (T/N)");
        if (n=='T'||n=='t'){
        skaitymas(studentas, failas);
        rusiavimas(studentas, kiet, varg);
        }
    }
    if (n=='N'||n=='n'){
    klausimas(n, "Ar skirstyti studentus? (T/N)");
    if (n=='T'||n=='t'){
    skaitymas(studentas, failas);
    rusiavimas(studentas, kiet, varg);
    }
    if (n=='N'||n=='n'){
    ivestis(studentas);
    isvedimas(studentas);
    }
    }

    return 0;
}
