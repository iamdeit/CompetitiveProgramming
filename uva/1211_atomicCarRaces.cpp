
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

using namespace std;


// Definitions.


// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.

int arr[102];
long double memo[10002][102];
long double t[10002];
int n;
long double b, r, v, e, f;

//Functions




long double getTime(int from, int to) {
    int x = 0;
    long double res = 0;
    while(x <= (to-from)) {
        if(x < r) res += 1.0/(v - f * (r - (x*1.0)));
        else res +=  1.0/(v - e * ((x*1.0) - r));
        x++;
    }
    return res;
}

long double DP(int last, int i) {
    if(i >= n) return 0;
    if(i == n-1) {
        if(memo[last][i] != -1) return memo[last][i];
        return memo[last][i] = t[arr[i]-last-1];
    }
    if(memo[last][i] != -1) return memo[last][i];
    int distance = arr[i]-last-1;

    long double minTime = min( DP(last, i+1), b + t[distance] + DP(arr[i], i+1));
    return memo[last][i] = minTime;
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n, n) {
        for(int i = 0; i < n; i++) cin >> arr[i];
        cin >> b >> r >> v >> e >> f;
        long double tempTime = 0;
        for(int x = 0; x <= arr[n-1]; x++) {
            tempTime += x < r ? 1.0/(v - f * (r - (x*1.0))) : 1.0/(v - e * ((x*1.0) - r));
            t[x] = tempTime;
        }
        for(int i = 0; i < 10002; i++) fill(memo[i], memo[i]+n, -1.0);
        cout << fixed << setprecision(4)<<DP(0, 0) << "\n";
    }
    return 0;
}