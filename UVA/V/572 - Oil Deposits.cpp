#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m,n,cont;
vector<string> v;
string s;
bool visited[100][100];

int di[]={1,1,1,-1,-1,-1,0,0};
int dj[]={1,0,-1,1,0,-1,1,-1};

void dfs(int a, int b){
    
    
    int I,J;
    
    for(int i=0;i<8;i++){
        I=a+di[i];
        J=b+dj[i];
        if(I>=0 && I<m && J>=0 && J<n && !visited[I][J]){
            visited[I][J]=1;
            if(v[I][J]=='@') dfs(I,J);
        }
    }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    while(1){
        cin>>m>>n;
        if(m==0) break;  
        
        v.clear();
        
        for(int i=0;i<m;i++){
            cin>>s;
            v.push_back(s);
        }
        
        cont=0;
        memset(visited,0,sizeof(visited));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    visited[i][j]=1;
                    if(v[i][j]=='@'){
                        cont++;
                        dfs(i,j);
                    }
                }
            }
        }
        
        cout<<cont<<endl;
    }
}
