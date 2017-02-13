#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector< pair<double, ii> > edgeList;
int V, r;
int xs[1002], ys[1002];

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

    int states = 1;
    double roads, railRoads;
    roads = railRoads = 0;
    UnionFind UF(V);

    for (auto edge : edgeList) {
        if (!UF.isSameSet(edge.second.first, edge.second.second)) {
            if (edge.first > r) {
                states++;
                railRoads += edge.first;
            } else {
                roads += edge.first;
            }

            UF.unionSet(edge.second.first, edge.second.second);
        }
    }

    cout << states << " " << round(roads) << " " << round(railRoads) << "\n";
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    int t, currCase = 1, x, y;

    cin >> t;

    while(t--) {

        edgeList.clear();

        cin >> V >> r;

        for(int i = 0; i < V; i++) {
            cin >> xs[i] >> ys[i];
        }

        for(int i = 0; i < V; i++) {
            for (int j = i+1; j < V; j++) {
                double dist = hypot(abs(xs[i]-xs[j]), abs(ys[i]-ys[j]));
                edgeList.push_back({dist, {i, j}});
            }
        }

        cout << "Case #" << currCase++ << ": ";
        kruskal(V);
    }

    return 0;
}