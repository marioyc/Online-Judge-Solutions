#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,M,a[10000],b[10000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 0;i < N;++i) scanf("%d",&a[i]);
        for(int i = 0;i < M;++i) scanf("%d",&b[i]);
        
        sort(a,a + N);
        sort(b,b + M);
        
        int ans = 0;
        
        for(int i1 = 0,i2 = 0;i1 < N || i2 < M;){
            int e1 = i1,e2 = i2,x;
            
            if(i1 < N && i2 < M) x = min(a[i1],b[i2]);
            else if(i1 < N) x = a[i1];
            else x = b[i2];
            
            while(e1 < N && a[e1] == x) ++e1;
            while(e2 < M && b[e2] == x) ++e2;
            
            ans += abs((e1 - i1) - (e2 - i2));
            
            i1 = e1; i2 = e2;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
