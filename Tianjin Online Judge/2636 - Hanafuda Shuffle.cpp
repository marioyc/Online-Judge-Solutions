#include<cstdio>

using namespace std;

int main(){    
    int n,r,p,c;
    int card[50];
    int aux[50];
    
    while(1){
        scanf("%d %d",&n,&r);
        if(n==0 && r==0) break;
        
        for(int i=0;i<n;i++) card[i]=n-i;
        
        for(int i=0;i<r;i++){
            scanf("%d %d",&p,&c);
            
            for(int j=0;j<p-1;j++) aux[c+j]=card[j];
            for(int j=p-1;j<p-1+c;j++) aux[j-p+1]=card[j];
            for(int j=0;j<p+c-1;j++) card[j]=aux[j];
        }
        
        printf("%d\n",card[0]);
    }
    
    return 0;
}
