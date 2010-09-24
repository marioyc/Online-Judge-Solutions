#include<queue>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

int N,key;
vector< vector<int> > v;
bool M[1000];

int dfs(int n){
    M[n]=1;
    int cont=1;
    
    queue<int> Q;
    
    for(int i=0;i<v[n].size();i++)
        if(v[n][i]!=key) Q.push(v[n][i]);
    
    while(!Q.empty()){
        n=Q.front();
        Q.pop();
        
        if(M[n]) continue;
        
        cont++; M[n]=1;
        
        for(int i=0;i<v[n].size();i++)
            if(v[n][i]!=key) Q.push(v[n][i]);
    }
    
    return cont;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int a,b,ax;
    string s;
    
    while(1){
        cin>>N;
        if(N==0) break;
        
        v.clear(); v.resize(N);
        
        getline(cin,s);
        
        while(1){
            getline(cin,s);
            istringstream is(s);
            
            is>>a;
            if(a==0) break;
            
            a--;
            
            while(is>>b){
                b--;
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        
        ax=0;
        ostringstream os;
        
        
        key=0;
        for(int i=0;i<N;i++) M[i]=0;
        if(dfs(1)!=N-1){
            os<<1<<" ";
            ax++;
        }
        
        for(int i=1;i<N;i++){
            key=i;
            for(int j=0;j<N;j++) M[j]=0;
            if(dfs(0)!=N-1){
                os<<i+1<<" ";
                ax++;
            }
        }
        s=os.str();
        if(!s.empty()) s.erase(s.size()-1,1);
        
        cout<<ax;
        if(ax!=0) cout<<" "<<s;
        cout<<endl;
    }
}
