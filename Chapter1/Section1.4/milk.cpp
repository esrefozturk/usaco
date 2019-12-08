/*
ID: esrefoz2
TASK: milk
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

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    ofstream fout("milk.out");
    ifstream fin("milk.in");

    int N;
    int M;
    int P;
    int A;

    fin >> N >> M;

    vector <pair<int, int> > milkers;

    for (int i = 0; i < M; i++) {
        fin >> P >> A;
        milkers.push_back(pair<int, int>(P, A));
    }

    sort(milkers.begin(), milkers.end(), comp);

    int cost = 0;

    for (int i = 0; i < M; i++) {
        cost += (milkers[i].second < N ? milkers[i].second : N) * milkers[i].first;
        N -= milkers[i].second < N ? milkers[i].second : N;
        if (N == 0)
            break;
    }
    fout << cost << endl;

}
