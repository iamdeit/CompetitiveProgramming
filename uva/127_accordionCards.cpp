#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string.h>
#include <vector>

using namespace std;

vector<stack<string>> pile;

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

bool match(string c1, string c2) {
    return (c1[0] == c2[0] || c1[1] == c2[1]);
}

void removeGap(int i) {
    if(pile[i].empty()) {
        pile.erase(pile.begin()+i);
    }
}

void check() {
    string currCard;
    int index, i;
    i = 1;
    while(i < pile.size() && pile.size() > 1) {
        index = i-1;
        currCard = pile[i].top();
        if(index-2 >= 0 && match(currCard, pile[index-2].top())) {
            pile[i].pop();
            pile[index-2].push(currCard);
            removeGap(i);
            i = 1;
        }else if(match(currCard, pile[index].top())) {
            pile[i].pop();
            pile[index].push(currCard);
            removeGap(i);
            i = 1;
        }else {
            i++;
        }
    }
}

int main() {
    string line,line2,currCard;
    int index;
    vector<string> deck;
    while(getline(cin,line), line != "#") {
        getline(cin,line2);
        line = line + " " + line2;
        deck = split(line," ");
        stack<string> s;
        s.push(deck[0]);
        pile.push_back(s);

        for(int i =1 ;i<52;i++){
            index = pile.size()-1;
            currCard = deck[i];
            if(index-2 >= 0 && match(currCard, pile[index-2].top())) {
                pile[index-2].push(currCard);
                check();
            }else if(match(currCard, pile[index].top())) {
                pile[index].push(currCard);
                check();
            }else {
                stack<string> temp;
                temp.push(currCard);
                pile.push_back(temp);
            }
        }
        if(pile.size() == 1) printf("1 pile remaining:");
        else printf("%d piles remaining:", pile.size());
        for(int i = 0; i < pile.size(); i++) printf(" %d", pile[i].size());
        printf("\n");
        pile.clear();
    }


    return 0;
}
