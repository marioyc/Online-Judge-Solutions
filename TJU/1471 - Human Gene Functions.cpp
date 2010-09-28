#include<iostream>
#include<algorithm>

using namespace std;

char a[101];
char b[101];
int n,m;
int dp[101][101];

int score(char c1, char c2){
    if(c1==c2) return 5;
    if(c1=='A'){
        if(c2=='C') return -1;
        if(c2=='G') return -2;
        if(c2=='T') return -1;
        if(c2==' ') return -3;
    }
    if(c1=='C'){
        if(c2=='A') return -1;
        if(c2=='G') return -3;
        if(c2=='T') return -2;
        if(c2==' ') return -4;
    }
    if(c1=='G'){
        if(c2=='A') return -2;
        if(c2=='C') return -3;
        if(c2=='T') return -2;
        if(c2==' ') return -2;
    }
    if(c1=='T'){
        if(c2=='A') return -1;
        if(c2=='C') return -2;
        if(c2=='G') return -2;
        if(c2==' ') return -1;
    }    
    if(c1==' '){
        if(c2=='A') return -3;
        if(c2=='C') return -4;
        if(c2=='G') return -2;
        if(c2=='T') return -1;
    }
}

int f(int p1, int p2){
    if(p1==n && p2==m) return 0;
    
    if(dp[p1][p2]!=-1) return dp[p1][p2];
    
    if(p1==n) dp[p1][p2]=f(p1,p2+1)+score(' ',b[p2]);    
    else if(p2==m) dp[p1][p2]=f(p1+1,p2)+score(a[p1],' ');    
    else dp[p1][p2]=max(max(f(p1,p2+1)+score(' ',b[p2]),f(p1+1,p2)+score(a[p1],' ')),f(p1+1,p2+1)+score(a[p1],b[p2]));
    
    return dp[p1][p2];
}

int main(){
    int T;
    
    cin>>T;
    
    for(int caso=1;caso<=T;caso++){
        cin>>n>>a;
        cin>>m>>b;
        
        memset(dp,-1,sizeof(dp));
        
        printf("%d\n",f(0,0));
    }
    
    return 0;
}
