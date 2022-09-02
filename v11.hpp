#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
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
using std::getline;
using std::istringstream;

class Studentas {
    private:
    std::string vardas_;
    std::string pavarde_;
    double egzaminas_;
    std::vector<double> nd_;
    public:
    Studentas() : egzaminas_(0) { }
    Studentas(std::istream& is);
    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    // double galBalas(double (*) (vector<double>) = mediana) const;
    std::istream& readStudent(std::istream&);
};

bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);
