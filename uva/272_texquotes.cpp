#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    string line;
    string res;
    int even = 1;
    while(getline(cin, line)) {
        res = "";
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '"') {
                if(even) res += "``";
                else res += "''";
                even = !even;
            }else {
                res += line[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}

