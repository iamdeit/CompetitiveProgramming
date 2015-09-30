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



int main() {
    int t, size;
    string s1, s2;
    scanf("%d", &t);
    getchar();
    while(t--) {
        getline(cin, s1);
        getline(cin, s1);
        vector<string> indexArr = split(s1, " ");
        size = indexArr.size();
        string res[size];
        getline(cin, s2);
        vector<string> secArr = split(s2, " ");
        for(int i = 0; i < size; i++) {
            res[stoi(indexArr[i])-1] = secArr[i];
        }
        for(int i = 0; i < size; i++) {
            printf("%s\n",res[i].c_str());
        }
        if(t > 0) printf("\n");
    }
    return 0;
}

