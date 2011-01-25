#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long ans[100001];
int a[100000],b[100000],c[100000];

int main(){
    int N,M,Q;
    scanf("%d %d %d",&N,&M,&Q);
    
    for(int i = 0;i<M;++i)
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
    
    int x;
    long long total = 0;
    memset(ans,-1,sizeof(ans));
    
    while(Q--){
        scanf("%d",&x);
        
        if(ans[x]==-1){
            ans[x] = 0;
            
            for(int i = 0;i<M;++i)
                if(x>=a[i] && x<=b[i])
                    ans[x] += c[i]+x-a[i];
        }
        
        total += ans[x];
    }
    
    cout<<total<<endl;
    
    return 0;
}
