/*
ID: esrefoz2
TASK: namenum
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int alphabet[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

int main() {
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
    ifstream dictin("dict.txt");

    string name;
    long long int no;
    long long int tmp;
    int flag = false;

    fin >> no;

    while (dictin >> name) {
        tmp = 0;
        for (int i = 0; i < name.size(); i++) {
            tmp = tmp * 10 + alphabet[name[i] - 'A'];
        }
        if (tmp == no) {
            fout << name << endl;
            flag = true;
        }
    }
    if (!flag) {
        fout << "NONE" << endl;
    }

}
