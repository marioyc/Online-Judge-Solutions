#include <iostream>

using namespace std;

int v[]={50,25,10,5,1}; 
int memo[7850][4];

int f(int a, int b)
{
    if(a==0) return 1;
    if(a<0) return 0;
    if(b>4) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    int x=f(a-v[b],b)+f(a-v[b+1],b+1)+f(a-v[b+2],b+2)+f(a,b+3);
    memo[a][b]=x;
    return x;
}

int main(){
    int x;
    memset(memo,-1,sizeof(memo));
    while(cin>>x)
        cout<<f(x,0)<<endl;
    return 0;
}
