#include<cstdio>
#include<algorithm>

using namespace std;

bool p[1000001];

int main(){
    fill(p,p+1000001,true);
    
    p[0]=p[1]=false;
    
    for(int i=2;i<1000001;i++)
        if(p[i]){
            for(int j=2;j*i<1000001;j++) p[j*i]=false;
        }
    
    int pot2[1000];
    int pot3[100];
    int pot4[31];
    
    for(int i=1;i<=1000;i++) pot2[i-1]=i*i;
    for(int i=1;i<=100;i++) pot3[i-1]=pot2[i-1]*i;
    for(int i=1;i<=31;i++) pot4[i-1]=pot3[i-1]*i;
    
    int N,M,x[100],cont[100],sum[100],prod[100],aux;
    
    scanf("%d",&N);
    
    for(int caso=1;caso<=N;caso++){
        scanf("%d",&M);
        
        fill(cont,cont+M,0);
        
        for(int i=0;i<M;i++){
            scanf("%d",&x[i]);
            
            if(p[x[i]]) cont[i]++;
            
            for(int j=0;j<1000 && pot2[j]<=x[i];j++)
                if(pot2[j]==x[i]){
                    cont[i]++;
                    break;
                }
            
            for(int j=0;j<100 && pot3[j]<=x[i];j++)
                if(pot3[j]==x[i]){
                    cont[i]++;
                    break;
                }
            
            for(int j=0;j<31 && pot4[j]<=x[i];j++)
                if(pot4[j]==x[i]){
                    cont[i]++;
                    break;
                }
            
            aux=x[i];
            sum[i]=0;
            prod[i]=1;
            
            while(aux!=0){
                sum[i]+=aux%10;
                prod[i]*=aux%10;
                aux/=10;
            }
            
            if(x[i]%sum[i]==0) cont[i]++;
            if(prod[i]!=0 && x[i]%prod[i]==0) cont[i]++;
        }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[i]%x[j]==0){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[j]%x[i]==0){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[j]<=1000 && x[i]==x[j]*x[j]){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[j]<=100 && x[i]==x[j]*x[j]*x[j]){
                    cont[i]++;
                    break;
                }
        
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[j]<=31 && x[i]==x[j]*x[j]*x[j]*x[j]){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(x[i]%sum[j]==0){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                if(i==j) continue;
                else if(prod[j]!=0 && x[i]%prod[j]==0){
                    cont[i]++;
                    break;
                }
        
        for(int i=0;i<M;i++)
            for(int j=i+1;j<M;j++)
                if(cont[i]<cont[j] || (cont[i]==cont[j] && x[i]>x[j])){
                    swap(cont[i],cont[j]);
                    swap(x[i],x[j]);
                }
        
        printf("DATA SET #%d\n",caso);
        
        for(int i=0;i<M && cont[i]==cont[0];i++) printf("%d\n",x[i]);
    }
    
    return 0;
}
