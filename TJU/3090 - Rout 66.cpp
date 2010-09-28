#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int N,E,D[20],J[20],S[20],I,F,B,d;
    bool fail;
    
    scanf("%d",&N);
    
    for(int caso=1;caso<=N;caso++){
        scanf("%d",&E);
        
        for(int i=0;i<E;i++) scanf("%d %d %d",&D[i],&J[i],&S[i]);
        scanf("%d",&I);
        
        for(int i=0;i<E;i++)
            for(int j=i+1;j<E;j++)
                if(D[i]>D[j]){
                    swap(D[i],D[j]);
                    swap(J[i],J[j]);
                    swap(S[i],S[j]);
                }
        
        fail=false;
        d=0;
        
        for(int i=0;i<E && !fail;i++){
            F=I*(D[i]-d);
            B=J[i]*S[i]*S[i];
            
            if(F<=B) fail=true;
            else{
                d=D[i];
                I=ceil(I-B*I*1.0/F);
            }
        }
        
        if(fail) printf("RETREAT!\n");
        else printf("ROUT!\n");
    }
    
    return 0;
}
