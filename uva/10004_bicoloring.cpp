
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
bool bipartite;


//Functions

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

void bfs(int u) {
    queue<int> q;
    colors[u] = 1;
    q.push(u);
    bipartite = true;
    int node, v;
    while(!q.empty() && bipartite) {
        node = q.front();
        q.pop();
        for(int i = 0; i < graph[node].size(); i++) {
            v = graph[node][i];
            if(colors[v] == -1) {
                colors[v] = 1 - colors[node];
                q.push(v);
            }else if(colors[v] == colors[node]) {
                bipartite = false;
                break;
            }
        }
    }
}


//Main

int main() {

    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int edges, u, v;
    while(cin >> n, n) {
        graph.assign(n, vi());
        cin >> edges;
        while(edges--) {
            cin >> u >> v;
            addEdge(u, v);
        }
        memset(colors, -1, sizeof colors);
        bfs(0);
        if(bipartite) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";


    }
    return 0;
}

