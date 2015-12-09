
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

    int b, n, bd, bc, val;
    bool flag;
    while(scanf("%d %d", &b, &n), b || n) {
        flag = true;
        int arr[b];
        for(int i = 0; i < b; i++) scanf("%d", &arr[i]);
        while(n--) {
            scanf("%d %d %d", &bd, &bc, &val);
            arr[bd-1] -= val;
            arr[bc-1] += val;
        }
        for(int i = 0; i < b; i++) {
            if(arr[i] < 0) {
                flag = false;
                break;
            }
        }
        if(flag) printf("S\n");
        else printf("N\n");
    }
    return 0;
}