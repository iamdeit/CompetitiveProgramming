
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
    int cases, n;
    long long size, animals, friendliness;
    double res;
    scanf("%d", &cases);
    while(cases--) {
        res = 0;
        scanf("%d", &n);
        while(n--) {
            scanf("%lld %lld %lld", &size, &animals, &friendliness);
            res += ( (size/(animals+0.0))*(friendliness)*animals );
        }
        long long printRes = (long long) round(res);
        printf("%lld\n", printRes);
    }
    return 0;
}