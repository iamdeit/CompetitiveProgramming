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

using namespace std;


// Definitions.
#define VISITED 1
#define UNVISITED -1
#define MAX_N 101

// Typedefs.

typedef long long ll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;


//Global variables.

int dr[] = {1,1,0,-1,-1,-1, 0, 1}; // S,SE,E,NE,N,NW,W,SW
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // neighbors

char grid[MAX_N][MAX_N];
int rows, cols;

//Functions
int floodfill(int i, int j, char c1, char c2) {

    if(i < 0 || i >= rows || j < 0 || j >= cols) return 0;
    if(grid[i][j] != c1) return 0;
    grid[i][j] = c2;
    int res = 1;
    for(int index = 0; index < 8; index++) {
        res += floodfill(i+dr[index], j+dc[index], c1, c2);
    }
    return res;
}

//Main

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, i, j;
    string line;
    cin >> cases;
    getline(cin, line);
    getline(cin, line);
    while(cases--) {
        rows = 0;
        while(getline(cin, line), line[0] == 'W' || line[0] == 'L') {
            strcpy(grid[rows], line.c_str());
            rows++;
            cols = (int) line.size();
        }
        while(line[0] != '\0' && line[0] != '\n') {
            stringstream s(line);
            s >> i >> j;
            i--, j--;
            cout << floodfill(i, j, 'W', '.') << endl;
            floodfill(i, j, '.', 'W');
            getline(cin, line);
        }

        if(cases) cout << endl;
    }
    return 0;
}
