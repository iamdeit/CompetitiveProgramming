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
#include <arpa/inet.h>

using namespace std;


// Definitions.

#define MAX_N 100005

// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.

int n;
map<char, int> tasks;
vector<vi> graph;
int weights[28];
int dist[28];
bool visited[28];

//Functions

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

void fillMap() {
    for(int i = 0; i < 27; i++) {
        tasks[(char)(65+i)] = i;
    }
}


void addEdge(int u, int v) {
    graph[u].push_back(v);
}

int DP(int u) {
    if(dist[u] != -1) return dist[u];
    visited[u] = true;
    int lp = 0;
    for(int i = 0; i < graph[u].size(); i++) {
        lp = max(lp, DP(graph[u][i]));
    }
    return dist[u] = lp+weights[u];
}

//Main

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fillMap();
    int cases;
    cin >> cases;
    string line;
    getline(cin, line);
    getline(cin, line);
    while(cases--) {
        n = 0;
        graph.assign(27, vi());
        fill(visited, visited+28, false);
        memset(dist, -1, sizeof dist);
        while(getline(cin, line), line.size() > 0) {
            n++;
            vector<string> input = split(line, " ");
            int u = tasks[input[0][0]];
            int weight = stoi(input[1]);
            weights[u] = weight;
            if(input.size() == 3) {
                for(auto c : input[2]) {
                    int v = tasks[c];
                    addEdge(v, u);
                }

            }
            line = "";
        }
        int lp = -1;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                lp = max(lp, DP(i));
            }
        }
        cout << lp;
        if(cases) cout << "\n";
    }
    return 0;
}