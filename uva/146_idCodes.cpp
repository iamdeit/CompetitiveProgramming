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

    char s[1000];
    int len;
    while(scanf("%s", s), s[0] != '#') {
        len = strlen(s);
        if(next_permutation(s,s+len)) {
            printf("%s\n",s);
        }else {
            printf("No Successor\n");
        }
    }
    return 0;
}

