#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <stdio.h>


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
map<char,int> m;

int main() {
    int N,K,M,value;
    unsigned long long payment;
    char c;
    string line;
    scanf("%d\n",&N);
    while(N--){
        payment = 0;
        scanf("%d\n",&K);
        while(K--){
            scanf("%c %d\n",&c,&value);
            m[c] = value;
        }
        scanf("%d\n",&M);
        while(M--){
            getline(cin,line);
            for(int i =0; i < line.size();i++){
                payment += m[line[i]];
            }
        }
        printf("%.2lf$\n",payment/100.0);
        m.clear();
    }
    return 0;
}
