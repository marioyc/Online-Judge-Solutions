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

int main(){
    ios::sync_with_stdio(0);
    
    string s[100],s2;
    int n,p[100];
    
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> s[i] >> s2;
        if(s2 == "rat") p[i] = 0;
        else if(s2 == "woman" || s2 == "child") p[i] = 1;
        else if(s2 == "man") p[i] = 2;
        else p[i] = 3;
    }
    
    for(int j = 0;j < 4;++j)
        for(int i = 0;i < n;++i)
            if(p[i] == j) cout << s[i] << '\n';
    
    return 0;
}
