#include <cstdio>
#include <algorithm>

using namespace std;

int MCD[101][101],a[30],sz;

void generate(int n, int m, int mn){
    if(n==sz){
        if(m==0){
            for(int i=0;i<sz;i++){
                printf("%d",a[i]);
                if(i<sz-1) printf(" ");
                else printf("\n");
            }
        }
        return;
    }
    
    bool valid;
    
    for(int i=mn;i*(sz-n)<=m;i++){
        valid=true;
        for(int j=0;j<n;j++) if(MCD[a[j]][i]!=1) valid=false;
        
        if(!valid) continue;
        
        a[n]=i;
        generate(n+1,m-i,i);
    }
}

int main(){
    for(int i=1;i<=100;i++)
        for(int j=i;j<=100;j++)
            MCD[i][j]=__gcd(i,j);
    
    int T,S;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&S,&sz);
        
        printf("Case %d:\n",tc);
        generate(0,S,1);
    }
    
    return 0;
}
