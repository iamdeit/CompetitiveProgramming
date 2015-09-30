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
#include <stack>

using namespace std;

vector<int> v;
stack<int> st;

vector<int> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<int> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(stoi(current));
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}

void clearStack() {
    while(!st.empty()) st.pop();
}

void printV() {
    for(int i : v) {
        cout << i << " ";
    }
}


int main() {

    int n, currCase, index;
    string s;
    currCase = 1;
    while(scanf("%d", &n), getchar(), n != 0) {
        while(getline(cin, s), s != "0") {
            v = split(s, " ");
            index = 0;
            for(int i = 1; i <= n; i++) {
                st.push(i);
                while(!st.empty() && v[index] == st.top()) {
                    st.pop();
                    index++;
                    if(index >= n) break;
                }
            }
            if(st.empty()) printf("Yes\n");
            else {
                printf("No\n");
                clearStack();
            }
            v.clear();
        }
        printf("\n");
    }
    return 0;
}


