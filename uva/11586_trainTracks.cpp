
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>

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


int main() {
    int cases, male, female;
    string line;
    scanf("%d\n", &cases);
    while(cases--) {
        getline(cin, line);
        male = female = 0;
        vector<string> pieces = split(line, " ");
        for(int i = 0; i < pieces.size(); i++) {
            if(pieces[i][0] == 'M') male++;
            else female++;
            if(pieces[i][1] == 'M') male++;
            else female++;
        }
        if(male == female && pieces.size() > 1) printf("LOOP\n");
        else printf("NO LOOP\n");
    }
    return 0;
}