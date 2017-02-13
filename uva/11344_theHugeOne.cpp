
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

string n;
int len;

//Functions

bool isDivisible(int div) {
    int num = 0;
    for (int i=0; i < len; i++) {
        num = num*10 + n[i]-48;
        num %= div;
    }
    return !num;
}


//Main

int main() {

    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cases, divisors, read;
    bool res;
    cin >> cases;
    while(cases--) {
        cin >> n;
        len = n.size();
        cin >> divisors;
        res = true;
        while(divisors--) {
            cin >> read;
            res = res && isDivisible(read);
        }

        if(res) cout << n << " - Wonderful.\n";
        else cout << n << " - Simple.\n";
    }


    return 0;
}