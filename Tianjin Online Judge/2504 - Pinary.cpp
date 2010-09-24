#include <cstdio>

using namespace std;

int main(){
    int f[38],T[38];
    
    f[0]=f[1]=1;
    for(int i=2;i<38;i++) f[i]=f[i-1]+f[i-2];
    
    T[0]=1;
    for(int i=1;i<38;i++) T[i]=T[i-1]+f[i];
    
    int TC,K,D,last;
    scanf("%d",&TC);
    
    char s[39];
    
    for(int tc=1;tc<=TC;tc++){
        scanf("%d",&K);
        
        for(int i=0;;i++){
            if(K<=T[i]){
                D=i+1;
                break;
            }
        }
        
        if(D>=2) K=K-T[D-2]-1;
        
        for(int i=0;i<39;i++) s[i]=0;
        
        s[0]='1';
        last=1;
        
        for(int i=1,j=D-1;i<D;i++){
            if(last==1){
                s[i]='0';
                last=0;
            }else{
                if(K>=f[j-1]){
                    s[i]='1';
                    last=1;
                    K-=f[j-1];
                    j-=2;
                }else{
                    s[i]='0';
                    last=0;
                    j--;
                }
            }
        }
        
        printf("%s\n",s);
    }
    
    return 0;
}
