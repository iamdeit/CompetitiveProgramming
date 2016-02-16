#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

vector<int> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<int> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(stoi(current));
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

int main() {
    int cases, a, b;
    string line;
    cin >> cases;
    getline(cin, line);
    while(cases--) {
        getline(cin, line);
        vector<int> v = split(line, " ");
        sort(v.rbegin(), v.rend());
        a = b = 0;
        for(auto i:v) {
            if(a <= b) a += i;
            else b += i;
        }
        a == b ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}