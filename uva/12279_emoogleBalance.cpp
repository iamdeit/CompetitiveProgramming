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
    //freopen("input", "r", stdin);
    int n, index = 0, res, read;
    while(scanf("%d", &n), n) {
        index++;
        res = 0;
        while(n--) {
            scanf("%d", &read);
            if(read) res++;
            else res--;
        }
        printf("Case %d: %d\n", index, res);
    }
    return 0;
}