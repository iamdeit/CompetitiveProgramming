// Imports.

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;


// Definitions.

#define N_MAX 22


// Typedefs.
typedef long long ll;
typedef pair<int, int> pii;


//Global variables.

vector<pii> graph[N_MAX];
vector<pii> cities;
int memo[12][1 << 11];
int n, m, beepers, origX, origY;


// Functions.

void addEdge(int u, pii v) {
    graph[u].push_back(v);
}


int getDistance(pii u, pii v) {
    return abs(u.first - v.first) + abs(u.second - v.second);
}

int DP(int u, int bitmask) {
    if(bitmask == (1 << (beepers+1)) - 1) return graph[u][0].second;
    if(memo[u][bitmask] != -1) return memo[u][bitmask];

    int minPath = 2000000000, neighbor, weight;
    for(int i = 0; i < (int) graph[u].size(); i++) {
        neighbor = graph[u][i].first;
        weight = graph[u][i].second;
        if (!(bitmask & (1 << neighbor))) minPath = min(minPath, weight + DP(neighbor, bitmask | (1 << neighbor)));
    }
    memo[u][bitmask] = minPath;
    return memo[u][bitmask];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases;
    cin >> cases;
    while(cases--) {
        cin >> n >> m >> origX >> origY >> beepers;
        cities.push_back(make_pair(origX, origY));
        int tempX, tempY;
        for(int i = 0; i < beepers; i++) {
            cin >> tempX >> tempY;
            cities.push_back(make_pair(tempX, tempY));
        }
        for(int i = 0; i < (int)cities.size(); i++) {
            for(int j = 0; j < (int)cities.size(); j++) {
                if(i != j) {
                    addEdge(i, make_pair( j, getDistance(cities[i], cities[j]) ) );
                }
            }
        }
        memset(memo, -1, sizeof memo);
        cout << "The shortest path has length " << DP(0, 1) << endl;
        for(int i = 0; i < beepers+1; i++) graph[i].clear();
        cities.clear();
    }
    return 0;
}