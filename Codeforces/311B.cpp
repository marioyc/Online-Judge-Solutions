#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXM 100000

struct line{
    long long a,b;
    
    line(){}
    line(long long _a, long long _b):
        a(_a),b(_b){}
};

long long a[MAXM],suma[MAXM];
long long dp[2][MAXM];
line H[MAXM];
int sz,pos;

bool check(line &l1, line &l2, line &l3){
    return (l3.b - l2.b) * (l1.a - l3.a) >= (l3.b - l1.b) * (l2.a - l3.a);
}

void insert(long long a, long long b){
    line l(a,b);
    while(sz >= 2 && !check(H[sz - 2],H[sz - 1],l)) --sz;
    H[sz] = l;
    ++sz;
}

long long eval(int ind, long long x){
    return H[ind].a * x + H[ind].b;
}

long long query(long long x){
    while(pos + 1 < sz && eval(pos,x) > eval(pos + 1,x)) ++pos;
    return eval(pos,x);
}

int main(){
    ios::sync_with_stdio(0);
    
    int n,m,p;
    
    cin >> n >> m >> p;
    
    long long d[n];
    d[0] = 0;
    
    for(int i = 1;i < n;++i)
        cin >> d[i];
    for(int i = 1;i < n;++i)
        d[i] += d[i - 1];
    
    for(int i = 0,h,t;i < m;++i){
        cin >> h >> t;
        a[i] = t + 1 - d[h - 1];
    }
    
    sort(a,a + m);
    suma[0] = 0;
    
    for(int i = 0;i < m;++i)
        suma[i + 1] = suma[i] + a[i];
    
    for(int i = 0;i < m;++i)
        dp[1][i] = a[i] * (i + 1) - suma[i + 1];
    
    for(int i = 2,r = 0;i <= p;++i,r ^= 1){
        sz = 0;
        pos = 0;
        
        for(int j = 0;j < m;++j){
            if(j < i) dp[r][j] = 0;
            else{
                long long q = query(a[j]);
                dp[r][j] = a[j] * j - suma[j + 1] + q;
            }
            insert(-j,dp[r ^ 1][j] + suma[j + 1]);
        }
    }
    
    cout << dp[p & 1][m - 1] << endl;
    
    return 0;
}
