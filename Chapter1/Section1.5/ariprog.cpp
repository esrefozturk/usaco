/*
ID: esrefoz2
TASK: ariprog
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

bool nums[125001];
vector<int> v;
int a, b;
int N, M;
int flag;
vector <pair<int, int> > res;


struct sort_pred {
    bool operator()(const std::pair<int, int> &left, const std::pair<int, int> &right) {
        return left.second < right.second;
    }
};


int main() {
    ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");


    fin >> N >> M;


    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            nums[i * i + j * j] = true;
            v.push_back(i * i + j * j);
        }
    }


    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {

            a = i;
            b = j - i;


            if ((a + b * (N - 1)) > (v[v.size() - 1] - v[0])) {
                break;
            }

            flag = true;

            for (int k = 0; k < N; k++) {
                if (!nums[a + k * b]) {
                    flag = false;
                    break;
                }
            }


            if (flag) {
                res.push_back(pair<int, int>(a, b));
            }

        }
    }
    if (!res.size()) {
        fout << "NONE" << endl;
    } else {
        sort(res.begin(), res.end(), sort_pred());
        for (int i = 0; i < res.size(); i++) {
            fout << res[i].first << " " << res[i].second << endl;
        }
    }


}
