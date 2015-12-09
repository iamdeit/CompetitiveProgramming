
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
    int people, money, gifts, cost, index = 0;
    string name;
    while(scanf("%d", &people) != EOF) {
        if(index++) printf("\n");
        map<string, int> m;
        string nameOrder[people];
        for(int i = 0; i < people; i++) {
            cin >> name;
            nameOrder[i] = name;
            m[name] = 0;
        }
        for(int i = 0; i < people; i++) {
            cin >> name;
            scanf("%d %d", &money, &gifts);
            if(gifts) {
                cost = money/gifts;
                m[name] -= (money - (money - (cost*gifts)));
                while(gifts--) {
                    cin >> name;
                    m[name] += cost;
                }
            }
        }
        for(int i = 0; i < people; i++) {
            cout << nameOrder[i] << " " << m[nameOrder[i]] << endl;
        }
    }
    return 0;
}