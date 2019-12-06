/*
ID: esrefoz2
TASK: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;


int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");

    vector <string> names;
    map<string, int> money;
    string name;
    string giver;
    int count;
    int total_money;
    int divide;


    fin >> count;


    for (int i = 0; i < count; i++) {
        fin >> name;
        names.push_back(name);
        money[name] = 0;
    }

    for (int j = 0; j < count; j++) {
        fin >> giver >> total_money >> divide;
        if (divide == 0)
            continue;
        for (int i = 0; i < divide; i++) {
            fin >> name;
            money[name] += total_money / divide;
        }
        money[giver] -= total_money;
        money[giver] += total_money % divide;
    }
    for (int i = 0; i < count; i++) {
        fout << names[i] << " " << money[names[i]] << endl;
    }


    return 0;
}
