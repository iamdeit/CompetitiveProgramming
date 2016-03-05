// Imports.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;


// Definitions.

#define MAX_N 53

// Typedefs.

typedef long long ll;

//Global variables.

ll memo[MAX_N][MAX_N];
int n, k, m;

//Functions

ll DP(int sum, int bars) {
    if(sum > n || bars > k) return 0;
    if(memo[sum][bars] != -1) return memo[sum][bars];
    if(sum == n && bars == k) return 1;
    ll res = 0;
    for(int i = 1; i <= m; i++) {
        res += DP(sum + i, bars + 1);
    }
    return memo[sum][bars] = res;
}

//Main

int main() {
    ios::sync_with_stdio(0);
    cin.tie();

    while(cin>>n>>k>>m) {
        memset(memo, -1, sizeof memo);
        cout << DP(0, 0) << "\n";
    }
    return 0;
}
