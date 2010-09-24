#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    bool p[31623];
    fill(p,p+31623,true);
    p[0]=p[1]=false;    
    
    int P[3401]; //sqrt(10^9)=31622.77660
    int P_size=0;
    
    for(int i=2;i<31623;i++){
        if(p[i]){
            P[P_size++]=i;
            for(int j=2;j*i<31623;j++) p[i*j]=false;
        }
        
    }
    
int T,n,cont,d;

scanf("%d",&T);

for(int i=1;i<=T;i++){
    printf("Scenario #%d:\n",i);
    
    scanf("%d",&n);

    d=1;
    
    for(int i=0;i<P_size && P[i]<sqrt(n) && n!=1;i++){
        cont=0;
        while(n%P[i]==0){
            n/=P[i];
            cont++;
        }
        d*=(2*cont+1);
    }
        
    if(n!=1) d*=3;
        
    printf("%d\n\n",(d+1)/2);
}
    
    return 0;
}
