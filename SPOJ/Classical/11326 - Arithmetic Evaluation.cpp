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

string s;

//op = 0 : +
//op = 1 : -
//op = 2 : *

int solve(int l, int r){
    int ret = 0,op = 0;
    
    for(int i = l,j = 0;i <= r;j ^= 1){
        if(j == 0){
            if(s[i] == '('){
                int diff = 1,l2 = i,r2 = i;
                
                while(diff){
                    ++r2;
                    
                    if(s[r2] == '(') ++diff;
                    else if(s[r2] == ')') --diff;
                }
                
                int aux = solve(l2 + 1,r2 - 1);
                
                if(op == 0) ret += aux;
                if(op == 1) ret -= aux;
                if(op == 2) ret *= aux;
                i = r2 + 1;
            }else{
                int aux = 0;
                
                while(i <= r && s[i] >= '0' && s[i] <= '9'){
                    aux = aux * 10 + s[i] - '0';
                    ++i;
                }
                
                if(op == 0) ret += aux;
                if(op == 1) ret -= aux;
                if(op == 2) ret *= aux;
            }
        }else{
            if(s[i] == '+') op = 0;
            if(s[i] == '-') op = 1;
            if(s[i] == '*') op = 2;
            ++i;
        }
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> s;
    
    cout << solve(0,s.size() - 1) << '\n';
    
    return 0;
}
