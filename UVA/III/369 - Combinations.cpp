#include<iostream>

using namespace std;

long long memo[101][101];

long long C(int a, int b){
    if(b==0) return 1;
    if(a==b) return 1;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    memo[a][b]=C(a-1,b)+C(a-1,b-1);
    return memo[a][b];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int n,k;
    
    memset(memo,-1,sizeof(memo));
    
    while(1){
        cin>>n>>k;
        
        if(n==0 && k==0) break;
        
        cout<<n<<" things taken "<<k<<" at a time is "<<C(n,k)<<" exactly."<<endl;
    }
    
    return 0;
}
