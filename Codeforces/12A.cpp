#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
    
char M[3][4];

bool check(){
    if(M[0][0] != M[2][2]) return false;
    if(M[2][0] != M[0][2]) return false;
    if(M[1][0] != M[1][2]) return false;
    if(M[0][1] != M[2][1]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    
    for(int i = 0;i < 3;++i)
        scanf("%s",M[i]);
    
    if(check()) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
