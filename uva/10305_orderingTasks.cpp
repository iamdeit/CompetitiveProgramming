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
#define VISITED 1
#define UNVISITED -1

// Typedefs.

typedef long long ll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;


//Global variables.

int n, m;
vector<vi> graph;
vi visited;
vi vqueue;

//Functions

void addEdge(int u, int v) {
    graph[u].push_back(v);
}

void dfsTS(int u) {
    visited[u] = VISITED;
    for(auto neighbor : graph[u]) {
        if(visited[neighbor] == UNVISITED) dfsTS(neighbor);
    }
    vqueue.push_back(u);
}

void clearStructures() {
    graph.assign(n+1, vi());
    visited.assign(n+1, UNVISITED);
    vqueue.clear();
}


//Main

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    while(cin >> n >> m, n || m) {
        clearStructures();
        while(m--) {
            cin >> u >> v;
            addEdge(u, v);
        }

        for(int i = 1; i <= n; i++) {
            if(visited[i] == UNVISITED) dfsTS(i);
        }

        for(int i = n-1; i >= 0; i--) {
            cout << vqueue[i];
            if(!i) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
