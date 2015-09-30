#include <iostream>
#include <stdio.h>

using namespace std;


int process(long n) {
    if(n == 1) return 1;
    int counter = 1;
    while(n > 1) {
        if(n % 2 == 0) {
            n /= 2;
        }else {
            n = (3*n)+1;
        }
        counter++;
    }
    return counter;
}

int processInterval(long i, long f) {
    int greatest = -1;
    long temp = i;
    int res;
    while(temp <= f) {
        res = process(temp);
        if(res > greatest) greatest = res;
        temp++;
    }
    return greatest;
}


/*
int main() {
    long ini, fin;
    while(scanf("%ld %ld", &ini, &fin) != EOF) {
        if(ini > fin) printf("%ld %ld %d\n", ini, fin, processInterval(fin,ini));
        else printf("%ld %ld %d\n", ini, fin, processInterval(ini,fin));

    }
    return 0;
}
 */

