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

stack<char> stack1;

void clearStack() {
    while(!stack1.empty()) stack1.pop();
}

char getPar(char c) {
    if(c == ')') return '(';
    else return '[';
}

int main() {
    int cases;
    bool flag;
    char c;
    scanf("%d", &cases);
    getchar();
    string s;
    while(cases--) {
        getline(cin, s);
        flag = true;
        for(int i = 0; i < s.size() && flag; i++) {
            c = s[i];
            if(c == '(' || c == '[') stack1.push(c);
            else if(c == ')' || c == ']') {
                if(stack1.empty() || stack1.top() != getPar(c)) flag = false;
                else stack1.pop();
            }
        }
        if(stack1.empty() && flag) printf("Yes\n");
        else printf("No\n");
        clearStack();
    }

    return 0;
}

