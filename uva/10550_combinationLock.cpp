#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    int c0, c1, c2, c3, res;
    while(cin >> c0 >> c1 >> c2 >> c3, c0 || c1 || c2 || c3) {
        res = 1080;
        if(c0 > c1) res += (c0-c1) * 9;
        else res += ((40+c0)-c1) * 9;
        if(c2 > c1) res += (c2-c1) * 9;
        else res += ((40+c2)-c1) * 9;
        if(c2 > c3) res += (c2-c3) * 9;
        else res += ((40+c2)-c3) * 9;
        cout << res << endl;
    }
	return 0;
}

