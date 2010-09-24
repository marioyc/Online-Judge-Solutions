#include<iostream>
#include<set>
#include<vector>

using namespace std;

bool M[10];
int P,T,aux;
int memo[11][999];

int f(int a, int b, int x){
    
    if(a==0){
        if(b==0){
            return 1;
        }
        else return 0;
    }
    
    if(memo[a][b]!=-1) return memo[a][b];
    
    int total=0;
    
    if(a!=P && M[0]) total=(total+f(a-1,b,x*10+0)%1000001)%1000001;
    
    for(int i=1;i<9;i++){
        if(M[i]){
            aux=i;            
            for(int j=0;j<a-1;j++) aux=(aux*10)%T;                
            
            aux=(b-aux)%T;
            while(aux<0) aux+=T;
            
            total=(total+f(a-1,aux,x*10+i)%1000001)%1000001;
        }
    }
    
    memo[a][b]=total;
    
    return total;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N;
    
    cin>>N;
    
    set<int> digits;
    set<int> :: iterator it;
    
    for(int i=0;i<N;i++){
        cin>>aux;
        digits.insert(aux);
    }
    
    memset(M,false,sizeof(M));
    memset(memo,-1,sizeof(memo));
    
    for(it=digits.begin();it!=digits.end();it++) M[(*it)]=true;
    
    cin>>P>>T;
    
    cout<<f(P,0,0)<<endl;
        
    return 0;
}
