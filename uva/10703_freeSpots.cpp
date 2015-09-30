#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>

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
    int w, h, n, x1, x2, y1, y2, littlex, bigx, littley, bigy;
    while(scanf("%d%d%d", &w, &h, &n), w != 0 || h != 0 || n != 0) {
        bool** m = new bool*[h];
        for(int i = 0; i < h; ++i)
            m[i] = new bool[w];
        while(n--) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            getchar();

            littlex = min(x1, x2);
            littley = min(y1,y2);
            bigx = max(x1, x2);
            bigy = max(y1,y2);

            for(int i = littley-1; i < bigy; i++) {
                for(int j = littlex-1; j < bigx; j++) {
                    m[i][j] = true;
                }
            }
        }

        int res = 0;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!m[i][j]) {
                    res++;
                }
            }
        }

        if(res == 0) printf("There is no empty spots.\n");
        else if(res == 1) printf("There is one empty spot.\n");
        else printf("There are %d empty spots.\n", res);


    }
    return 0;
}

