
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


int main() {
    bool alreadyPicked[53];
    int she[3], he[2], bestCard, sheWins, leftCard;
    while(scanf("%d %d %d %d %d", &she[0], &she[1], &she[2], &he[0], &he[1]), she[0]) {
        fill(alreadyPicked, alreadyPicked+53, false);
        alreadyPicked[she[0]] = true;
        alreadyPicked[she[1]] = true;
        alreadyPicked[she[2]] = true;
        alreadyPicked[he[0]] = true;
        alreadyPicked[he[1]] = true;
        sheWins = 0;
        sort(she, she+3);
        sort(he, he+2);
        if(she[0] > he[1]) {
            sheWins += 2;
            leftCard = she[2];
        }else if(she[0] > he[0]) {
            sheWins++;
            if(she[1] > he[1]) sheWins++;
            else {
                if(she[2] > he[1]) sheWins++;
                else leftCard = she[2];
            }
        }else if(she[1] > he[1]) {
            sheWins += 2;
            leftCard = she[0];
        }else if(she[1] > he[0]) {
            sheWins++;
            if(she[2] > he[1]) sheWins++;
            else leftCard = she[2];
        }else if(she[2] > he[1] || she[2] > he[0]) {
            sheWins++;
            leftCard = she[1];
        }else {
            leftCard = 0;
        }

        if(sheWins > 1) bestCard = -1;
        else {
            int i = leftCard+1;
            while(alreadyPicked[i] && i < 53) i++;
            if(i < 53) bestCard = i;
            else bestCard = -1;
        }
        printf("%d\n", bestCard);
    }
    return 0;
}