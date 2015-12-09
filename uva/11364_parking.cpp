#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    int cases, n, minimum, maximum, read;
    cin >> cases;
    while(cases--) {
        minimum = 10000000;
        maximum = -1000000;
        cin >> n;
        while(n--) {
            cin >> read;
            if(read > maximum) maximum = read;
            if(read < minimum) minimum = read;
        }
        cout << (maximum-minimum)*2 << endl;
    }
	return 0;
}

