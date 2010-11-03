#include <cstdio>
#include <cstring>

using namespace std;

int A[500000],C[500000],pos1,pos2,sz;

long long countInversions(int a, int b){
    if(a==b) return 0;
    
    int c=((a+b)>>1);
    long long aux=countInversions(a,c)+countInversions(c+1,b);
    
    pos1=a; pos2=c+1; sz=0;
    
    while(pos1<=c && pos2<=b){
        if(A[pos1]<A[pos2]) C[sz]=A[pos1++];
        else{
            C[sz]=A[pos2++];
            aux+=c-pos1+1;
        }
        ++sz;
    }
     
    if(pos1>c) for(;pos2<=b;++pos2,++sz) C[sz]=A[pos2];
    else for(;pos1<=c;++pos1,++sz) C[sz]=A[pos1];
    
    for(int i=a;i<=b;++i) A[i]=C[i-a];
    
    return aux;
}

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;++i) scanf("%d",&A[i]);
        
        printf("%lld\n",countInversions(0,N-1));
    }
    
    return 0;
}
