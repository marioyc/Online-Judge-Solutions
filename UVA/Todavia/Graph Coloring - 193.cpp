#include<iostream>
#include<map>
#include<queue>

using namespace std;

int n,m,a,b,K;
bool visited[100];
int M[100][100];
int gr[100];
//int tot=0;
//int cont1,cont2;
pair<int, bool> P;
vector<int> v1;
vector<int> v2;
vector<int> v;

void dfs(int a){
    queue< pair<int, bool> > Q;
    v1.clear();
    v1.push_back(a);
    v2.clear();
    
    //cont1=1;cont2=0;
    
    visited[a]=true;
    
    for(int i=0;i<gr[a];i++)
        if(!visited[M[a][i]]) Q.push(make_pair(M[a][i],1));
    
    while(!Q.empty()){
        P=Q.front();
        Q.pop();
        visited[P.first]=true;
        
        if(P.second==0){
            //cont1++;
            v1.push_back(P.first);
        }
        else{
            //cont2++;
            v2.push_back(P.first);
        }
        
        for(int i=0;i<gr[P.first];i++)
            if(!visited[M[P.first][i]]) Q.push(make_pair(M[P.first][i],1-P.second));
    }
    if(v1.size()>=v2.size()){
        for(int i=0;i<v1.size();i++) v.push_back(v1[i]);
    }else{
        for(int i=0;i<v2.size();i++) v.push_back(v2[i]);
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    cin>>m;
    
    for(int i=0;i<m;i++){
        memset(visited,false,sizeof(visited));
        memset(gr,0,sizeof(gr));
        
        cin>>n>>K;
        
        for(int i=0;i<K;i++){
            cin>>a>>b;
            a--;
            b--;
            M[a][gr[a]++]=b;
            M[b][gr[b]++]=a;
        }
        
        v.clear();
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++) cout<<v[i]+1<<" ";
        cout<<endl;
    }
    
    return 0;
}
