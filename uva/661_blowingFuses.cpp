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
    int n, m, c, temp, curr, greatest, index, seq;
    bool go;
    scanf("%d %d %d", &n, &m, &c);
    seq = 0;
    while(n != 0 || m != 0 || c != 0) {
        seq++;
        greatest = 0;
        curr = 0;
        bool on[n];
        go = true;
        int values[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &temp);
            values[i] = temp;
            on[i] = false;
        }
        for(int j = 0; j < m; j++) {
            scanf("%d", &index);
            if(go) {
                if(!on[index-1]) {
                    on[index-1] = true;
                    curr += values[index-1];
                    if(curr > greatest) greatest = curr;
                }else {
                    on[index-1] = false;
                    curr -= values[index-1];
                }
                if(curr > c) {
                    go = false;
                }
            }
        }
        printf("Sequence %d\n", seq);
        if(go) {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n", greatest);
        }else {
            printf("Fuse was blown.\n");
        }
        cout << endl;
        scanf("%d %d %d", &n, &m, &c);
    }
    return 0;
}*/