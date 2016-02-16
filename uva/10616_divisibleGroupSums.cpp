#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int N, Q, D, M, set = 1, query;

long long memo[205][22][12];
int arr[202];

long long DP(int index, int sum, int size) {
    if(size == M) {
        if(!sum) return 1;
        return 0;
    }
    if(index == N) {
        return 0;
    }
    if(memo[index][sum][size] != -1) return memo[index][sum][size];
    memo[index][sum][size] = DP(index + 1, ((sum+arr[index])%D + D) % D, size+1) + DP(index + 1, sum, size);
    return memo[index][sum][size];
}

long long solve() {
    return DP(0, 0, 0);
}


int main() {
    while(cin >> N >> Q, N && Q) {
        for(int i = 0; i < N; i++) cin >> arr[i];
        cout << "SET " << set++ << ":" << endl;
        query = 1;
        while(Q--) {
            cin >> D >> M;
            memset(memo, -1, sizeof(memo));
            cout << "QUERY " << query++ << ": " << solve() << endl;
        }

    }
    return 0;
}