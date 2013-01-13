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

int n,a[50],p,p2,n2;
int b[50];
double memo[51][51][51];
double fact[51];

double solve(int pos, int have, int chose){
    if(chose < 0 || have > p) return 0;
    
    if(pos == n2){
        if(have > p2) return (double)chose / (n - chose) * fact[chose];
        return 0.0;
    }
    
    double &ret = memo[pos][have][chose];
    
    if(!(ret == ret))
        ret = solve(pos + 1,have,chose) + 1.0 / (n - chose) * solve(pos + 1,have + b[pos],chose + 1);
    
    return ret;
}

int main(){
    fact[0] = 1;
    
    for(int i = 1;i <= 50;++i)
        fact[i] = i * fact[i - 1];
    
    cin >> n;
    
    int sum = 0;
    
    for(int i = 0;i < n;++i){
        cin >> a[i];
        sum += a[i];
    }
    
    cin >> p;
    
    //todos entran
    if(sum <= p){
        printf("%d\n",n);
        return 0;
    }
    
    double ans = 0;
    
    // uno fuera
    for(int j = 0;j < n;++j){
        p2 = p - a[j];
        n2 = 0;
        
        for(int k = 0;k < j;++k) b[n2++] = a[k];
        for(int k = j + 1;k < n;++k) b[n2++] = a[k];
        
        memset(memo,-1,sizeof memo);
        ans += solve(0,0,0);
    }
    
    printf("%.5f\n",ans);
    
    return 0;
}
