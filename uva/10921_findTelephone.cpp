#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

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


    char convert(char c) {
        if(c == '-' || c == '0' || c == '1') return c;
        else if(c == 'A' || c == 'B' || c == 'C') return '2';
        else if(c == 'D' || c == 'E' || c == 'F') return '3';
        else if(c == 'G' || c == 'H' || c == 'I') return '4';
        else if(c == 'J' || c == 'K' || c == 'L') return '5';
        else if(c == 'M' || c == 'N' || c == 'O') return '6';
        else if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') return '7';
        else if(c == 'T' || c == 'U' || c == 'V') return '8';
        else return '9';
    }


int main() {
    string c;
    while(getline(cin, c)) {
        string res = "";
        for(int i = 0; i < c.size(); i++) {
            res += convert(c[i]);
        }
        res+="\n";
        printf("%s", res.c_str());
    }
    return 0;
}

