
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
    int cases, n, m, res;
    char c;
    cin >> cases;
    while(cases--) {
        cin >> c >> m >> n;
        if(c == 'r' || c == 'Q') res = min(n, m);
        else if(c == 'k') res = (((m + 1)/2) * ((n + 1)/2)) + (((m)/2) * ((n)/2));
        else res = (((m + 1)/2) * ((n + 1)/2));
        printf("%d\n", res);
    }
    return 0;
}