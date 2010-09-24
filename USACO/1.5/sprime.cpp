/*
ID:zion_ba1
LANG:C++
TASK:sprime
*/

#include <cstdio>
#include <queue>

using namespace std;

struct node{
    int N,L;
    
    node(){
    }
    
    node(int _N, int _L){
        N=_N; L=_L;
    }
}aux;

bool prime(int n){
    if(n%2==0) return false;
    
    for(int i=3;i*i<=n;i+=2)
        if(n%i==0) return false;
    
    return true;
}

int main(){
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    
    int L,n;
    scanf("%d",&L);
    
    queue<node> Q;
    Q.push(node(2,1));
    Q.push(node(3,1));
    Q.push(node(5,1));
    Q.push(node(7,1));
    
    while(!Q.empty()){
        aux=Q.front();
        Q.pop();
        
        if(aux.L==L){
            printf("%d\n",aux.N);
            continue;
        }
        
        for(int i=1;i<=9;i+=2){
            n=aux.N*10+i;
            if(prime(n)) Q.push(node(n,aux.L+1));
        }
    }
    
    return 0;
}
