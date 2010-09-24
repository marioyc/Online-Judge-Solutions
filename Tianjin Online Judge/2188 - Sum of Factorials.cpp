#include<iostream>
#include<map>

using namespace std;

map< pair<int, int> , bool > M;

int fac[]={1,2,6,24,120,720,5040,40320,362880,3628800};

void sums(int n, int x, int y){
    if(n==10){
        M[make_pair(x,y)]=1;
        return;
    }
    
    sums(n+1,x+fac[n],y);
    sums(n+1,x,y+fac[n]);
    sums(n+1,x,y);
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int x,y;
    
    sums(0,0,0);
    
    while(1){
        cin>>x>>y;
        
        if(x==0 && y==0) break;
        
        if(M[make_pair(x,y)]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
