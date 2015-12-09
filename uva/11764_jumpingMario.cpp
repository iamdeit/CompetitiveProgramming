
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
    int cases, currCase = 1, walls, h, l, currWall, readWall;
    scanf("%d", &cases);
    while(cases--) {
        h = l = 0;
        scanf("%d", &walls);
        scanf("%d", &currWall);
        while(--walls) {
            scanf("%d", &readWall);
            if(readWall > currWall) h++;
            else if(readWall < currWall) l++;
            currWall = readWall;
        }
        printf("Case %d: %d %d\n", currCase++, h, l);
    }
    return 0;
}