
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int cases, cols, y1, y2, diff;
    bool flag;
    cin >> cases;
    while(cases--) {
        cin >> cols;
        flag = true;
        if(cols) {
            cin >> y1 >> y2;
            cols--;
            diff = abs(y1-y2);
        }
        while(cols--) {
            cin >> y1 >> y2;
            if(diff != abs(y1-y2)) flag = false;
        }
        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;
        if(cases) cout << endl;
    }
    return 0;
}