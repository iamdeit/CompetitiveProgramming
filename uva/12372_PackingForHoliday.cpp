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

int main() {
    int cases, index = 0, l, w, h;
    string res;
    cin >> cases;
    while(cases--) {
        index++;
        scanf("%d %d %d", &l, &w, &h);
        if(l <= 20 && w <= 20 && h <= 20) res = "good";
        else res = "bad";
        cout << "Case " << index << ": " << res << endl;
    }
    return 0;
}