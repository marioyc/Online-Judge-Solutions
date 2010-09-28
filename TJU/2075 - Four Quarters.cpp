#include<iostream>
#include<iomanip>

using namespace std;

double memo[20][61][61];

int N;

double fA(int n, int A, int B){
    if(n==N){
        if(A>B) return 1.0;
        return 0.0;
    }
    
    if(memo[n][A][B]>-0.5) return memo[n][A][B];
    
    memo[n][A][B]=0.0625*(3*fA(n+1,A+1,B)+2*fA(n+1,A+1,B-1)+fA(n+1,A+2,B-1)+2*fA(n+1,A,B+1)+6*fA(n+1,A,B)+fA(n+1,A-1,B+2)+fA(n+1,A,B-1));
    
    return memo[n][A][B];
}

double fB(int n, int A, int B){
    if(n==N){
        if(A<B) return 1.0;
        return 0.0;
    }
    
    if(memo[n][A][B]>-0.5) return memo[n][A][B];
    
    memo[n][A][B]=0.0625*(3*fB(n+1,A+1,B)+2*fB(n+1,A+1,B-1)+fB(n+1,A+2,B-1)+2*fB(n+1,A,B+1)+6*fB(n+1,A,B)+fB(n+1,A-1,B+2)+fB(n+1,A,B-1));
    
    return memo[n][A][B];
}

int main(){    
    printf("Round   A wins    B wins    Tie\n");
    
    double A,B;
    
    for(int i=1;i<=20;i++){
        N=i;
        
        memset(memo,-1,sizeof(memo));
        A=fA(0,20,20)*100;
        
        memset(memo,-1,sizeof(memo));
        B=fB(0,20,20)*100;
        
        cout<<setw(5)<<setiosflags(ios::right)<<i<<"   ";
        cout<<setw(7)<<setprecision(4)<<fixed<<A<<"%  ";
        cout<<setw(7)<<setprecision(4)<<fixed<<B<<"%  ";
        cout<<setw(7)<<setprecision(4)<<fixed<<(100-A-B)<<"%";
        cout<<endl;
    }
    
    return 0;
}
