#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>

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

struct stud{
    string vardas;
    string pavarde;
    int ndsk=1;
    double* nd = new double[ndsk];
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

void skivestis(int &sk, int s){
    cout<<"Iveskite "<<(s+1)<<"-aji pazymi :"<<endl;
    cin>>sk;
    while (sk<minpaz||sk>maxpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cout<<"Iveskite "<<(s+1)<<"-aji pazymi :"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin>>sk;
    }
};

void pazivestis(double &sk, int s){
    cout<<"Iveskite "<<(s+1)<<"-aji pazymi: "<<endl;
    cin>>sk;
    while (sk<minpaz||sk>maxpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cout<<"Iveskite "<<(s+1)<<"-aji pazymi :"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cin>>sk;
    }
};

void studivestis(int &n, string ivest){
    cout<<ivest;
    cin>>n;
    while (n<minpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<ivest;
        cin>>n;
    }
};

void sivestis(double &n, string ivest){
    cout<<ivest;
    cin>>n;
    while (n>maxpaz||n<minpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<ivest;
        cin>>n;
    }
};

void pazskivestis(int &n, string ivest){
    cout<<ivest;
    cin>>n;
    while (n<minpaz||cin.fail()){
        cout<<"Klaidinga ivestis. Bandykite dar karta"<<endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<ivest;
        cin>>n;
    }
};

void pazpridejimas(double *&mas, int dydis, double d){
    double *temp = new double[dydis + 1];
    for (int i=0; i<dydis; i++){
        temp[i]=mas[i];
    }
    temp[dydis]=d;
    delete[] mas;
    mas = temp;
}

void studpridejimas(stud *&mas, int &dydis, stud studentas){
    stud *temp = new stud[dydis+1];
    for (int i=0; i<dydis; i++){
        temp[i]=mas[i];
    }
    temp[dydis]=studentas;
    delete[] mas;
    mas=temp;
}

void ivestis(stud* &studentas, int &studsk){
    char ats1;
    char ats2;
    char ats3;
    char ats4='T';
    char ats5;
    studsk=0;
    klausimas(ats1, "Ar zinote studentu skaiciu? (T/N)");
    if (ats1=='T'||ats1=='t'){
        studivestis(studsk, "Iveskite studentu skaiciu : ");
        stud* studentas = new stud[studsk];
        for (int i=0; i<studsk; i++){
            cout<<"Iveskite "<<i+1<<"-ojo studento varda :"<<endl;
            cin>>studentas[i].vardas;
            cout<<"Iveskite "<<i+1<<"-ojo studento pavarde :"<<endl;
            cin>>studentas[i].pavarde;
            klausimas (ats2, "Ar zinote studento namu darbu pazymiu skaiciu? (T/N)");
            if (ats2=='T'||ats2=='t'){
                pazskivestis(studentas[i].ndsk,"Iveskite studento namu darbu pazymiu skaiciu : ");
                klausimas (ats3, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats3=='T'||ats3=='t'){
                    cout<<"Atsitiktinai sugeneruoti pazymiai :"<<endl;
                    for (int j=0; j<studentas[i].ndsk; j++){
                        studentas[i].nd[j]=(rand()%10);
                        cout<<studentas[i].nd[j]<<endl;
                    }
                }
                if (ats3=='N'||ats3=='n'){
                    studivestis(studentas[i].ndsk, "Iveskite studento namu darbu pazymiu skaiciu : ");
                    for (int j=0; j<studentas[i].ndsk; j++){
                    pazivestis(studentas[i].nd[j], j);
                    cout<<studentas[i].ndsk;
                    }
                }
            }
            if (ats2=='N'||ats2=='n'){
                int t=0;
                klausimas (ats3, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats3=='T'||ats3=='t'){
                    while (ats4=='T'||ats4=='t'){
                        studentas[i].nd[t]=(rand()%10);
                        pazpridejimas(studentas->nd, t, (rand()%10));
                        cout<<"Sugeneruotas pazymys : "<<studentas[i].nd[t]<<endl;
                        klausimas(ats4, "Ar norite sugeneruoti dar viena pazymi? (T/N)");
                        t++;
                    }
                }
                if (ats3=='N'||ats3=='n'){
                    while (ats4=='T'||ats4=='t'){
                        pazivestis(studentas[i].nd[t], t);
                        pazpridejimas(studentas->nd, t, studentas[i].nd[t]);
                        klausimas(ats4, "Ar norite ivesti dar viena pazymi? (T/N)");
                        t++;
                    }
                }
                studentas[i].ndsk=t;
            }
            klausimas (ats5, "Ar norite patys ivesti studento egzamino rezultata? (T/N)");
            if (ats5=='T'||ats5=='t'){
                sivestis(studentas[i].egz,"Iveskite studento egzamino rezultata : ");
            }
            if (ats5=='N'||ats5=='n'){
                studentas[i].egz=(rand()%10);
                cout<<"Studento egzamino rezultato atsitiktinai sugeneruotas pazymys : "<<studentas[i].egz<<endl;
            }
        }
    }
    if (ats1=='N'||ats1=='n'){
        int l=0;
        stud* studentas = new stud[l+1];
        while(ats1=='N'||ats1=='n'){
            cout<<"Iveskite "<<l+1<<"-ojo studento varda : "<<endl;
            cin>>studentas[l].vardas;
            cout<<"Iveskite "<<l+1<<"-ojo studento pavarde : "<<endl;
            cin>>studentas[l].pavarde;
            klausimas (ats2, "Ar zinote studento namu darbu pazymiu skaiciu? (T/N)");
            if (ats2=='T'||ats2=='t'){
                pazskivestis(studentas[l].ndsk,"Iveskite studento namu darbu pazymiu skaiciu: ");
                klausimas (ats3, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats3=='T'||ats3=='t'){
                    for (int j=0; j<studentas[l].ndsk; j++){
                        studentas[l].nd[j]=(rand()%10);
                    }
                    cout<<"Atsitiktinai sugeneruoti pazymiai :"<<endl;
                    for (int j=0; j<studentas[l].ndsk; j++){
                        cout<<studentas[l].nd[j]<<endl;
                    }
                }
                if (ats3=='N'||ats3=='n'){
                    studivestis(studentas[l].ndsk, "Iveskite studento namu darbu pazymiu skaiciu : ");
                    for (int j=0; j<studentas[l].ndsk; j++){
                    pazivestis(studentas[l].nd[j], j);
                    }
                }
            }
            if (ats2=='N'||ats2=='n'){
                int t=0;
                klausimas (ats3, "Ar norite, kad butu atsitiktinai sugeneruoti pazymiai? (T/N)");
                if (ats3=='T'||ats3=='t'){
                    while (ats4=='T'||ats4=='t'){
                        studentas[l].nd[t]=(rand()%10);
                        pazpridejimas(studentas->nd, t, studentas[l].nd[t]);
                        cout<<"Sugeneruotas pazymys : "<<studentas[l].nd[t]<<endl;
                        klausimas(ats4, "Ar norite sugeneruoti dar viena pazymi? (T/N)");
                        t++;
                    }
                }
                if (ats3=='N'||ats3=='n'){
                    while (ats4=='T'||ats4=='t'){
                        pazivestis(studentas[l].nd[t], t);
                        pazpridejimas(studentas->nd, t, studentas[l].nd[t]);
                        klausimas(ats4, "Ar norite ivesti dar viena pazymi? (T/N)");
                        t++;
                    }
                }
                studentas[l].ndsk=t;
            }
            klausimas (ats5, "Ar norite patys ivesti studento egzamino rezultata? (T/N)");
            if (ats5=='T'||ats5=='t'){
                sivestis(studentas[l].egz,"Iveskite studento egzamino rezultata : ");
            }
            if (ats5=='N'||ats5=='n'){
                studentas[l].egz=(rand()%10);
                cout<<"Studento egzamino rezultato atsitiktinai sugeneruotas pazymys : "<<studentas[l].egz<<endl;
            }
            l++;
            klausimas(ats1, "Ar baigete ivesti studentus? (T/N)");
            studpridejimas(studentas, l, studentas[l]);
        }
        studsk=l;
    }
    delete[] studentas;
}

double vidurkis(int ndpazsk, double paz[]){
    double v=0;
    double vid=0;
    for (int i=0; i<ndpazsk; i++){
        v=v+paz[i];
    }
    vid=v/ndpazsk;
    return vid;
}

double mediana(int ndpazsk, double paz[]){
    double med;
    sort(paz, (paz+ndpazsk));
    int m=ndpazsk/2;
    if (ndpazsk%2==0){
        med=(double)(paz[m-1] + paz[m])/2.0;
    }
    else {
        med=(double)paz[m];
    }
    return med;
}

void isvedimas(stud* studentas, int studsk){
    char iats;
    klausimas(iats,"Ar norite, kad butu isvedamas vidurkis?(Jei ne, isvedama mediana) (T/N)");
    if (iats=='T'||iats=='t'){
        cout<<left<<setw(25)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Vidurkis"<<setw(15)<<"Galutinis"<<endl;
            for (int i=0; i<studsk; i++){
            cout<<left<<setw(15)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<vidurkis(studentas[i].ndsk, studentas[i].nd)<<setw(15)<<setprecision(5)<<((vidurkis(studentas[i].ndsk, studentas[i].nd)*0.4)+((studentas[i].egz)*0.6))<<endl;
        }
    }
    if (iats=='N'||iats=='n'){
        cout<<left<<setw(25)<<"Studento vardas"<<setw(20)<<"Pavarde"<<setw(15)<<"Mediana"<<setw(15)<<"Galutinis"<<endl;
            for (int i=0; i<studsk; i++){
            cout<<left<<setw(15)<<studentas[i].vardas<<setw(20)<<studentas[i].pavarde<<setw(15)<<setprecision(5)<<mediana(studentas[i].ndsk, studentas[i].nd)<<setw(15)<<setprecision(5)<<((vidurkis(studentas[i].ndsk, studentas[i].nd)*0.4)+((studentas[i].egz)*0.6))<<endl;
        }
    }
}

int main(){
    srand(time(NULL));
    int studsk=1;
    stud* studentas = new stud[studsk];
    ivestis(studentas, studsk);
    isvedimas(studentas, studsk);
    delete[] studentas;

    return 0;
}