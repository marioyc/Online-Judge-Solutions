#include<iostream>

using namespace std;

long long memo[2001][10];
int pot2[]={1,2,4,8,16,32,64,128,256,512,1024};
int M;

long long f(int a, int b){
    if(b==0) return 1;
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    long long aux=0;
    
    for(int i=2*a;i*pot2[b-1]<=M;i++)
        aux+=f(i,b-1);
    
    memo[a][b]=aux;
    
    return aux;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int C,N;
    
    long long ans;
    
    cin>>C;
    
    for(int caso=0;caso<C;caso++){
        cin>>N>>M;
        
        for(int i=1;i<=M;i++)
            for(int j=1;j<N;j++) memo[i][j]=-1;
        
        ans=0;
        
        for(int i=1;i*pot2[N-1]<=M;i++) ans+=f(i,N-1);
        
        cout<<"Case "<<caso+1<<": n = "<<N<<", m = "<<M<<", # lists = "<<ans<<endl;
    }
    
    return 0;
}
