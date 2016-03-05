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
#define MAX_N 52

// Typedefs.

typedef long long ll;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;


//Global variables.

int dr[] = {-1, 1, 0, 0}; // N, S , W , E
int dc[] = {0, 0, -1, 1}; // N, S , W , E

char gold = 'G';
char trap = 'T';
char wall = '#';
char normal = '.';

char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int rows, cols, finalRes;

//Functions

bool isSafe(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) return true;
    else return grid[i][j] != trap;
}

void floodfill(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols) return;
    if(visited[i][j] == 1 || grid[i][j] == trap || grid[i][j] == wall) return;
    visited[i][j] = 1;
    if(grid[i][j] == gold) finalRes++;
    bool safe = true;
    for(int index = 0; index < 4 && safe; index++) {
        safe = isSafe(i + dr[index], j + dc[index]);
    }
    if(safe) {
        for(int index = 0; index < 4; index++)
            floodfill(i+dr[index], j+dc[index]);
    }
}

//Main

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int startI, startJ;
    while(cin >> cols >> rows) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'P') {
                    startI = i;
                    startJ = j;
                    grid[i][j] = normal;
                }
            }
        }
        memset(visited, -1, sizeof visited);
        finalRes = 0;
        floodfill(startI, startJ);
        cout << finalRes << endl;
    }

    return 0;
}
