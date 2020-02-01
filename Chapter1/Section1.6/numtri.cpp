/*
ID: esrefoz2
TASK: numtri
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int vals[1001][1001];

int main() {
    ofstream fout("numtri.out");
    ifstream fin("numtri.in");

    int R;

    fin >> R;



    for (int i = 0; i < R; i++) {
        for (int j = 0; j < i + 1; j++) {
            fin >> vals[i][j];
        }
    }

    for (int i = R - 2; i >= 0; i--) {
        for (int j = 0; j <= R; j++) {
            vals[i][j] += max(vals[i + 1][j], vals[i + 1][j + 1]);
        }
    }

    fout << vals[0][0] << endl;

}
