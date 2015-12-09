
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
    int cases, currCase = 1, maxi, n, speed;
    scanf("%d", &cases);
    while(cases--) {
        maxi = -1;
        scanf("%d", &n);
        while(n--) {
            scanf("%d", &speed);
            maxi = max(maxi, speed);
        }
        printf("Case %d: %d\n", currCase++, maxi);
    }
    return 0;
}