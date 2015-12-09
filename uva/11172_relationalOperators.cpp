#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    int cases, a, b;
    char res;
    cin >> cases;
    while(cases--) {
        cin >> a >> b;
        res = '=';
        if(a > b) res = '>';
        else if(b > a) res = '<';
        cout << res << endl;
    }
	return 0;
}

