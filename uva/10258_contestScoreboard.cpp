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


struct contestantStruct {
    int contestantNumber;
    int problems;
    int time;

    bool operator < (const contestantStruct& cs2) const {
        bool res;
        if(problems < cs2.problems) res = true;
        else if(problems > cs2.problems) res = false;
        else {
            if(time > cs2.time) res = true;
            else if(time < cs2.time) res = false;
            else {
                if(contestantNumber > cs2.contestantNumber) res = true;
                else res = false;
            }
        }
        return res;
    }
};


int main() {
    int cases;
    int contestant, problem, time;
    char state;
    string buffer;
    scanf("%d", &cases);
    getchar();
    map<int, pair<bool, int>[9]> map1;
    getline(cin, buffer);
    pair<bool, int> empty[9] = {};
    while(cases--) {
        while(getline(cin, buffer) && buffer != "") {
            vector<string> v = split(buffer, " ");
            contestant = stoi(v[0]);
            problem = stoi(v[1]);
            time = stoi(v[2]);
            state = v[3][0];
            if(state != 'U' && state != 'R' && state != 'E') {
                if(state == 'I') {
                    if(!map1[contestant][problem-1].first) {
                        map1[contestant][problem-1].second += 20;
                    }
                }else {
                    if(!map1[contestant][problem-1].first) {
                        map1[contestant][problem-1].second += time;
                        map1[contestant][problem-1].first = true;
                    }
                }
            }else{
                map1[contestant][problem-1].second += 0;
            }
        }
        vector<contestantStruct> vc;
        typedef map<int, pair<bool, int>[9]>::iterator it_type;
        for(it_type iterator = map1.begin(); iterator != map1.end(); iterator++) {
            contestantStruct cs;
            cs.contestantNumber = iterator->first;
            pair<bool, int> *tempArray = iterator->second;
            int totalProblems = 0;
            int totalTime = 0;
            for(int i = 0; i < 9; i++) {
                if(tempArray[i].first) {
                    totalProblems++;
                    totalTime += tempArray[i].second;
                }
            }
            cs.problems = totalProblems;
            cs.time = totalTime;
            vc.push_back(cs);
        }
        sort(vc.rbegin(), vc.rend());
        for(contestantStruct csvar : vc) {
            printf("%d %d %d\n", csvar.contestantNumber, csvar.problems, csvar.time);
        }
        if(cases > 0) {
            printf("\n");
        }
        map1.clear();
    }
    return 0;
}

