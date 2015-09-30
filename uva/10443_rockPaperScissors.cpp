#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>


using namespace std;

    int r, c, n;

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


    char change(char **mat, int row, int col) {
        char curr = mat[row][col];
        char c1,c2,c3,c4, compare;
        c1 = c2 = c3 = c4 = curr;
        if(row-1 >= 0) c1 = mat[row-1][col];
        if(col-1 >= 0) c2 = mat[row][col-1];
        if(col+1 < c) c3 = mat[row][col+1];
        if(row+1 < r) c4 = mat[row+1][col];
        if(curr == 'P') {
            compare = 'S';
        }else if(curr == 'S') {
            compare = 'R';
        }else {
            compare = 'P';
        }
        char res;
        if(c1 == compare || c2 == compare || c3 == compare || c4 == compare) {
            res = compare;
        }
        else res = curr;
        return res;
    }




int main() {

    int t;
    char temp;
    string s;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d%d", &r, &c, &n);
        getchar();
        char** arr1 = new char*[r];
        char** arr2 = new char*[r];
        for(int i = 0; i < r; i++) {
            arr1[i] = new char[c];
            arr2[i] = new char[c];
        }
        for(int i = 0; i < r; i++) {
            getline(cin, s);
            for(int j = 0; j < c; j++) {
                arr1[i][j] = s[j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int k = 0; k < r; k++) {
                for(int o = 0; o < c; o++) {
                    if(i % 2 == 0) {
                        arr2[k][o] = change(arr1, k, o);
                    }else {
                        arr1[k][o] = change(arr2, k, o);
                    }
                }
            }
            if(i == n-1) {
                if(i%2==0) {
                    for(int w = 0; w < r; w++) {
                        for(int q = 0; q < c; q++) {
                            printf("%c",arr2[w][q]);
                        }
                        printf("\n");
                    }
                }else {
                    for(int w = 0; w < r; w++) {
                        for(int q = 0; q < c; q++) {
                            printf("%c",arr1[w][q]);
                        }
                        printf("\n");
                    }
                }
                if(t > 0) printf("\n");
            }
        }




    }


    return 0;
}

