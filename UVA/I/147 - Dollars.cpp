#include <iostream>
#include <iomanip>

using namespace std;

int v[]={10000,5000,2000,1000,500,200,100,50,20,10,5}; 
long long memo[30001][11];

long long f(int a, int b)
{
    if(a==0) return 1;
    if(a<0) return 0;
    if(b>10) return 0;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    long long x=f(a-v[b],b)+f(a,b+1);
    memo[a][b]=x;
    return x;
}
int main(){
    int x;
    string y;
    int aux;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    memset(memo,-1,sizeof(memo));
    while(true)
    {
        scanf("%d.", &x);
        //cin>>y;
        aux=(y[0]-'0')*10+(y[1]-'0');
        if(x==0 && aux==0) break;
        cout<<setw(3)<<setiosflags(ios::right)<<x<<"."<<y<<setw(17)<<setiosflags(ios::right)<<f(x*100+aux,0)<<endl;
    }
    return 0;
}
