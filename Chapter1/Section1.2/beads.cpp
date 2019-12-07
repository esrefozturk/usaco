/*
ID: esrefoz2
TASK: beads
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

int N;
int m = 0;
int l = 0;
string necklace;

int calc(int s, int f) {
    int counter = 0;
    char current_color = 'w';
    while (counter * f < N) {
        if (necklace[(s + counter + N) % N] == 'w') {
            counter += f;
        } else {
            if (current_color == 'w') {
                current_color = necklace[(s + counter + N) % N];
                counter += f;
            } else if (current_color == necklace[(s + counter + N) % N]) {
                counter += f;
            } else {
                return counter * f;
            }
        }
    }
    return N;
}

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");


    fin >> N >> necklace;


    for (int i = 0; i < N; i++) {
        l = calc(i, -1) + calc((i + 1) % N, 1);
        if (l > m) {
            m = l;

        }
    }
    if (m > N) {
        fout << N << endl;
    } else {
        fout << m << endl;
    }


    return 0;
}
