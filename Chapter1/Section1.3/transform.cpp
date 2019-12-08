/*
ID: esrefoz2
TASK: transform
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int N;
vector <string> start;
vector <string> last;


vector <string> o1(vector <string> v1) {
    vector <string> v2;
    for (int i = 0; i < N; i++) {
        string s;
        for (int j = N - 1; j >= 0; j--) {
            s += v1[j][i];
        }
        v2.push_back(s);
    }
    return v2;
}

vector <string> o2(vector <string> v1) {
    vector <string> v2;
    for (int i = N - 1; i >= 0; i--) {
        string s;
        for (int j = N - 1; j >= 0; j--) {
            s += v1[i][j];
        }
        v2.push_back(s);
    }
    return v2;
}

vector <string> o3(vector <string> v1) {
    vector <string> v2;
    for (int i = N - 1; i >= 0; i--) {
        string s;
        for (int j = 0; j < N; j++) {
            s += v1[j][i];
        }
        v2.push_back(s);
    }
    return v2;
}

vector <string> o4(vector <string> v1) {
    vector <string> v2;
    for (int i = 0; i < N; i++) {
        string s;
        for (int j = N - 1; j >= 0; j--) {
            s += v1[i][j];
        }
        v2.push_back(s);
    }
    return v2;
}

vector <string> o5(vector <string> v1) {
    vector <string> v2;
    for (int i = N - 1; i >= 0; i--) {
        string s;
        for (int j = 0; j < N; j++) {
            s += v1[i][j];
        }
        v2.push_back(s);
    }
    return v2;
}


bool check(vector <string> v1, vector <string> v2) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (v1[i][j] != v2[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");

    fin >> N;

    start = vector<string>(N, "");
    last = vector<string>(N, "");


    for (int i = 0; i < N; i++) {
        fin >> start[i];
    }
    for (int i = 0; i < N; i++) {
        fin >> last[i];
    }

    if (check(o1(start), last)) {
        fout << 1 << endl;
    } else if (check(o2(start), last)) {
        fout << 2 << endl;
    } else if (check(o3(start), last)) {
        fout << 3 << endl;
    } else if (check(o4(start), last)) {
        fout << 4 << endl;
    } else if (check(o5(start), last) || check(o1(o5(start)), last) || check(o2(o5(start)), last) ||
               check(o3(o5(start)), last)) {
        fout << 5 << endl;
    } else if (check(start, last)) {
        fout << 6 << endl;
    } else {
        fout << 7 << endl;
    }


}
