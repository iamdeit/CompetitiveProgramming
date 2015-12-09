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
    int index = 1;
    string res, line;
    while(cin >> line, line != "#") {
        if(line == "HELLO") res = "ENGLISH";
        else if(line == "HOLA") res = "SPANISH";
        else if(line == "HALLO") res = "GERMAN";
        else if(line == "BONJOUR") res = "FRENCH";
        else if(line == "CIAO") res = "ITALIAN";
        else if(line == "ZDRAVSTVUJTE") res = "RUSSIAN";
        else res = "UNKNOWN";
        printf("Case %d: %s\n", index++, res.c_str());
    }
    return 0;
}