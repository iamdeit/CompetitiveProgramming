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



int bubble(int arr[], int len) {
    int res = 0;
    int temp;
    bool go = true;
    while(go) {
        go = false;
        for(int i = 0; i < len-1; i++) {
            if(arr[i+1] < arr[i]) {
                temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                res++;
                go = true;
            }
        }
    }
    return res;
}


int main() {
    int cases, trains, temp;
    scanf("%d\n", &cases);
    while(cases--) {
        scanf("%d\n", &trains);
        int arr[trains];
        for(int i = 0; i < trains; i++) {
            scanf("%d", &temp);
            arr[i] = temp;
        }
        printf("Optimal train swapping takes %d swaps.\n", bubble(arr, trains));
    }
    return 0;
}
