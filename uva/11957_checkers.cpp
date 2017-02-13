
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
#include <iomanip>
#include <bitset>
#include <queue>

using namespace std;


// Definitions.

#define MOD 1000007

// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.

int n;
char mat[102][102];
ll memo[102][102];


//Functions

bool isInvalid(int x, int y) {
    return (x >= n || x < 0 || y >= n || y < 0);
}

ll DP(int x, int y) {
    if(isInvalid(x, y)) return 0;
    if(!x && mat[x][y] == '.') return 1;
    if(memo[x][y] != -1) return memo[x][y];

    ll res = 0;
    int mvX, mvY;

    mvX = x-1;
    mvY = y-1;
    if(!isInvalid(mvX, mvY) && mat[mvX][mvY] == '.') {
        res += DP(mvX, mvY)%MOD;
    }else{
        mvX = x-2; mvY = y-2;
        if(!isInvalid(mvX, mvY) && mat[mvX][mvY] == '.') res += DP(mvX, mvY)%MOD;
    }

    mvX = x-1;
    mvY = y+1;
    if(!isInvalid(mvX, mvY) && mat[mvX][mvY] == '.') {
        res += DP(mvX, mvY)%MOD;
    }else{
        mvX = x-2; mvY = y+2;
        if(!isInvalid(mvX, mvY) && mat[mvX][mvY] == '.') res += DP(mvX, mvY)%MOD;
    }

    return memo[x][y] = res%MOD;
}

//Main

int main() {

    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, x, y;
    char read;
    cin >> cases;
    for(int curr = 1; curr <= cases; curr++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> read;
                mat[i][j] = read;
                if(read == 'W') {
                    x = i;
                    y = j;
                }
            }
        }
        memset(memo, -1, sizeof memo);
        ll res;
        if(!x) res = 1;
        else res = DP(x, y)%MOD;
        cout << "Case " << curr << ": " << res << "\n";
    }
    return 0;
}

