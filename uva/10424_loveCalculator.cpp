
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

int f(int n) {
    if(n < 10) return n;
    else {
        int res = 0;
        while(n > 0) {
            res += n%10;
            n /= 10;
        }
        return f(res);
    }
}

int sumName(string name) {
    int len = name.size();
    int res = 0, add;
    for(int i = 0; i < len; i++) {
        add = 0;
        if(name[i] >= 65 && name[i] <= 90) add = (name[i]-64);
        else if(name[i] >= 97 && name[i] <= 122) add = (name[i]-96);
        res += add;
    }
    return res;
}

int main() {
    string name1, name2;
    int sumName1, sumName2;
    double res;
    while(getline(cin, name1)) {
        getline(cin, name2);
        sumName1 = f(sumName(name1));
        sumName2 = f(sumName(name2));
        if(!sumName1 || !sumName2) res = 0.0;
        else res = (min(sumName1, sumName2)/(max(sumName1, sumName2)+0.0))*100.0;
        printf("%.2lf %\n", res);
    }
    return 0;
}