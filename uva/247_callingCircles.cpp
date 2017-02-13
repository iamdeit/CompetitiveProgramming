#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vi dfsNum, dfsLow, S, visited;
vector<vector<ii>> graph;
map<string, int> people;
vector<string> people2;
int dfsNumberCounter, V, E;

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
        while(1) {
            int v = S.back();
            S.pop_back();
            visited[v] = 0;
            cout << people2[v];
            if (u == v) {
                cout << "\n";
                break;
            }
            cout << ", ";
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    int t = 1, curr;
    string us, vs;

    while(cin >> V >> E, V) {

        if (t > 1) cout << "\n";

        graph.assign(V, vector<ii>());
        people2.assign(V, string());
        people2.clear();
        people.clear();

        curr = 1;

        for(int i = 0; i < E; i++) {
            cin >> us >> vs;

            if (!people[us]) {
                people2[curr-1] = us;
                people[us] = curr++;
            }

            if (!people[vs]) {
                people2[curr-1] = vs;
                people[vs] = curr++;
            }

            graph[people[us]-1].push_back({people[vs]-1, 1});
        }

        dfsNum.assign(V, UNVISITED);
        dfsLow.assign(V, 0);
        visited.assign(V, 0);
        dfsNumberCounter = 0;

        cout << "Calling circles for data set " << t++ << ":\n";

        for (int i = 0; i < V; i++) {
            if (dfsNum[i] == UNVISITED) {
                tarjanSCC(i);
            }
        }

    }

    return 0;
}