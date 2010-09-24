#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

bool solved;
vector<int> v;
bool M[11][11];
bool X[11][11];
int N;
int cont;

void b(int a)
{
    if(cont==2*(N+1)){
        solved=true;
        return;
    }
    
    if(v[a]>=2) return;
    
    for(int i=0;i<N+1;i++){
        if(solved) return;
        if(M[a][i] && !X[a][i] && v[i]<2){
            v[a]++;
            v[i]++;
            X[a][i]=true;
            X[i][a]=true;            
            cont+=2;
                        
            b(i);
            
            v[a]--;
            v[i]--;
            X[a][i]=false;
            X[i][a]=false;
            cont-=2;
        }
    }
    return;
}

int main(){    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    string s;
    
    int ax;
    int cnt=1;
    
    while(cin>>N){
        if(N==0) break;
        getline(cin,s);
        
        memset(M,false,sizeof(M));
        
        for(int i=1;i<=N;i++){
            getline(cin,s); 
            istringstream is(s);
            while(is>>ax){
                M[i][ax]=true;
                M[ax][i]=true;
            }
        }
        
        v.clear();
        v.resize(N+1);
        for(int i=0;i<N+1;i++) v[i]=0;
        
        solved=false;
        cont=0;
        memset(X,false,sizeof(X));
        b(0);
        if(solved) cout<<"Case "<<cnt<<": Granny can make the circuit."<<endl;
        else cout<<"Case "<<cnt<<": Granny can not make the circuit."<<endl;
        cnt++;
    }
    return 0;
}
