#include <iostream>
#include <stdio.h>

#define MAX_AMOUNT 7490

using namespace std;

int main() {

    int coins[] = {1, 5, 10, 25, 50};
    int DP[MAX_AMOUNT][5]; //Rows for all possible cents to be changed and 5 columns for each type of coin.

    //Fill up the first row with 1s, because there is only one way for changing 0 cents.
    for(int j = 0; j < 5; j++) {
        DP[0][j] = 1;
    }

    //Fill up the first column with 1s, becase you can change any amount of money giving n coins of 1.
    for(int i = 1; i < MAX_AMOUNT; i++) {
        DP[i][0] = 1;
    }

    //Fill the rest of matrix. You can include or not include the actual type of coin (j).
    int including, excluding;
    for(int i = 1; i < MAX_AMOUNT; i++) {
        for(int j = 1; j < 5; j++) {
            excluding = DP[i][j-1];

            including = i >= coins[j]? DP[i-coins[j]][j] : 0;

            DP[i][j] = excluding + including;
        }
    }

    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", DP[n][4]);
    }
    return 0;
}
