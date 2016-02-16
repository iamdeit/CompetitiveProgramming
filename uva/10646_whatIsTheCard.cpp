
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

int getVal(string card) {
    int res;
    int val = card[0]-48;
    if(val >=2 && val <= 9) res = val;
    else res = 10;
    return res;
}


int main() {
    freopen("input", "r", stdin);
    string line;
    int cases, index = 1, y, x, topIndex, times;
    scanf("%d\n", &cases);
    while(cases--) {
        y = 0;
        getline(cin, line);
        vector<string> pile = split(line, " ");
        vector<string> hand;
        for(int i = 51; i > 26; i--) {
            hand.push_back(pile[i]);
            pile.erase(pile.begin()+i);
        }
        topIndex = pile.size()-1;
        for(int i = 0; i < 3; i++) {
            x = getVal(pile[topIndex]);
            y += x;
            pile.erase(pile.begin()+topIndex);
            topIndex--;
            times = 10-x;
            while(times--) {
                pile.erase(pile.begin()+topIndex);
                topIndex--;
            }
        }
        for(int i = 24; i >= 0; i--) {
            pile.push_back(hand[i]);
        }
        printf("Case %d: %s\n", index++, pile[y-1].c_str());
    }

    return 0;
}