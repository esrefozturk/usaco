/*
ID: esrefoz2
TASK: crypt1
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
int first;
int second;
int result;
int counter = 0;


int digit_test[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool check(int number, int len) {


    vector<int> ds;
    while (number) {
        if (!digit_test[number % 10])
            return false;
        ds.push_back(number % 10);
        number /= 10;
    }
    if (ds.size() != len)
        return false;
    return true;
}


int main() {
    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");


    fin >> N;


    vector<int> digits(N);


    for (int i = 0; i < N; i++) {
        fin >> digits[i];
        digit_test[digits[i]] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int a = 0; a < N; a++) {
                    for (int b = 0; b < N; b++) {


                        if (digits[i] == 0 || digits[a] == 0) {
                            continue;
                        }

                        first = (digits[i] * 100 + digits[j] * 10 + digits[k]) * digits[b];

                        if (!check(first, 3)) {
                            continue;
                        }

                        second = (digits[i] * 100 + digits[j] * 10 + digits[k]) * digits[a];

                        if (!check(second, 3)) {
                            continue;
                        }


                        result = first + second * 10;

                        if (!check(result, 4)) {
                            continue;
                        }

                        counter++;

                    }
                }
            }
        }
    }

    fout << counter << endl;

}
