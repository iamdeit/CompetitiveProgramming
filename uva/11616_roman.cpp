#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>

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


map<char, int> m;

void initMap() {
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
}

string generateStr(char c, short n) {
    string res = "";
    while(n--) res += c;
    return res;
}


int main() {

    initMap();
    char s[100], curr, next;
    string romanRes;
    short len, digit;
    int ascii, res;
    string str;
    while(scanf("%s", s) != EOF) {
        len = strlen(s);
        res = 0;
        romanRes = "";
        ascii = s[0];
        if(ascii > 57) {   // Es árabico
            for(int i = 0; i < len; i++) {
                curr = s[i];
                if(i == len-1) {
                    res += m[curr];
                }else {
                    next = s[i+1];
                    if( (curr == 'I' && (next == 'X' || next == 'V')) ||
                        (curr == 'X' && (next == 'L' || next == 'C')) ||
                        (curr == 'C' && (next == 'D' || next == 'M'))) {
                        res += (m[next] - m[curr]);
                        i++;
                    }else {
                        res += m[curr];
                    }
                }
            }
            printf("%d\n", res);
        }else {
            str = string(s);
            while(len > 0) {
                digit = str[0]-48;
                if(len > 3) {
                    romanRes += generateStr('M', digit);
                }else if(len > 2) {
                    if(digit < 4) romanRes += generateStr('C', digit);
                    else if(digit == 4) romanRes += "CD";
                    else if(digit < 9) romanRes += ('D'+generateStr('C', digit-5));
                    else romanRes += "CM";
                }else if(len > 1) {
                    if(digit < 4) romanRes += generateStr('X', digit);
                    else if(digit == 4) romanRes += "XL";
                    else if(digit < 9) romanRes += ('L'+generateStr('X', digit-5));
                    else romanRes += "XC";
                }else {
                    if(digit < 4) romanRes += generateStr('I', digit);
                    else if(digit == 4) romanRes += "IV";
                    else if(digit < 9) romanRes += ('V'+generateStr('I', digit-5));
                    else romanRes += "IX";
                }
                str = str.substr(1);
                len--;
            }
            printf("%s\n", romanRes.c_str());
        }
    }
    return 0;
}

