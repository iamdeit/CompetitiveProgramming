#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {
    long long res;
    int cases, n;
    cin >> cases;
    while(cases--) {
        cin >> n;
        res = (((((n*567)/9) + 7492) * 235)/47) - 498;
        cout << abs((res%100)/10) << endl;
    }
	return 0;
}

