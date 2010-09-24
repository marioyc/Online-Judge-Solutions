#include<cstdio>
#include<vector>

#define max(a,b) a>b? a:b

using namespace std;

vector<int> v;
int sum,n,m,k;

void f(int x){
    if(x==n){
        v[max(sum-k,1)]++;
        return;
    }
    
    for(int i=1;i<=m;i++){
        sum+=i;
        f(x+1);
        sum-=i;
    }
}

int main(){    
    sum=0;
    double E;
    int pot;
    
    while(1){
        scanf("%d %d %d",&n,&m,&k);
        if(n==0) break;
        
        v.clear();
        v.resize(m*n-k+1,0);
        
        f(0);
        
        pot=1;
        for(int i=0;i<n;i++) pot*=m;
        
        E=0;
        for(int i=1;i<=m*n-k;i++) E+=i*(v[i]*1.0/pot);
        
        printf("%.8f\n",E);
    }
    
    return 0;
}
