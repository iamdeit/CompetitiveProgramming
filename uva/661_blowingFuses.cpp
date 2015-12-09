
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
    int devices, m, capacity, index = 1, read, maxi, currVal;
    bool blown;
    while(scanf("%d %d %d", &devices, &m, &capacity), devices || m || capacity) {
        blown = false;
        maxi = -1;
        currVal = 0;
        bool state[devices];
        fill(state, state+devices, false);
        int values[devices];
        for(int i = 0; i < devices; i++) scanf("%d", &values[i]);
        for(int i = 0; i < m; i++) {
            scanf("%d", &read);
            if(!blown) {
                if(!state[read-1]) {
                    state[read-1] = true;
                    currVal += values[read-1];
                    if(currVal > capacity) blown = true;
                    else maxi = max(maxi, currVal);
                }else{
                    state[read-1] = false;
                    currVal -= values[read-1];
                }
            }
        }
        printf("Sequence %d\n", index++);
        if(blown) printf("Fuse was blown.\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", maxi);
        printf("\n");
    }
    return 0;
}