/*
ID: esrefoz2
TASK: combo
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
    ofstream fout("combo.out");
    ifstream fin("combo.in");

    int N;
    vector<int> john(3);
    vector<int> master(3);
    int counter = 0;
    bool flag;

    fin >> N;
    fin >> john[0] >> john[1] >> john[2];
    fin >> master[0] >> master[1] >> master[2];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {

                flag = true;

                if (min(abs(john[0] - i), N - abs(john[0] - i)) > 2)
                    flag = false;

                if (min(abs(john[1] - j), N - abs(john[1] - j)) > 2)
                    flag = false;

                if (min(abs(john[2] - k), N - abs(john[2] - k)) > 2)
                    flag = false;

                if (flag) {
                    counter++;
                    continue;
                }

                flag = true;

                if (min(abs(master[0] - i), N - abs(master[0] - i)) > 2)
                    flag = false;

                if (min(abs(master[1] - j), N - abs(master[1] - j)) > 2)
                    flag = false;

                if (min(abs(master[2] - k), N - abs(master[2] - k)) > 2)
                    flag = false;

                if (flag) {
                    counter++;
                    continue;
                }
            }
        }
    }
    fout << counter << endl;

}
