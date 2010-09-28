#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int H[N];
    
    for(int i=0;i<N;i++) scanf("%d",&H[i]);
    
    int ind[N];
    
    for(int i=0;i<N;i++) ind[i]=i;
    
    unsigned int cont=0;
    bool ok;
    
    do{
        ok=true;
        
        for(int i=0;i<N && ok;i++) if(abs(H[ind[(i+1)%N]]-H[ind[i]])>K) ok=false;
        
        if(ok) cont++;
    }while(next_permutation(ind+1,ind+N));
    
    printf("%u\n",cont);
    
    return 0;
}
