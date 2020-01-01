/*
ID: esrefoz2
TASK: wormhole
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
int holes[13][2];
int righty[13];
int pairy[13];

bool check() {
    for (int i = 1; i <= N; i++) {
        int current = i;
        for (int j = 1; j <= N; j++) {
            current = righty[pairy[current]];
        }
        if (current) return true;
    }
    return false;
}


int tryit() {

    int result = 0;
    int unpairyed;
    for (unpairyed = 1; unpairyed <= N; unpairyed++) {
        if (pairy[unpairyed] == 0) {
            break;
        }
    }

    if (unpairyed > N) {
        if (check()) {
            return 1;
        }
        return 0;
    }

    for (int j = unpairyed + 1; j <= N; j++) {
        if (pairy[j] == 0) {
            pairy[unpairyed] = j;
            pairy[j] = unpairyed;
            result += tryit();
            pairy[unpairyed] = 0;
            pairy[j] = 0;
        }
    }
    return result;
}


int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");

    fin >> N;


    for (int i = 1; i <= N; i++) {
        fin >> holes[i][0] >> holes[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (holes[j][0] > holes[i][0] && holes[j][1] == holes[i][1]) {
                if (righty[i] == 0 || holes[j][0] - holes[i][0] < holes[righty[i]][0] - holes[i][0]) {
                    righty[i] = j;
                }
            }
        }
    }


    fout << tryit() << endl;


}
