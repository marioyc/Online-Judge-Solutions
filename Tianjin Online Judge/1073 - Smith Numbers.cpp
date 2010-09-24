#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int sum(int n){
    int aux=0;
    
    while(n!=0){
        aux+=n%10;
        n/=10;
    }
    
    return aux;
}

int main(){
    bool p[10500];
    int P[1284];
    int S[1284];
    
    fill(p,p+10500,true);
    
    for(int i=2,j=0;i<10500;i++)
        if(p[i]){
            P[j]=i;
            S[j++]=sum(i);
            for(int j=i*i;j<10500;j+=i) p[j]=false;
        }
    
    int n,m,S1,S2;
    double r;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i=n+1;;i++){            
            S1=sum(i);
            r=sqrt(i);            
            S2=0;
            m=i;
            
            for(int j=0;P[j]<=r;j++){
                while(m%P[j]==0){
                    S2+=S[j];
                    m/=P[j];
                }
            }
            
            if(m==i) continue;
            if(m!=1) S2+=sum(m);
            
            if(S1==S2){
                printf("%d\n",i);
                break;
            }
        }
    }
    
    return 0;
}
