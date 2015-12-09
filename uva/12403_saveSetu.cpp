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
    int cases, money, res = 0;
    string line;
    cin >> cases;
    while(cases--) {
        cin >> line;
        if(line == "donate") {
            scanf("%d", &money);
            res += money;
        } else {
            printf("%d\n", res);
        }
    }
    return 0;
}