/*
ID: esrefoz2
TASK: skidesign
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

int N;
int hills[1000];
int min_cost = 1000000000;
int cost;

int main() {
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> hills[i];
    }

    for (int i = 0; i <= 83; i++) {
        cost = 0;
        for (int j = 0; j < N; j++) {
            if (hills[j] < i) {
                cost += (i - hills[j]) * (i - hills[j]);
            } else if (hills[j] > i + 17) {
                cost += (hills[j] - i - 17) * (hills[j] - i - 17);
            }
        }
        if (min_cost > cost) {
            min_cost = cost;
        }
    }

    fout << min_cost << endl;

}
