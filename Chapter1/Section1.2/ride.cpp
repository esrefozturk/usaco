/*
ID: esrefoz2
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calc(string s) {
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        res = (res * (s[i] - 'A' + 1)) % 47;
    }
    return res;
}

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string a, b;
    fin >> a >> b;
    if (calc(a) == calc(b)) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
