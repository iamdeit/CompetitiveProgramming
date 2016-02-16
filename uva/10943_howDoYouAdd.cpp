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

int DP[200][200];
int MOD = 1000000;

int C() {
    for(int i = 0; i < 200; i++) DP[i][0] = 1;
    for(int i = 1; i < 200; i++) {
        for(int j = 0; j <= i; j++) {
            if(i == j) DP[i][j] = 1;
            else DP[i][j] = (DP[i-1][j-1] + DP[i-1][j])%MOD;
        }
    }
}

int main() {
    C();
    int n, k;
    while(cin >> n >> k, n && k) {
        cout << DP[n+k-1][n] << endl;
    }
    return 0;
}