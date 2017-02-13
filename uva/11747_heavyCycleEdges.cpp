#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector< pair<double, ii> > edgeList;
vi cycles;
int V, E;

class UnionFind {
private: vi p, rank;

public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) p[i] = i;
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i);
            int y = findSet(j);
            if (rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

void kruskal(int V) {
    sort(edgeList.begin(), edgeList.end());
    UnionFind UF(V);

    for (auto edge : edgeList) {
        if (!UF.isSameSet(edge.second.first, edge.second.second)) {
            UF.unionSet(edge.second.first, edge.second.second);
        } else {
            cycles.push_back(edge.first);
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    int t, u, v, w;

    while(cin >> V >> E, V) {

        edgeList.clear();
        cycles.clear();

        for(int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edgeList.push_back({w, {u, v}});
        }

        kruskal(V);

        sort(cycles.begin(), cycles.end());

        if (cycles.size() == 0) {
            cout << "forest\n";
        } else {
            for(int i = 0; i < cycles.size(); i++) {
                cout << cycles[i];
                if (i < cycles.size()-1) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}