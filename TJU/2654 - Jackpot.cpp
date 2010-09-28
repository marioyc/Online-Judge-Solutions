#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    bool p[1000];
    int P[168];
    
    fill(p,p+1000,true);
    
    p[0]=p[1]=false;
    
    for(int i=2,k=0;i<1000;i++)
        if(p[i]){
            for(int j=i*i;j<1000;j+=i) p[j]=false;
            P[k++]=i;
        }
    
    int n,w,aux,cont;
    long long x;
    int T[5];
    int pow[168];
    double check;    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&w);
        
        for(int j=0;j<w;j++) scanf("%d",&T[j]);        
        
        for(int j=0;j<168;j++){
            aux=0;
            for(int k=0;k<w;k++){
                cont=0;
                while(T[k]%P[j]==0){
                    cont++;
                    T[k]/=P[j];
                }
                aux=max(aux,cont);
            }
            pow[j]=aux;
        }
        
        x=1;
        for(int j=0;j<168;j++)
            for(int k=0;k<pow[j];k++) x*=P[j];
        
        if(x>1000000000) printf("More than a billion.\n");
        else printf("%lld\n",x);
    }
    
    return 0;
}
