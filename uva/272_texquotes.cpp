#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

/*
int main() {
    vector<string> v;
    string str, res, temp;
    int limit, c;
    bool add;
    while(getline(cin, str)) {
        c = count(str.begin(),str.end(),'\"');
        while(c % 2 != 0) {
            temp = "";
            getline(cin, temp);
            str = str + "\n" + temp;
            c += count(temp.begin(),temp.end(),'\"');
        }
        add = str.at(str.size()-1) == '\"';
        res = "";
        v.clear();
        v = split(str, '\"');
        limit = v.size()-1;
        int i;
        for(i = 0; i < limit; i++) {
            res += v.at(i);
            if(i % 2 == 0) res += "``";
            else res += "''";
        }
        res += v.at(limit);
        if(add) {
            if(i % 2 == 0) res += "``";
            else res += "''";
        }
        cout << res << "\n";
    }
    return 0;
}*/

