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
    int cases, res;
    cin >> cases;
    char word[5];
    while(cases--) {
        scanf("%s", word);
        if(strlen(word) == 5) res = 3;
        else if( (word[0] == 'o' && word[1] == 'n') || (word[0] == 'o' && word[2] == 'e') || (word[1] == 'n' && word[2] == 'e')) res = 1;
        else res = 2;
        printf("%d\n", res);
    }
    return 0;
}