/*
ID: esrefoz2
TASK: barn1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

int main() {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");

    int M, S, C;

    fin >> M >> S >> C;

    vector<int> occupieds(C);

    for (int i = 0; i < C; i++) {
        fin >> occupieds[i];
    }

    sort(occupieds.begin(), occupieds.end());

    S = occupieds[C - 1] - occupieds[0] + 1;

    vector<int> intervals;

    for (int i = 0; i < C - 1; i++) {
        intervals.push_back(occupieds[i + 1] - occupieds[i] - 1);
    }


    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < M - 1 && i < C - 1; i++) {
        S -= intervals[C - 2 - i];
    }


    fout << S << endl;

}
