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

int n,x[10],y[10];
char s[10][5];
char guess[5];

bool check_guess(){
    for(int j = 0;j < 4;++j)
        for(int k = j + 1;k < 4;++k)
            if(guess[j] == guess[k]) return false;
    
    for(int i = 0;i < n;++i){
        int cx = 0,cy = 0;
        
        for(int j = 0;j < 4;++j)
            for(int k = 0;k < 4;++k)
                if(s[i][j] == guess[k]){
                    if(j == k) ++cx;
                    else ++cy;
                }
        
        if(x[i] != cx || y[i] != cy) return false;
    }
    
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0;i < n;++i)
        cin >> s[i] >> x[i] >> y[i];
    
    vector<string> poss;
    
    for(char c1 = '0';c1 <= '9';++c1)
        for(char c2 = '0';c2 <= '9';++c2)
            for(char c3 = '0';c3 <= '9';++c3)
                for(char c4 = '0';c4 <= '9';++c4){
                    guess[0] = c1; guess[1] = c2; guess[2] = c3; guess[3] = c4;
                    if(check_guess()) poss.push_back(guess);
                }
    
    if(poss.size() == 1) cout << poss[0] << '\n';
    else if(poss.size() == 0) cout << "Incorrect data\n";
    else cout << "Need more data\n";
    
    return 0;
}
