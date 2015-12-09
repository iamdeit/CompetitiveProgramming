#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

string toUpperCase(string s) {
    s[0] = toupper(s[0]);
    s[1] = toupper(s[1]);
    return s;
}

int main() {
    int cases, len, mem[100], ptr, currCase = 1;
    char line[100010];
    scanf("%d", &cases);
    while(cases--) {
        fill(mem, mem+100, 0);
        scanf("%s", line);
        len = strlen(line);
        ptr = 0;
        for(int i = 0; i < len; i++) {
            if(line[i] == '>') ptr = (ptr+1)%100;
            else if(line[i] == '<') {
                ptr--;
                if(ptr < 0) ptr = 99;
            }
            else if(line[i] == '+') mem[ptr] = (mem[ptr]+1)%256;
            else if(line[i] == '-') {
                mem[ptr]--;
                if(mem[ptr] < 0) mem[ptr] = 255;
            }
        }
        printf("Case %d:", currCase++);
        for(int i = 0; i < 100; i++) {
            stringstream sstream;
            sstream << setw(2) << hex << setfill('0') << mem[i];
            string res = toUpperCase(sstream.str());
            printf(" %s", res.c_str());
        }
        printf("\n");
    }
}