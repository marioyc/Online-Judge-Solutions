#include <cstdio>
#include <algorithm>

using namespace std;

int suff[201],suff2[201];
int ans;

void solve(int n, int a[]){
    int total = 0;
    
    for(int i = 0;i < n;++i)
        total += a[i];
    
    suff[0] = suff2[0] = 0;
    
    for(int i = 0;i < n;++i)
        suff[i + 1] = suff[i] + a[n - 1 - i];
    
    for(int i = 1;i < n;++i){
        ans = max(ans,suff[i]);
        suff2[i] = min(suff[i],suff2[i - 1]);
        suff[i] = max(suff[i],suff[i - 1]);
    }
    
    for(int i = 1,sum = a[0];i < n;++i){
        ans = max(ans,sum + suff[n - i]);
        ans = max(ans,total - sum - suff2[n - 1 - i]);
        if(i < n) sum += a[i];
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
