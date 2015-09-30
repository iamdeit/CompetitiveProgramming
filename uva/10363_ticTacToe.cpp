#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

char mat[3][3];
bool xwin;
bool ywin;

void clearMat() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            mat[i][j] = 0;
        }
    }
}



int winner() {
    int res = 0;
    for(int i = 0; i < 3; i++) {
        if(mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) {
            if(mat[i][0] != '.') {
                res++;
                if(mat[i][0] == 'X') xwin = true;
                else ywin = true;
            }

        }
    }
    for(int i = 0; i < 3; i++) {
        if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) {
            if(mat[0][i] != '.') {
                res++;
                if (mat[0][i] == 'X') xwin = true;
                else ywin = true;
            }
        }
    }
    if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) {
        if(mat[0][0] != '.') {
            res++;
            if (mat[0][0] == 'X') xwin = true;
            else ywin = true;
        }
    }
    if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]) {
        if(mat[0][2] != '.') {
            res++;
            if (mat[0][2] == 'X') xwin = true;
            else ywin = true;
        }
    }
    return res;
}

int countItems(char c) {
    int res = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(mat[i][j] == c) {
                res++;
            }
        }
    }
    return res;
}

int main() {

    int cases, countx,county, winnerRes;
    bool res;
    string s;
    scanf("%d\n", &cases);
    while(cases--) {
        res = false;
            cin >> s;
            mat[0][0] = s.at(0);
            mat[0][1] = s.at(1);
            mat[0][2] = s.at(2);

            cin >> s;
            mat[1][0] = s.at(0);
            mat[1][1] = s.at(1);
            mat[1][2] = s.at(2);
            cin >> s;
            mat[2][0] = s.at(0);
            mat[2][1] = s.at(1);
            mat[2][2] = s.at(2);

        xwin = false;
        ywin = false;
        countx = countItems('X');
        county = countItems('O');
        winnerRes = winner();

        if(winnerRes == 0) {
            if(county == countx || county == countx-1) res = true;
        }else if(winnerRes == 1) {
            if(xwin && (countx == county+1)) res = true;
            else if(ywin && (countx == county)) res = true;
        }else {
            if(winnerRes == 2) {
                if(xwin && !ywin && countx == 5 && county == 4) res = true;
            }else {
                res = false;
            }
        }

        if(res) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}

