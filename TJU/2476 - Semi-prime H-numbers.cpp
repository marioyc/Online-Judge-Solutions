#include<cstdio>
#include<cmath>

using namespace std;

int main(){    
    int cont[250001];
    int div[250001];
    
    cont[0]=0;
    div[0]=1;
    
    double lim;
    bool found;
    
    for(int i=1,a=5;i<=250000;i++,a+=4){
        lim=sqrt(4*i+1);
        
        found=false;
        
        for(int j=5;j<=lim;j+=4)
            if(a%j==0){
                found=true;
                div[i]=div[(a/j-1)/4]+1;
                break;
            }
        
        if(!found) div[i]=1;
        
        if(div[i]==2) cont[i]=cont[i-1]+1;
        else cont[i]=cont[i-1];
    }
    
    int h;
    
    while(1){
        scanf("%d",&h);
        if(h==0) break;
        
        printf("%d %d\n",h,cont[(h-1)/4]);
    }
    
    return 0;
}
