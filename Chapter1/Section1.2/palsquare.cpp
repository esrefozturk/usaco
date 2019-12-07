/*
ID: esrefoz2
TASK: palsquare
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


char *alp = "0123456789ABCDEFGHIJ";

string convert(int n, int b) {
    string s;
    while (n) {
        s += alp[n % b];
        n /= b;
    }
    string r;
    for (int i = s.size() - 1; i >= 0; i--) {
        r += s[i];
    }
    return r;
}

bool check(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");

    int base;
    string c1;
    string c2;


    fin >> base;

    for (int i = 1; i <= 300; i++) {
        c1 = convert(i, base);
        c2 = convert(i * i, base);
        if (check(c2)) {
            fout << c1 << " " << c2 << endl;
        }
    }

}
