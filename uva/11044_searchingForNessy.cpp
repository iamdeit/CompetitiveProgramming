#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    int cases, n, m;
    cin >> cases;
    while(cases--) {
        cin >> n >> m;
        cout << (n/3)*(m/3) << endl;
    }
	return 0;
}

