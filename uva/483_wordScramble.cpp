#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

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

/*
int main() {
    string str, res, temp;
    int limit;
    vector<string> v;
    while(getline(cin, str )) {
        if(str.size() > 0) {
            res = "";
            temp = "";
            v = split(str," ");
            limit = v.size()-1;
            for(int i = 0; i < limit; i++) {
                temp = v.at(i);
                res = res + string(temp.rbegin(), temp.rend()) + " ";
            }
            temp = v.at(limit);
            res = res + string(temp.rbegin(), temp.rend());
            v.clear();
            cout << res << "\n";
        }else {
            cout << "\n";
        }
    }
    return 0;
}*/

