/*
ID: esrefoz2
TASK: milk2
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
    if (p1.first < p2.first) {
        return true;
    } else if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return false;
}

int main() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");

    int N;
    int s;
    int e;
    int max = 0;
    int min = 0;
    vector <pair<int, int> > data;
    vector <pair<int, int> > combined;

    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> s >> e;
        data.push_back(pair<int, int>(s, e));
    }
    sort(data.begin(), data.end(), comp);

    combined.push_back(data[0]);

    for (int i = 1; i < N; i++) {
        if (combined[combined.size() - 1].second >= data[i].first) {
            combined[combined.size() - 1].second =
                    data[i].second > combined[combined.size() - 1].second ? data[i].second : combined[combined.size() -
                                                                                                      1].second;
        } else {
            combined.push_back(data[i]);
        }
    }

    for (int i = 0; i < combined.size(); i++) {
        max = (combined[i].second - combined[i].first > max) ? (combined[i].second - combined[i].first) : max;
    }
    for (int i = 0; i < combined.size() - 1; i++) {
        min = (combined[i + 1].first - combined[i].second > min) ? (combined[i + 1].first - combined[i].second) : min;
    }



    fout << max << " " << min << endl;

    return 0;
}
