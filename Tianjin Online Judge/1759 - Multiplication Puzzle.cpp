#include <cstdio>
#include <cstring>

using namespace std;

int a[100],memo[100][100];

int solve(int s, int e){
    if(e==s+1) return 0;
    int &aux = memo[s][e],aux2;
    if(aux!=-1) return aux;
    
    for(int i=s+1;i<e;++i){
        aux2 = a[s]*a[i]*a[e]+solve(s,i)+solve(i,e);
        if(aux==-1 || aux2<aux) aux = aux2;
    }
    
    return aux;
}

int main(){
    int n;
    
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;++i) scanf("%d",&a[i]);
        
        memset(memo,-1,sizeof(memo));
        printf("%d\n",solve(0,n-1));
    }
    
    return 0;
}
