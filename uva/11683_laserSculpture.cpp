
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
    int n, m, res;
    bool prev;
    while(scanf("%d %d", &n, &m), n || m) {
        res = 0;
        int colH[m];
        for(int i = 0; i < m; i++) scanf("%d", &colH[i]);
        for(int i = 0; i < n; i++) {
            prev = false;
            for(int j = 0; j < m; j++) {
                if(prev) {
                    if(i >= (n-colH[j])) {
                        prev = false;
                    }
                }else {
                    if(i < (n-colH[j])) {
                        prev = true;
                        res++;
                    }
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}