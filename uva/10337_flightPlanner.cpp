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

#define MAX_N 1002
#define INF 100000000

// Typedefs.

typedef long long ll;

//Global variables.

int destiny;
int windArray[11][MAX_N];
int memo[11][MAX_N];

//Functions

int DP(int altitude, int currDist) {
    if(altitude < 0 || altitude > 9) return INF;
    if(currDist == destiny) return !altitude ? 0 : INF;
    if(memo[altitude][currDist] != -1) return memo[altitude][currDist];

    int ws = windArray[altitude][currDist];
    int climb = 60 - ws + DP(altitude+1, currDist+1);
    int hold = 30 - ws + DP(altitude, currDist+1);
    int sink = 20 - ws + DP(altitude-1, currDist+1);
    return memo[altitude][currDist] = min(climb, min(hold, sink));
}


//Main

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> destiny;
        destiny /= 100;
        for(int i = 9; i >= 0; i--) {
            for(int j = 0; j < destiny; j++) {
                cin >> windArray[i][j];
            }
        }
        memset(memo, -1, sizeof memo);
        cout << DP(0, 0) << "\n\n";
    }
    return 0;
}

