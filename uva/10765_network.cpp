#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;


vi dfsNum, dfsLow, dfsParent;
int V, dfsNumberCounter, dfsRoot, rootChildren, res;
vi articulationPoints;
vector<vector<ii>> graph;


void findArticulationPoints(int u) {
    dfsLow[u] = dfsNum[u] = dfsNumberCounter++;
    for(int j = 0; j < (int)graph[u].size(); j++) {
        ii v = graph[u][j];
        if (dfsNum[v.first] == UNVISITED) { // tree edge
            dfsParent[v.first] = u;
            if (u == dfsRoot) rootChildren++;

            findArticulationPoints(v.first);

            if (dfsLow[v.first] >= dfsNum[u]) {
                articulationPoints[u]++;
            }

            dfsLow[u] = min(dfsLow[u], dfsLow[v.first]);
        } else if (v.first != dfsParent[u]) { // back edge
            dfsLow[u] = min(dfsLow[u], dfsNum[v.first]);
        }
    }
}

vector<string> split(string str,string sep) {
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL) {
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}




int main() {
    ios::sync_with_stdio(0);
    //cin.tie(0);

    int u, v, nodeEdges;
    string tmp;


    while(cin >> V, V) {
        res = 0;
        dfsNumberCounter = 0;
        dfsNum.assign(V, UNVISITED);
        dfsLow.assign(V, 0);
        articulationPoints.assign(V, 0);
        dfsParent.assign(V, 0);
        graph.assign(V, vector<ii>());

        getline(cin, tmp);
        while(getline(cin, tmp), tmp != "0") {
            vector<string> connections = split(tmp, " ");
            u = stoi(connections[0])-1;
            for(int i = 1; i < connections.size(); i++) {
                v = stoi(connections[i])-1;
                graph[u].push_back({v, 1});
                graph[v].push_back({u, 1});
            }
        }

        for(int i = 0; i < V; i++) {
            if (dfsNum[i] == UNVISITED) {
                dfsRoot = i;
                rootChildren = 0;
                findArticulationPoints(i);
                articulationPoints[dfsRoot] = rootChildren > 1;
            }
        }

        for(auto ap : articulationPoints) {
            if (ap) res++;
        }
        cout << res << "\n";
    }


    return 0;
}