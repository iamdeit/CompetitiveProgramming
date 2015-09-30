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

int main() {
    string res, empty;
    char c, temp;
    int cases;
    string buffer;
    cin >> cases;
    getline(cin, empty);
    getline(cin, empty);
    while(cases--) {
        res = "";
        while(getline(cin, buffer) && !buffer.empty()) {
            c = buffer[0];
            if(c >= 48 && c <= 57) res += c;
            else if(c == '(') st.push('(');
            else if(c == '+' || c == '-') {
                if(!st.empty()) {
                    temp = st.top();
                    if(temp == '(') st.push(c);
                    else {
                        while(temp != '(' && !st.empty()) {
                            st.pop();
                            res += temp;
                            if(!st.empty()) temp = st.top();
                        }
                        st.push(c);
                    }
                }else {
                    st.push(c);
                }
            }else if(c == '*' || c == '/') {
                if(!st.empty()) {
                    temp = st.top();
                    if(temp == '(' || temp == '+' || temp == '-') st.push(c);
                    else {
                        while((temp == '*' || temp == '/') && !st.empty()) {
                            st.pop();
                            res += temp;
                            if(!st.empty()) temp = st.top();
                        }
                        st.push(c);
                    }
                }else {
                    st.push(c);
                }
            }else{
                while(st.top() != '(') {
                    temp = st.top();
                    st.pop();
                    res += temp;
                }
                st.pop();
            }
        }
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        printf("%s\n", res.c_str());
        if(cases > 0) {
            printf("\n");
        }
    }
    return 0;
}


