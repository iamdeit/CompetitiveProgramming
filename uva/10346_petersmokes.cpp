#include <iostream>

using namespace std;

int main() {
    int n,k,res, curr;  //Res es el contador de los que ha fumado, curr cigarros actuales( sin fumar y fumados ).
    while(scanf("%d%d",&n, &k) != EOF) {
        res = curr = n; // Me fumo los n iniciales y me quedan n en curr (solo coletillas).

        while(curr >= k) { //Mientras pueda canjear coletillas
            res += (curr/k); //Sumo los nuevos cigarros que puedo canjear.
            curr = (curr/k) + (curr%k); //Curr ahora es igual a las coletillas de los nuevos cigarros más las que no pude cajear.
        }

        printf("%d\n",res);
    }

    return 0;
}

