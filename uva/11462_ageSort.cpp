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


int main() {
    int n, temp;
    int arr[100];
    while(scanf("%d",&n), n != 0) {
        fill(arr, arr+100, 0);
        while(n--) {
            scanf("%d", &temp);
            arr[temp-1]++;
        }
        bool flag = false;
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < arr[i]; j++) {
                if(!flag) {
                    flag = true;
                    printf("%d", i+1);
                } else{
                    printf(" %d", i+1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
