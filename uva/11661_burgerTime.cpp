
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
    int n, len, mini, acum;
    char highway[2000010], prev;
    bool flag;
    while(scanf("%d", &n), n) {
        scanf("%s", highway);
        len = strlen(highway);
        mini = 99999999;
        flag = false;
        acum = 0;
        for(int i = 0; i < len; i++) {
            if(highway[i] == 'Z') {
                mini = 0;
                break;
            }else {
                if(!flag && highway[i] != '.') {
                    prev = highway[i];
                    acum = 1;
                    flag = true;
                }else {
                    if(highway[i] != '.') {
                        if(highway[i] != prev) {
                            mini = min(mini, acum);
                            acum = 1;
                            prev = highway[i];
                        }else {
                            acum = 1;
                        }
                    }else acum++;
                }
            }
        }
        printf("%d\n", mini);
    }
    return 0;
}