#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


vi dfsNum, dfsLow, dfsParent;
int V, dfsNumberCounter, dfsRoot, rootChildren;
vector<ii> bridges;
vector<vector<ii>> graph;


void findBridges(int u) {
    dfsLow[u] = dfsNum[u] = dfsNumberCounter++;
    for(int j = 0; j < (int)graph[u].size(); j++) {
        ii v = graph[u][j];
        if (dfsNum[v.first] == UNVISITED) { // tree edge
            dfsParent[v.first] = u;
            if (u == dfsRoot) rootChildren++;

            findBridges(v.first);

            if (dfsLow[v.first] > dfsNum[u]) {
                bridges.push_back({min(u, v.first), max(v.first, u)});
            }

            dfsLow[u] = min(dfsLow[u], dfsLow[v.first]);
        } else if (v.first != dfsParent[u]) { // back edge
            dfsLow[u] = min(dfsLow[u], dfsNum[v.first]);
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);

    int u, v, nodeEdges;
    string tmp;


    while(cin >> V) {
        dfsNumberCounter = 0;
        dfsNum.assign(V, UNVISITED);
        dfsLow.assign(V, 0);
        dfsParent.assign(V, 0);
        graph.assign(V, vector<ii>());
        bridges.clear();


        for(int i = 0; i < V; i++) {
            cin >> u;
            cin >> tmp;
            nodeEdges = stoi(tmp.substr(1, tmp.size()-2));
            for(int j = 0; j < nodeEdges; j++) {
                cin >> v;
                graph[u].push_back({v, 1});
                graph[v].push_back({u, 1});
            }
        }

        for(int i = 0; i < V; i++) {
            if (dfsNum[i] == UNVISITED) {
                dfsRoot = i;
                rootChildren = 0;
                findBridges(i);
            }
        }

        cout << bridges.size() << " critical links\n";

        sort(bridges.begin(), bridges.end());

        for (auto bridge : bridges) {
            cout << bridge.first << " - " << bridge.second << "\n";
        }

        cout << "\n";
    }


    return 0;
}