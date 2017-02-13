#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi dfsNum, dfsLow, S, visited;
vector<vector<ii>> graph;
int dfsNumberCounter, numSCC, V, E;

void tarjanSCC(int u) {
    dfsLow[u] = dfsNum[u] = dfsNumberCounter++;
    S.push_back(u);
    visited[u] = 1;
    for(int j = 0; j < graph[u].size(); j++) {
        ii v = graph[u][j];
        if (dfsNum[v.first] == UNVISITED) {
            tarjanSCC(v.first);
        }
        if (visited[v.first]) {
            dfsLow[u] = min(dfsLow[u], dfsLow[v.first]);
        }
    }

    if (dfsLow[u] == dfsNum[u]) {
        ++numSCC;                   // Number of ssc.
        while(1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            if (u == v) break;
        }
    }
}



int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int u, v, p;

    while(cin >> V >> E, V) {

        graph.assign(V, vector<ii>());

        for(int i = 0; i < E; i++) {
            cin >> u >> v >> p;
            u--;
            v--;
            graph[u].push_back({v, 1});
            if(p == 2) {
                graph[v].push_back({u, 1});
            }
        }

        dfsNum.assign(V, UNVISITED);
        dfsLow.assign(V, 0);
        visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;

        for (int i = 0; i < V; i++) {
            if (dfsNum[i] == UNVISITED) {
                tarjanSCC(i);
            }
        }

        if (numSCC == 1) cout << 1 << "\n";
        else cout << 0 << "\n";
    }



    return 0;
}