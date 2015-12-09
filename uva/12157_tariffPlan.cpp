
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
    int cases, currCase = 1, calls, read, mile, juice;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &calls);
        mile = juice = 0;
        while(calls--) {
            scanf("%d", &read);
            mile += (((read/30)+1)*10);
            juice += (((read/60)+1)*15);
        }
        printf("Case %d: ", currCase++);
        if(mile == juice) printf("Mile Juice %d\n", mile);
        else if(mile < juice) printf("Mile %d\n", mile);
        else printf("Juice %d\n", juice);
    }
    return 0;
}