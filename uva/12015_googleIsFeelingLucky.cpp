
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
    int cases, currCase = 1, val, maxi, len;
    string url;
    scanf("%d", &cases);
    while(cases--) {
        map<int, vector<string>> m;
        maxi = -1;
        for(int i = 0; i < 10; i++) {
            cin >> url >> val;
            maxi = max(maxi, val);
            m[val].push_back(url);
        }
        printf("Case #%d:\n", currCase++);
        len = m[maxi].size();
        for(int i = 0; i < len; i++) {
            printf("%s\n", m[maxi][i].c_str());
        }
    }
    return 0;
}