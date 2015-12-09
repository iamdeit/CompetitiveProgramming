
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
    int cases, ins, pos, index;
    string line;
    scanf("%d", &cases);
    while(cases--) {
        pos = 0;
        scanf("%d", &ins);
        int insArr[ins];
        for(int i = 1; i <= ins; i++) {
            cin >> line;
            if(line == "RIGHT") insArr[i] = 1;
            else if(line == "LEFT") insArr[i] = -1;
            else {
                cin >> line;
                scanf("%d", &index);
                insArr[i] = insArr[index];
            }
            pos += insArr[i];
        }
        printf("%d\n", pos);
    }
    return 0;
}