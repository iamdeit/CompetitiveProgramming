#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>


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


    int n, res, r;

    while(scanf("%d",&n) != EOF) {
        bitset<32> bs(n);
        bitset<32> res;
        short index = 24;

        for(int i = 0; i < 32; i++) {
            if(i == 8) index = 16;
            else if(i == 16) index = 8;
            else if(i == 24) index = 0;
            res[index++] = bs[i];
        }
        r = (int)(res.to_ulong());
        printf("%d converts to %d\n",n, r);
    }
    return 0;
}
/*
int main() {


    int n, res;

    while(scanf("%d",&n) != EOF) {
        bitset<32> bs(n);
        string s = bs.to_string();
        string reversed = s.substr(24,8)+s.substr(16,8)+s.substr(8,8)+s.substr(0, 8);
        bitset<32> bs2(reversed);
        res = static_cast<int>(bs2.to_ulong());
        printf("%d converts to %d\n",n, res);
    }
    return 0;
}*/