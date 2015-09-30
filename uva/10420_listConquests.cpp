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
    map<string, set<string>> m;
    int n, SIZE;
    string s1,s2;
    scanf("%d",&n);
    set<string> sorted;
    int index = 0;
    while(n--) {
        cin >> s1;
        sorted.insert(s1);
        getline(cin, s2);
        m[s1].insert(s2);
    }
    for(string str : sorted) {
        printf("%s %d\n", str.c_str(), m[str].size());
    }
    return 0;
}

