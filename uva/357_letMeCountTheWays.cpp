
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>


#define N_COINS 5
#define N_MAX 30005

using namespace std;

int coins[] = {1, 5, 10, 25, 50};
long long DP[N_MAX][N_COINS];

long long F(int val, int index) {
    if(index >= N_COINS || val < 0) return 0;
    if(!val) return DP[val][index] = 1;

    if(DP[val][index] != -1) return DP[val][index];
    DP[val][index] = F(val, index+1) + F(val-coins[index], index);
    return DP[val][index];
}


int main() {
    memset(DP, -1, sizeof(DP));
    F(30000, 0);
    int n;
    long long res;
    while(cin >> n) {
        res = DP[n][0];
        if(res == 1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else cout << "There are " << res << " ways to produce " << n << " cents change." << endl;
    }
    return 0;
}