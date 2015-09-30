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

    void readLines(int n) {
        string s;
        for(int i = 0; i < n; i++) {
            getline(cin, s);
        }
    }



int main() {

    int n, p, index = 1;
    float price, wprice;
    int reqs, wreqs;
    string name, wname;
    scanf("%d %d", &n, &p);
    getchar();
    while(n != 0 || p != 0) {

        readLines(n);

        getline(cin, wname);
        scanf("%f %d", &wprice, &wreqs);
        getchar();

        readLines(wreqs);

        for(int i = 1; i < p; i++) {
            getline(cin, name);
            scanf("%f %d", &price, &reqs);
            getchar();
            readLines(reqs);
            if(reqs > wreqs || (reqs == wreqs && price < wprice)) {
                wname = name;
                wprice = price;
                wreqs = reqs;
            }
        }

        if(index > 1) printf("\n");
        printf("RFP #%d\n", index++);
        printf("%s\n", wname.c_str());
        scanf("%d %d", &n, &p);
        getchar();
    }
    return 0;
}

