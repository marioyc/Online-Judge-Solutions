#include <cstdio>

using namespace std;

struct EuclidReturn{
    int u,v,d;
	
    EuclidReturn(int _u, int _v, int _d){
        u = _u; v = _v; d = _d;
    }
};
    
EuclidReturn Extended_Euclid(int a, int b){
    if(b==0) return EuclidReturn(1,0,a);
    EuclidReturn aux = Extended_Euclid(b,a%b);
    int v = aux.u-(a/b)*aux.v;
    return EuclidReturn(aux.v,v,aux.d);
}

// ax = 1(mod n)
int modular_inverse(int a, int n){
    EuclidReturn aux = Extended_Euclid(a,n);
    return ((aux.u/aux.d)%n+n)%n;
}

int main(){
    int N, MOD = 2007;
    scanf("%d",&N);
    
    int F[10001],G[10001];
    for(int i = 1;i<=N;++i) scanf("%d",&F[i]);
    
    G[1] = modular_inverse(F[1],MOD);
    
    for(int i = 2,d;i<=N;++i){
        G[i] = F[i]*G[1];
        
        for(d = 2;d<i/d;++d)
            if(i%d==0)
                G[i] = (G[i]+F[d]*G[i/d]+F[i/d]*G[d])%MOD;
        
        if(d*d==i) G[i] = (G[i]+F[d]*G[d])%MOD;
        
        G[i] = (modular_inverse(MOD-F[1],MOD)*G[i])%MOD;
    }
    
    for(int i = 1;i<=N;++i) printf("%d ",G[i]);
    printf("\n");
    
    return 0;
}
