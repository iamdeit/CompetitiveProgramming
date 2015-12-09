
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
    int courses, categories, ncourses, req, metReq;
    string readCourse;
    bool flag;
    while(scanf("%d", &courses), courses) {
        scanf("%d", &categories);
        map<string, bool> m;
        while(courses--) {
            cin >> readCourse;
            m[readCourse] = true;
        }
        flag = true;
        while(categories--) {
            scanf("%d %d", &ncourses, &req);
            metReq = 0;
            while(ncourses--) {
                cin >> readCourse;
                if(m[readCourse]) metReq++;
            }
            if(metReq < req) flag = false;
        }
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}