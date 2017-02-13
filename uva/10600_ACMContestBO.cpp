#include <bits/stdc++.h>

#define VISITED 1
#define UNVISITED -1
#define EXPLORED 2

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

vector< pair<double, ii> > edgeList;
pair <double, vector<ii> > bestMST;
ii flaggedEdge;
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

pair<double, int> kruskal(int V, int first) {
    double res = 0;
    int sizee = 0;
    if (first) {
        sort(edgeList.begin(), edgeList.end());
        UnionFind UF(V);
        for (auto edge : edgeList) {
            if (!UF.isSameSet(edge.second.first, edge.second.second)) {
                res += edge.first;
                sizee++;
                bestMST.second.push_back({edge.second.first, edge.second.second});
                UF.unionSet(edge.second.first, edge.second.second);
            }
        }
        bestMST.first = res;
    } else {
        UnionFind UF(V);
        for (auto edge : edgeList) {
            if (edge.second.first != flaggedEdge.first || edge.second.second != flaggedEdge.second) {
                if (!UF.isSameSet(edge.second.first, edge.second.second)) {
                    res += edge.first;
                    sizee++;
                    UF.unionSet(edge.second.first, edge.second.second);
                }
            }
        }
    }
    return {res, sizee};
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);


    int t, u, v, w;

    cin >> t;

    while(t--) {

        cin >> V >> E;
        edgeList.clear();
        bestMST = {0, vector<ii>()};

        for(int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            u--;
            v--;
            edgeList.push_back({w, {u, v}});
        }

        pair<double, int> firstMST = kruskal(V, 1);

        double secBest = INT_MAX;
        for (auto edge : bestMST.second) {
            flaggedEdge = {edge.first, edge.second};
            pair<double, int> secMST = kruskal(V, 0);
            if (secMST.second == firstMST.second) {
                secBest = min(secBest, secMST.first);
            }
        }

        cout << bestMST.first << " " << secBest << "\n";
    }

    return 0;
}