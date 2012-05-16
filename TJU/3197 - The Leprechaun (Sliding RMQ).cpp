#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int sum[401];
int ans;

void solve(int n, int a[]){
    sum[0] = 0;
    
    for(int i = 1;i <= 2*n;++i)
        sum[i] = sum[i - 1] + a[i % n];
    
    deque< pair<int,int> > Q;
    Q.push_back(make_pair(0,0));
    
    for(int i = 1;i <= n;++i){
        while(!Q.empty() && Q.back().first > sum[i]) Q.pop_back();
        Q.push_back(make_pair(sum[i],i));
    }
    
    for(int i = n + 1;i <= 2*n;++i){
        if(Q.front().second == i - n - 1) Q.pop_front();
        
        ans = max(ans,sum[i] - Q.front().first);
        
        while(!Q.empty() && Q.back().first > sum[i]) Q.pop_back();
        Q.push_back(make_pair(sum[i],i));
    }
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    int M[N][N];
    
    for(int i = 0;i < N;++i)
        for(int j = 0;j < N;++j)
            scanf("%d",&M[i][j]);
    
    ans = M[0][0];
    int a[N];
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j)
            a[j] = M[i][j];
        
        solve(N,a);
        
        for(int j = 0;j < N;++j)
            a[j] = M[j][i];
        
        solve(N,a);
    }
    
    for(int i = 0;i < N;++i){
        for(int j = 0,r = 0,c = i;j < N;++j){
            a[j] = M[r][c];
            
            ++r;
            --c;
            
            if(r >= N) r -= N;
            if(c < 0) c += N;
        }
        
        solve(N,a);
        
        for(int j = 0,r = 0,c = i;j < N;++j){
            a[j] = M[r][c];
            
            ++r;
            ++c;
            
            if(r >= N) r -= N;
            if(c >= N) c -= N;
        }
        
        solve(N,a);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
