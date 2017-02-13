
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
vector<vi> graph;
int colors[202];


//Functions

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int bfs(int u) {
    queue<int> q;
    colors[u] = 0;
    int colorsCount[2] = {1, 0};
    q.push(u);
    bool bipartite = true;
    int currNode, v;
    while(!q.empty() && bipartite) {
        currNode = q.front(); q.pop();
        for(int i = 0; i < graph[currNode].size(); i++) {
            v = graph[currNode][i];
            if(colors[v] == -1) {
                colors[v] = 1 - colors[currNode];
                colorsCount[colors[v]]++;
                q.push(v);
            }else if(colors[v] == colors[currNode]) {
                bipartite = false;
                break;
            }
        }
    }
    if(!bipartite) return -1;
    else {
        if(colorsCount[0] && colorsCount[1]) return min(colorsCount[0], colorsCount[1]);
        else return max(colorsCount[0], colorsCount[1]);
    }
}


//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, edges, u, v;
    cin >> cases;
    while(cases--) {
        cin >> n >> edges;
        graph.assign(n, vi());
        for(int i = 0; i < edges; i++) {
            cin >> u >> v;
            addEdge(u, v);
        }

        memset(colors, -1, sizeof colors);
        int res = 0, partial;
        for(int i = 0; i < n; i++) {
            if(colors[i] == -1) {
                partial = bfs(i);
                if(partial == -1) {
                    res = -1;
                    break;
                }else {
                    res += partial;
                }
            }
        }
        cout << res << "\n";
    }

    return 0;
}

