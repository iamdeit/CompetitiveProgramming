#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    int queries, divX, divY, x, y;
    string res;
    while(cin >> queries, queries) {
        cin >> divX >> divY;
        while(queries--) {
            cin >> x >> y;
            if(x == divX || y == divY) res = "divisa";
            else {
                if(x < divX) {
                    if(y > divY) res = "NO";
                    else res = "SO";
                }else {
                    if(y > divY) res = "NE";
                    else res = "SE";
                }
            }
            cout << res << endl;
        }
    }
	return 0;
}

