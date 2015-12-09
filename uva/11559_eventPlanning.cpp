
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

    int n, budget, hotels, weeks, cost, beds;
    long long minimum, hotelCost;

    while(scanf("%d %d %d %d", &n, &budget, &hotels, &weeks) != EOF) {
        minimum = 999999999999999;
        while(hotels--) {
            scanf("%d", &cost);
            for(int i = 0; i < weeks; i++) {
                scanf("%d", &beds);
                hotelCost = cost*n;
                if(beds >= n && hotelCost <= budget) {
                    minimum = min(minimum, hotelCost);
                }
            }
        }
        if(minimum < 999999999999999) printf("%lld\n", minimum);
        else printf("stay home\n");
    }
    return 0;
}