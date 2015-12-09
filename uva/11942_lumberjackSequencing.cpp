
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
    vector<int> v(10);
    int cases;
    scanf("%d", &cases);
    printf("Lumberjacks:\n");
    while(cases--) {
        for(int i = 0; i < 10; i++) scanf("%d", &v[i]);
        if(is_sorted(v.begin(), v.end()) || is_sorted(v.rbegin(), v.rend())) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}