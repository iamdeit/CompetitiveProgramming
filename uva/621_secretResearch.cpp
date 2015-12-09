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
    int cases, len;
    string line, res;
    cin >> cases;
    while(cases--) {
        cin >> line;
        if(line == "1" || line == "4" || line == "78") res = "+";
        len = line.size();
        if(len >= 2) {
            if(line[len-1] == '5' && line[len-2] == '3') res = "-";
            else if(line[0] == '9' && line[len-1] == '4') res = "*";
            else if(len >= 3 && line[0] == '1' && line[1] == '9' && line[2] == '0') res = "?";
        }else {
            res = "+";
        }
        printf("%s\n", res.c_str());
    }
    return 0;
}