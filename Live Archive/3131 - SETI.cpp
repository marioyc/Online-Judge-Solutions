#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int R,C;
int MOD;

struct M{
    int X[70][71];
    
    M(){
    }
};

int exp(int a, int n){
    if(n==0) return 1;
    if(n==1) return a;
    
    int aux=exp(a,n/2);
    
    if(n&1) return ((long long)a*(aux*aux)%MOD)%MOD;
    return (aux*aux)%MOD;
}

int ModularInverse(int a){
    return exp(a,MOD-2);
}

void GaussianElimination(M &M0){
    int aux;
    bool found;
    
    for(int i=0,r=0;r<R && i<C;i++){
        found=false;
        
        for(int j=r;j<R;j++){
            if(M0.X[j][i]>0){
                found=true;
                
                if(j==r) break;
                
                for(int k=i;k<C;k++) swap(M0.X[r][k],M0.X[j][k]);
                break;
            }
        }
        
        if(found){
            aux=ModularInverse(M0.X[r][i]);
            
            for(int j=i;j<C;j++) M0.X[r][j]=(M0.X[r][j]*aux)%MOD;
            
            for(int j=r+1;j<R;j++){
                aux=MOD-M0.X[j][i];
                for(int k=i;k<C;k++) M0.X[j][k]=(M0.X[j][k]+aux*M0.X[r][k])%MOD;
            }
            
            r++;
        }
    }
    
    for(int i=R-1;i>0;i--)
        for(int j=0;j<i;j++)
            M0.X[j][R]=(M0.X[j][R]+(MOD-M0.X[j][i])*M0.X[i][R])%MOD;
}

int main(){
    int T;
    char s[71];
    M M0;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %s",&MOD,s);
        
        R=strlen(s);
        C=R+1;
        
        for(int k=1;k<=R;k++)
            for(int i=0,pot=1;i<R;i++,pot=(pot*k)%MOD)
                M0.X[k-1][i]=pot;
        
        for(int i=0;i<R;i++) M0.X[i][R]=(s[i]=='*'? 0:s[i]-'a'+1);
        
        GaussianElimination(M0);
        
        for(int i=0;i<R;i++){
            printf("%d",M0.X[i][R]);
            
            if(i<R-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
