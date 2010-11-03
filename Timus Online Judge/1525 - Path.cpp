#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    
    char I[100001];
    scanf("%s",I);
    
    int n0 = 0,n1 = n-1,m0 = 0,m1 = m-1,k0 = 0,k1 = k-1;
    int L = strlen(I);
    
    for(int i = 0;i<L;++i){
        if(I[i]=='l'){
            if(n0>0) --n0;
            if(n1>0) --n1;
        }
        
        if(I[i]=='r'){
            if(n0<n-1) ++n0;
            if(n1<n-1) ++n1;
        }
        
        if(I[i]=='d'){
            if(m0>0) --m0;
            if(m1>0) --m1;
        }
        
        if(I[i]=='u'){
            if(m0<m-1) ++m0;
            if(m1<m-1) ++m1;
        }
        
        if(I[i]=='b'){
            if(k0>0) --k0;
            if(k1>0) --k1;
        }
        
        if(I[i]=='f'){
            if(k0<k-1) ++k0;
            if(k1<k-1) ++k1;
        }
    }
    
    printf("%lld\n",(long long)(n1-n0+1)*(m1-m0+1)*(k1-k0+1));
    
    return 0;
}
