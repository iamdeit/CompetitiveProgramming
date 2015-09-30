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

#define pa pair<string, int>


bool my_sort(pa x, pa y){
    return (x.second < y.second);
}

int main()
{
    int M,n,m,measure;
    string line;
    scanf("%d\n",&M);
    while(M--){
        scanf("%d %d\n",&n,&m);
        pa arr[m];
        for(int i=0;i<m;i++){
            measure = 0;
            getline(cin, line);
            for(int j=0; j<n;j++){ // DAABEC 4+1=5
                for(int k=j+1;k<n;k++){
                    if (line[j] > line[k]) measure++;
                }
            }
            arr[i] = make_pair(line,measure);
        }

        stable_sort(arr,arr+m,my_sort);
        for(int i=0;i<m;i++) {
            printf("%s\n",arr[i].first.c_str());
        }
        if(M > 0) printf("\n");
    }

    return 0;
}
