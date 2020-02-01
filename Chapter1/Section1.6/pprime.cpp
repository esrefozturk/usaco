/*
ID: esrefoz2
TASK: pprime
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


int create(int x, int m) {
    int o = x;
    int y = 0;
    int mult = 1;
    while (x) {
        mult *= 10;
        y = y * 10 + x % 10;
        x /= 10;
    }
    if (m > 9) {
        return o * mult + y;
    }
    return o * mult * 10 + m * mult + y;

}

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (!(x % i)) {
            return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("pprime.out");
    ifstream fin("pprime.in");

    int a, b;

    fin >> a >> b;

    vector<int> v;

    for (int j = 0; j < 10; j++) {
        int pal = j;
        if (check(pal) && pal >= a && pal <= b) {
            v.push_back(pal);
        }
    }

    for (int i = 1; i < 1000; i++) {
        int pal = create(i, 10);
        if (check(pal) && pal >= a && pal <= b) {
            v.push_back(pal);
        }
        for (int j = 0; j < 10; j++) {
            int pal = create(i, j);
            if (check(pal) && pal >= a && pal <= b) {
                v.push_back(pal);
            }
        }
    }

    for(int i=0;i<v.size();i++){
        fout << v[i] << endl;
    }

}
