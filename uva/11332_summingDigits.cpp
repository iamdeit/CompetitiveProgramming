
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


long long f(long long n) {
    if(n < 10) return n;
    else {
        long long res = 0;
        while(n > 0) {
            res += n%10;
            n /= 10;
        }
        return f(res);
    }
}

int main() {
    long long n;
    while(scanf("%lld", &n), n != 0) {
        printf("%lld\n", f(n));
    }
    return 0;
}