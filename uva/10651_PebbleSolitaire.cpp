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

#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define MOD 1000007
#define EPSILON 0.000000001

// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.

int memo[4097];
int n = 12;

//Functions

int countPebbles(int board) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        if((board & (1<<i)) != 0) res++;
    }
    return res;
}

int DP(int board) {
    if(memo[board] != -1) return memo[board];
    int minPebbles = countPebbles(board), modBoard;
    for(int i = 0; i < 12; i++) {
        if((board & (1<<i)) != 0) {
            if(i <= 9) {
                if( ((board & (1<<(i+1))) != 0) && (((board & (1<<(i+2))) == 0)) ) {
                    modBoard = board | (1<<(i+2));      // Turn i+2 bit on.
                    modBoard &= ~(1 << i);       // Turn i bit off.
                    modBoard &= ~(1<<(i+1));   // Turn i+1 bit off.
                    minPebbles = min(minPebbles, DP(modBoard));
                }
            }
            if(i >= 2) {
                if( ((board & (1<<(i-1))) != 0) && (((board & (1<<(i-2))) == 0)) ) {
                    modBoard = board | (1<<(i-2));      // Turn i-2 bit on.
                    modBoard &= ~(1 << i);       // Turn i bit off.
                    modBoard &= ~(1<<(i-1));   // Turn i-1 bit off.
                    minPebbles = min(minPebbles, DP(modBoard));
                }
            }
        }
    }
    return memo[board] = minPebbles;
}

int getMask(string s) {
    int mask = 0;
    for(int i = 0; i < 12; i++) {
        if(s[11-i] == 'o') mask = mask | (1<<i);
    }
    return mask;
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, board;
    string line;
    cin >> cases;
    memset(memo, -1, sizeof memo);
    while(cases--) {
        cin >> line;
        board = getMask(line);
        cout << DP(board) << "\n";
    }
    return 0;
}