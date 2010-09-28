#include<iostream>

using namespace std;

int A,B;
double memo[31][31];

double prob(int R, int T){
    if(R<0 || T<0 || (A-R<=B-T && (R!=A || T!=B))) return 0.0;
    
    if(R==0 && T==0) return 1.0;
    
    if(memo[R][T]!=-1.0) return memo[R][T];
    
    memo[R][T]=R*1.0/(R+T)*prob(R-1,T)+T*1.0/(R+T)*prob(R,T-1);
    
    return memo[R][T];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while(1){
        scanf("%d %d",&A,&B);
        
        if(A==0 && B==0) break;
        
        for(int i=A;i>=0;i--)
            for(int j=B;j>=0;j--) memo[i][j]=-1.0;
        
        printf("%.3f\n",prob(A,B));
    }
    
    return 0;
}
