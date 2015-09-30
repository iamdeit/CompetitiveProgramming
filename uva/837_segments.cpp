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

struct line {
    float x1;
    float x2;
    float r;
    line(){};
    line(float xx1, float xx2, float r1) {
        x1 = xx1;
        x2 = xx2;
        r = r1;
    }
};

bool med(float x1, float x2, float p) {
    return (p > x1 && p < x2);
}

bool bet(float x1, float x2, float x3, float x4) {
    float ma = x3;
    float mi = x4;
    if(mi > ma) {
        ma = x4;
        mi = x3;
    }
    if(x1 == x2) {
        return ( (mi < x1 && ma > x2) || (mi == x1) );
    }else {
        return ( (mi == x1) || (ma == x2) || (med(x1, x2, mi)) || (med(x1, x2, ma)) || (mi < x1 && ma > x2));
    }
}


int main() {
    int cases, nl;
    string blank;
    line ltemp;
    float x1, x2, y1, y2, r, temp;
    scanf("%d",&cases);
    getline(cin, blank);
    vector<float> v;
    while(cases-- > 0) {
        v.clear();
        getline(cin, blank);
        scanf("%d", &nl);
        line arr[nl];
        for(int i = 0; i < nl; i++) {
            scanf("%f %f %f %f %f", &x1, &y1, &x2, &y2, &r);
            v.push_back(x1);
            v.push_back(x2);
            arr[i] = line(x1,x2,r);
        }
        sort(v.begin(), v.end());
        int index = 0;
        int limit = nl*2;
        printf("%d\n", (nl*2)+1);
        printf("-inf %.3f 1.000\n", v[index]);
        while(index < limit-1) {
            temp = 1;
            for(int i = 0; i < nl; i++) {
                ltemp = arr[i];
                if(bet(v[index], v[index+1], ltemp.x1, ltemp.x2)) temp *= ltemp.r;
            }
            printf("%.3f %.3f %.3f\n", v[index], v[index+1], temp);
            index++;
        }
        printf("%.3f +inf 1.000\n", v[index]);
        if(cases != 0) printf("\n");
    }
    return 0;
}

