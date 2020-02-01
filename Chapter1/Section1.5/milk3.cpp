/*
ID: esrefoz2
TASK: milk3
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

bool op[21][21][21];
int A, B, C;
bool res[21];


void solve(int a, int b, int c) {
    if (op[a][b][c]) {
        return;
    }
    op[a][b][c] = true;
    if (!a) {
        res[c] = true;
    }
    if (a + b > B) {
        solve(a - (B - b), B, c);
    } else {
        solve(0, a + b, c);
    }
    if (a + c > C) {
        solve(a - (C - c), b, C);
    } else {
        solve(0, b, a + c);
    }
    if (b + a > A) {
        solve(A, b - (A - a), c);
    } else {
        solve(a + b, 0, c);
    }
    if (b + c > C) {
        solve(a, b - (C - c), C);
    } else {
        solve(a, 0, b + c);
    }
    if (c + a > A) {
        solve(A, b, c - (A - a));
    } else {
        solve(a + c, b, 0);
    }
    if (b + c > B) {
        solve(a, B, c - (B - b));
    } else {
        solve(a, b + c, 0);
    }
}

int main() {
    ofstream fout("milk3.out");
    ifstream fin("milk3.in");

    fin >> A >> B >> C;

    solve(0, 0, C);

    bool flag = false;

    for (int i = 0; i <= 20; i++) {
        if (res[i]) {
            if (flag) {
                fout << " ";
            } else {
                flag = true;
            }
            fout << i;

        }
    }
    fout << endl;
}
