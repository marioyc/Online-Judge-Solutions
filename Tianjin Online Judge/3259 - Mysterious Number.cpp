#include <cstdio>
#include <algorithm>

using namespace std;

bool p[1000001];
int f[1000001],d[1000001];

int main(){
    fill(p,p+1000001,true);
    
    int P[78498];
    int cont=0;
    
    for(int i=2;i<=1000000;i++){
        if(p[i]){
            P[cont++]=i;
            if(i<=1000) for(int j=i*i;j<=1000000;j+=i) p[j]=false;
        }
    }
    
    int pos,aux,lim;
    
    f[0]=0;
    f[1]=1;
    d[1]=1;
    
    for(int i=1;i<=1000000;i++){
        if(P[pos]==i) pos++;
        
        for(int j=0;j<78498 && i<=1000000/P[j];j++){
            if(i%P[j]==0) continue;
            aux=i*P[j],lim=1000000/P[j];
            cont=1;
            while(1){
                d[aux]=d[i]*(cont+1);
                
                if(aux<=lim) aux*=P[j];
                else break;
                cont++;
            }
        }
        
        if(i%d[i]==0) f[i]=f[i-1]+1;
        else f[i]=f[i-1];
    }
    
    int L,H;
    
    while(scanf("%d %d",&L,&H)==2) printf("%d\n",f[H]-f[L-1]);
    
    return 0;
}
