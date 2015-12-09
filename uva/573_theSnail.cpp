
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
    int h, down, perc, state, currDay;
    double up, currH, fatigue;
    while(scanf("%d %lf %d %d", &h, &up, &down, &perc), h) {
        fatigue = up*(perc/100.0);
        state = currH = 0;
        currDay = 1;
        while(!state) {
            currH += up;
            if(currH > h) state = 1;
            else {
                currH -= down;
                if(currH < 0) state = 2;
                else {
                    up -= fatigue;
                    if(up < 0) up = 0;
                    currDay++;
                }
            }
        }
        if(state == 1) printf("success on day %d\n", currDay);
        else printf("failure on day %d\n", currDay);
    }
    return 0;
}