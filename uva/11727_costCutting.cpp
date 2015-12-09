#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int cases, index = 1, arr[3];
    cin >> cases;
    while(cases--) {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        printf("Case %d: %d\n", index++, arr[1]);
    }
	return 0;
}

