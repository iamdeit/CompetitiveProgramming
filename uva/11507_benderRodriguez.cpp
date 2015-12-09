
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
    freopen("input", "r", stdin);
    int len;
    string move, prev;
    while(scanf("%d", &len), len) {
        prev = "+x";
        while(--len) {
            cin >> move;
            if(move != "No") {
                if(prev == "+x") prev = move;
                else if(prev == "-x") {
                    if(move[0] == '-') prev = "+" + move.substr(1,1);
                    else prev = "-" + move.substr(1,1);
                }else if(prev == "+y") {
                    if(move == "+y") prev = "-x";
                    else if(move == "-y") prev = "+x";
                }else if(prev == "-y") {
                    if(move == "+y") prev = "+x";
                    else if(move == "-y") prev = "-x";
                }else if(prev == "+z") {
                    if(move == "+z") prev = "-x";
                    else if(move == "-z") prev = "+x";
                }else if(prev == "-z") {
                    if(move == "+z") prev = "+x";
                    else if(move == "-z") prev = "-x";
                }
            }
        }
        printf("%s\n", prev.c_str());
    }
    return 0;
}