#include<iostream>

using namespace std;

int a[]={1,5,10,25,50};

long long memo[30001][5];

long long num(int x, int y){
    if(y>4) return 0;
    if(x==0) return 1;
    if(x<0) return 0;
    
    if(memo[x][y]!=-1) return memo[x][y];
    
    memo[x][y]=num(x,y+1) + num(x-a[y],y);
    
    return memo[x][y];
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int n;
    long long ax;

    memset(memo,-1,sizeof(memo));

    while(cin>>n){
        ax=num(n,0);
        if(ax!=1) cout<<"There are "<<ax<<" ways to produce "<<n<<" cents change."<<endl;
        else cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
    }

    return 0;
}
