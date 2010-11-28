#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

struct result{
    int a,b;
    
    result(){}
    
    result(int _a, int _b){
        a = _a; b = _b;
    }
    
    result operator + (result X)const{
        return result(a+X.a,b+X.b);
    }
    
    double toDouble(){
        return a+b*sqrt(2.0);
    }
    
    result min(result X){
        if((*this).toDouble()<X.toDouble()) return (*this);
        return X;
    }
};

result dp[2][1001];
set< pair<int, int> > S;

int main(){
    int N,M,K;
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i = 0,r,c;i<K;++i){
        scanf("%d %d",&c,&r);
        S.insert(make_pair(r,c));
    }
    
    for(int c = 0;c<=N;++c) dp[0][c] = result(c,0);
    
    for(int r = 1;r<=M;++r){
        dp[r & 1][0] = result(r,0);
        
        for(int c = 1;c<=N;++c){
            dp[r & 1][c] = result(1,0)+dp[(r & 1) ^ 1][c].min(dp[r & 1][c-1]);
            
            if(S.find(make_pair(r,c))!=S.end())
                dp[r & 1][c] = dp[r & 1][c].min(dp[(r & 1) ^ 1][c-1]+result(0,1));
        }
    }
    
    printf("%.0lf\n",100.0*dp[M & 1][N].toDouble());
    
    return 0;
}
