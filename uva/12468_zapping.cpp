
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
    int c1, c2, up, down;
    while(scanf("%d %d", &c1, &c2), c1 != -1 || c2 != -1) {
        if(c1 < c2) {
            up = c2 - c1;
            down = abs((100+c1)-c2);
        }else {
            down = c1 - c2;
            up = abs((100+c2)-c1);
        }
        printf("%d\n", min(up, down));
    }
    return 0;
}