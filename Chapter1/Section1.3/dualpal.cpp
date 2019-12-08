/*
ID: esrefoz2
TASK: dualpal
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
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");

    int N, S;
    int ctr;
    string s;

    fin >> N >> S;

    while (S++) {
        ctr = 0;
        for (int b = 2; b <= 10; b++) {
            s = convert(S, b);
            if (check(s)) {
                ctr++;
            }
        }
        if (ctr >= 2) {
            fout << S << endl;
            N--;
            if (N == 0)
                break;
        }
    }

}
