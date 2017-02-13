
// Includes
#include <bits/stdc++.h>
using namespace std;

//Macros

#define EPSILON 0.0000000001
#define INF 1000000000
#define MOD 1000000007

typedef long long ll;
typedef vector<int> vi;


//Global variables.

ll _sieve_size;
bitset<5000> bs;
string str;
ll L, R, res;
ll memo[510][4510][2];

//Functions

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        }
}

void substractOne() {
    int index = str.size()-1;
    while(str[index] == '0') {
        str[index] = '9';
        index--;
    }
    str[index] = (char)((int)str[index])-1;
}

ll dp(int i, int sum, bool flag) {
    if(i == str.size()) return bs[sum];
    if(memo[i][sum][flag] != -1) return memo[i][sum][flag];
    ll res = 0;
    int digit;
    if(flag) {
        digit = str[i]-48;
        res = (res + dp(i+1, sum+digit, 1)) % MOD;
    }else digit = 10;

    while(--digit >= 0) res = (res + dp(i+1, sum+digit, 0)) % MOD;

    return memo[i][sum][flag] = res%MOD;
}

//Main


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // Erathostenes sieve.
    sieve(5000);
    while(cin >> str) {
        substractOne();
        memset(memo, -1, sizeof memo);
        L = dp(0, 0, 1);
        cin >> str;
        memset(memo, -1, sizeof memo);
        R = dp(0, 0, 1);
        res = (R-L+MOD)%MOD;
        cout << res << "\n";
    }
    return 0;
}