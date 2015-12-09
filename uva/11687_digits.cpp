#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	string line;
	int res, len;
	while(cin >> line, line != "END") {
		if(line == "1") res = 1;
		else {
			len = line.size();
			if(len == 1) res = 2;
			else if(len < 10) res = 3;
			else res = 4;
		}
		printf("%d\n", res);
	}
}