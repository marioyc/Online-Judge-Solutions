#include<iostream>

using namespace std;

int a[10];
int C,N;

int memo[1000][10];

int f(int x, int y){
    if(x==0) return 0;
    
    if(y==N || x<0) return (1<<20);
    
    if(memo[x][y]!=-1) return memo[x][y];
    
    memo[x][y]=min(1+f(x-a[y],y),f(x,y+1));
    
    return memo[x][y];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>C>>N;
    
    for(int i=0;i<N;i++) cin>>a[i];
    
    for(int i=0;i<=C;i++)
        for(int j=0;j<N;j++) memo[i][j]=-1;
    
    cout<<f(C,0)<<endl;
    
    return 0;
}
