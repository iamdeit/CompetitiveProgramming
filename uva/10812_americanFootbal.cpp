#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}




int main() {
    int n;
    long a, b, aa, bb;
    scanf("%d", &n);
    getchar();
    while(n--) {
        cin >> a >> b;
        bb = (a-b)/2;
        aa = a-bb;
        if(bb >= 0 && aa >= 0) {
            if(abs(bb-aa) == b && ((a-b)%2 == 0)) cout << aa << " " << bb << "\n";
            else cout << "impossible" << "\n";
        }
        else cout << "impossible" << "\n";

    }

    return 0;
}

