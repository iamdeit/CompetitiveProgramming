
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
    int req, p, maxiMetReq, bestPrice, metReq, index = 0;
    double price;
    string line, bestProp;
    while(scanf("%d %d\n", &req, &p), req || p) {
        if(index++) printf("\n");
        maxiMetReq = -1;
        bestPrice = 99999999;
        for(int i = 0; i < req; i++) getline(cin, line);
        for(int i = 0; i < p; i++) {
            getline(cin, line);
            scanf("%lf %d\n", &price, &metReq);
            if((metReq == maxiMetReq && price < bestPrice) || (metReq > maxiMetReq)) {
                maxiMetReq = metReq;
                bestPrice = price;
                bestProp = line;
            }
            while(metReq--) getline(cin, line);
        }
        printf("RFP #%d\n", index);
        printf("%s\n", bestProp.c_str());
    }
    return 0;
}