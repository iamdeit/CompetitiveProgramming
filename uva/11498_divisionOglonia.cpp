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
    int q, x, y, ix, iy;
    string res;
    while(scanf("%d", &q), q != 0) {
        scanf("%d%d", &x, &y);
        for(int i = 0; i < q; i++) {
            scanf("%d%d", &ix, &iy);
            if(ix == x || iy == y) res = "divisa";
            else if(ix > x) {
                if(iy > y) res = "NE";
                else res = "SE";
            }else {
                if(iy > y) res = "NO";
                else res = "SO";
            }
            printf("%s\n", res.c_str());
        }
    }
    return 0;
}

