
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

string  getSuit(int index) {
    string suit;
    if(index == 0) suit = "S";
    else if(index == 1) suit = "H";
    else if(index == 2) suit = "D";
    else suit = "C";
    return suit;
}


int main() {
    string line, answer, bidSuit;
    int res, suitIndex, res2, maxCardsSuit, len;
    char cardVal, suit;
    bool kingPresent, queenPresent, jackPresent, acePresent, allStopped;
    while(getline(cin, line)) {
        res = 0;
        vector<string> cards = split(line, " ");
        vector<string> suitArr[4];
        bool cardsPresent[4][4];
        for(int i = 0; i < 4; i++) fill(cardsPresent[i], cardsPresent[i]+4, false);
        bool stopped[4];
        for(int i = 0; i < 13; i++) {
            suit = cards[i][1];
            if(suit == 'S') suitIndex = 0;
            else if(suit == 'H') suitIndex = 1;
            else if(suit == 'D') suitIndex = 2;
            else suitIndex = 3;

            kingPresent = queenPresent = jackPresent = acePresent = false;
            cardVal = cards[i][0];
            if(cardVal == 'A') {
                acePresent = true;
                res += 4;
            }
            else if(cardVal == 'J') {
                jackPresent = true;
                res++;
            }
            else if(cardVal == 'Q') {
                queenPresent = true;
                res += 2;
            }
            else if(cardVal == 'K') {
                kingPresent = true;
                res += 3;
            }

            cardsPresent[suitIndex][0] = cardsPresent[suitIndex][0] || jackPresent;
            cardsPresent[suitIndex][1] = cardsPresent[suitIndex][1] || queenPresent;
            cardsPresent[suitIndex][2] = cardsPresent[suitIndex][2] || kingPresent;
            cardsPresent[suitIndex][3] = cardsPresent[suitIndex][3] || acePresent;

            suitArr[suitIndex].push_back(cards[i]);
        }

        res2 = 0;
        maxCardsSuit = -1;
        for(int i = 0; i < 4; i++) {
            len = suitArr[i].size();

            if(cardsPresent[i][0]) if(len <= 3) res--;
            if(cardsPresent[i][1]) if(len <= 2) res--;
            if(cardsPresent[i][2]) if(len == 1) res--;

            if(len == 2) res2++;
            else if(len == 1) res2 += 2;
            else if(len == 0) res2 += 2;

            stopped[i] = (cardsPresent[i][3]) || (cardsPresent[i][2] && len >= 2) || (cardsPresent[i][1] && len >= 3);

            if(len > maxCardsSuit) {
                maxCardsSuit = len;
                bidSuit = getSuit(i);
            }
        }

        allStopped = true;
        for(int i = 0; i < 4 && allStopped; i++) if(!stopped[i]) allStopped = false;

        res2 += res;

        if(res2 < 14) answer = "PASS";
        else if(res >= 16 && allStopped) answer = "BID NO-TRUMP";
        else answer = "BID " + bidSuit;

        printf("%s\n", answer.c_str());
    }
    return 0;
}