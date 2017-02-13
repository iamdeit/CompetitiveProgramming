
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
#include <queue>

using namespace std;


// Definitions.


// Typedefs.

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;


//Global variables.


//Functions

//

//Main

int main() {

    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned int a, sq;
    while(cin >> a, a) {
        sq = sqrt(a);
        if(sq*sq == a) cout << "yes\n";
        else cout << "no\n";
    }


    return 0;
}