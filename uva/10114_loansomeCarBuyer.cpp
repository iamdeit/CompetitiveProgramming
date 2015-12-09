
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

int main() {
    int months, records, readMonth, currMonth, index, res;
    bool flag;
    double pay, loan, percentage, carValue, monthPayment;
    while(scanf("%d %lf %lf %d", &months, &pay, &loan, &records), months > 0) {
        flag = true;
        currMonth = 0;
        double arr[months];
        while(records--) {
            scanf("%d %lf", &readMonth, &percentage);
            while(currMonth < readMonth) {
                arr[currMonth] = arr[currMonth-1];
                currMonth++;
            }
            arr[readMonth] = percentage;
            currMonth++;
        }
        while(currMonth < months) {
            arr[currMonth] = arr[currMonth-1];
            currMonth++;
        }
        index = 0;
        carValue = (loan + pay) - ((loan+pay)*arr[0]);
        if(loan < carValue) {
            flag = false;
            res = 0;
        }
        monthPayment = loan/(months+0.0);
        while(flag && index < months) {
            index++;
            carValue -= (carValue*arr[index]);
            loan -= monthPayment;
            if(loan < carValue) {
                res = index;
                flag = false;
            }
        }
        if(res == 1) cout << "1 month" << endl;
        else cout << res << " months" << endl;
    }
    return 0;
}