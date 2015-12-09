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
    string line, res;
    int index = 1;
    while(cin >> line, line != "*") {
        if(line == "Hajj") res = "Hajj-e-Akbar";
        else res = "Hajj-e-Asghar";
        cout << "Case " << index++ << ": " << res << endl;
    }
    return 0;
}