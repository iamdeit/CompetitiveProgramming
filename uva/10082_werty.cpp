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

map<char, char> map1;

void initMap() {
    map1['='] = '-';
    map1['-'] = '0';
    map1['0'] = '9';
    map1['1'] = '`';
    map1['2'] = '1';
    map1['3'] = '2';
    map1['4'] = '3';
    map1['5'] = '4';
    map1['6'] = '5';
    map1['7'] = '6';
    map1['8'] = '7';
    map1['9'] = '8';


    map1['\\'] = ']';
    map1[']'] = '[';
    map1['['] = 'P';
    map1['P'] = 'O';
    map1['O'] = 'I';
    map1['I'] = 'U';
    map1['U'] = 'Y';
    map1['Y'] = 'T';
    map1['T'] = 'R';
    map1['R'] = 'E';
    map1['E'] = 'W';
    map1['W'] = 'Q';

    map1['\''] = ';';
    map1[';'] = 'L';
    map1['L'] = 'K';
    map1['K'] = 'J';
    map1['J'] = 'H';
    map1['H'] = 'G';
    map1['G'] = 'F';
    map1['F'] = 'D';
    map1['D'] = 'S';
    map1['S'] = 'A';

    map1['/'] = '.';
    map1['.'] = ',';
    map1[','] = 'M';
    map1['M'] = 'N';
    map1['N'] = 'B';
    map1['B'] = 'V';
    map1['V'] = 'C';
    map1['C'] = 'X';
    map1['X'] = 'Z';
    map1[' '] = ' ';
}


int main() {

    initMap();
    string s,res;
    while(getline(cin, s)) {
        res = "";
        for(int i = 0; i < s.length(); i++) {
            res = res + map1[s.at(i)];
        }
        cout << res << "\n";
    }
    return 0;
}

