
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
    char number[1000010], c;
    bool flag;
    int queries, readI, readJ, init, end, len, index = 1;
    while(scanf("%s %d", number, &queries) != EOF) {
        printf("Case %d:\n", index++);
        while(queries--) {
            flag = true;
            scanf("%d %d", &readI, &readJ);
            init = min(readI, readJ);
            end = max(readI, readJ);
            if(number[init] == '1') c = '0';
            else c = '1';
            for(int i = init+1; i <= end && flag; i++) {
                if(number[i] == c) flag = false;
            }
            if(flag) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}