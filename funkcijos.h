#ifndef funkcijos
#define funkcijos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>

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
using std::ifstream;
using std::istringstream;

char klausimas(char &, string);
double pazivestis(int);
double sivestis(string ivest);
int pazskivestis(string ivest);
void ivestis(vector<stud>&);
void skaitymas (vector<stud>&, string &);
double vidurkis(vector<stud>&, int);
double mediana(vector<stud>&, int);
void isvedimas(vector<stud>&);

#endif
