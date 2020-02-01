/*
ID: esrefoz2
TASK: sprime
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

bool v[10][10];

bool check(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (!(x % i)) {
            return false;
        }
    }
    return true;
}


int main() {
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");

    int N;

    fin >> N;

    vector<int> p1;
    p1.push_back(2);
    p1.push_back(3);
    p1.push_back(5);
    p1.push_back(7);

    vector<int> p2;


    for(int i=1;i<N;i++){
        for(int j=0;j<p1.size();j++){
            for(int k=0;k<10;k++){
                if(check(p1[j]*10+k)){
                    p2.push_back(p1[j]*10+k);
                }
            }
        }
        p1 = p2;
        p2.clear();
    }

    for(int i=0;i<p1.size();i++){
        fout << p1[i] << endl;
    }

}
