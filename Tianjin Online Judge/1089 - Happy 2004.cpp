#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);    

    int mod2[28];
    int mod3[28];
    int mod167[14];
    int ax1=1,ax2=1;

    for(int i=0;i<28;i++){
        mod2[i]=ax1;
        mod3[i]=ax2;
        ax1=(ax1*2)%29;
        ax2=(ax2*3)%29;
    }
    ax1=1;
    for(int i=0;i<14;i++){
        mod167[i]=ax1;
        ax1=(ax1*167)%29;
    }
    
    int X,ans;
    
    while(1){
        scanf("%d",&X);
        
        if(X==0) break;
        
        //13^{-1}=9(mod 29)
        
        ans=(9*(mod2[(2*X+1)%28]-1)*(mod3[(X+1)%28]-1)*(mod167[(X+1)%14]-1))%29;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
