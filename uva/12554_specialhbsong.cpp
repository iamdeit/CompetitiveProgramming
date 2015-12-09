
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
    int n, nameIndex = 0;
    string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia",
                    "Happy", "birthday", "to", "you"};
    scanf("%d", &n);
    string names[n];
    for(int i = 0; i < n; i++) cin >> names[i];
    bool flag = false;
    while(!flag) {
        for(int i = 0; i < 16; i++) {
            printf("%s: %s\n", names[nameIndex].c_str(), song[i].c_str());
            if(nameIndex == n-1) {
                flag = true;
            }
            nameIndex = (nameIndex+1)%n;
        }
    }

    return 0;
}