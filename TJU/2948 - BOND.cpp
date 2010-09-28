#include<iostream>
#include<cmath>

using namespace std;

double bond[20][20];
int N;
bool busy[20];

double dp[(1<<21)];

double prob(int mask_bond){
    int cont=__builtin_popcount(mask_bond);
    
    if(cont==N) return 1.0;
    
    if(dp[mask_bond]!=-1.0) return dp[mask_bond];
    
    double mx=0.0;
    
    for(int i=0;i<N;i++)
        if((mask_bond & (1<<i))==0)
            mx=fmax(mx,bond[i][cont]*prob(mask_bond | (1<<i)));
    
    dp[mask_bond]=mx;
    
    return mx;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int aux;
    
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>aux;
            bond[i][j]=aux*0.01;
        }
    }
    
    for(int i=0;i<(1<<N);i++) dp[i]=-1.0;
    
    printf("%.12f\n",prob(0)*100);
    
    return 0;
}
