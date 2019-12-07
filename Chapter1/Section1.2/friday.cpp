/*
ID: esrefoz2
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int result[7] = {1, 0, 0, 0, 0, 0, 0};

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int N;

    fin >> N;

    int current = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            if (j == 1) {
                if ((1900 + i) % 400 == 0) {
                    current = (current + 29) % 7;
                } else if ((1900 + i) % 100 == 0) {
                    current = (current + 28) % 7;
                } else if ((1900 + i) % 4 == 0) {
                    current = (current + 29) % 7;
                } else {
                    current = (current + 28) % 7;
                }
            } else {
                if (i == N - 1 && j == 11)
                    continue;
                current = (current + days[j]) % 7;
            }
            result[current] += 1;
        }
    }
    for (int i = 0; i < 6; i++) {
        fout << result[i] << " ";
    }
    fout << result[6] << endl;

    return 0;
}
