#include<cstdio>

using namespace std;

int main(){    
    int P,T,a,b,cont;
    bool M[100][100];
    bool found[100];
    bool equal;
    
    scanf("%d %d",&P,&T);
    
    for(int i=0;i<P;i++) found[i]=false;
    for(int i=0;i<T;i++)
        for(int j=0;j<P;j++) M[i][j]=false;
    
    while(scanf("%d %d",&a,&b)==2) M[a-1][b-1]=true;
    
    cont=0;
    
    for(int i=0;i<P;i++){
        if(found[i]) continue;
        cont++;
        
        for(int j=i+1;j<P;j++){
            equal=true;
            
            for(int k=0;k<T;k++) if(M[i][k]!=M[j][k]) equal=false;
            
            if(equal) found[j]=true;
        }
    }
    
    printf("%d\n",cont);
    
    return 0;
}
