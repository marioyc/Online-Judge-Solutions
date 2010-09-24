#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;

bool visited[105];

vector< vector<int> > v;
int elim;

int dfs(int a){
    int cont=1;
    visited[a]=true;
    
    
    for(int i=0;i<v[a].size();i++){
        if(!visited[v[a][i]] && v[a][i]!=elim) cont+=dfs(v[a][i]);
    }
    
    return cont;
}

int main(){

    int N,m,x;
    string s;
    int tot;
    
    while(true){
        cin>>N;
        if(N==0) break;
        
        v.clear();
        v.resize(N+1);
        
        getline(cin,s);
        while(getline(cin,s)){
            istringstream is(s);
            is>>m;
            if(m==0) break;
            while(is>>x){
                v[m].push_back(x);
                v[x].push_back(m);
            }
        }
        tot=0;
        memset(visited,false,sizeof(visited));
        elim=1;
        if(N>1 && dfs(2)!=N-1) tot++;
        for(int i=2;i<=N;i++){
            memset(visited,false,sizeof(visited));
            elim=i;
            if(dfs(1)!=N-1) tot++;
        }
        
        cout<<tot<<endl;
    }

    return 0;
}
