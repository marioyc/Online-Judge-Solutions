#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<sstream>

using namespace std;

int lake[99][99];
vector<int> area;
vector<string> grid;

int di[]={-1,-1,-1,0,0,1,1,1};
int dj[]={1,0,-1,1,-1,1,0,-1};

void bfs(int a, int b){
    int cont=0,I,J,n=area.size();
    queue< pair<int, int> > Q;
    pair<int, int> P;
    
    Q.push(make_pair(a,b));
    lake[a][b]=n;
    
    while(!Q.empty()){
        P=Q.front();
        Q.pop();
        
        cont++;
        
        for(int i=0;i<8;i++){
            I=P.first+di[i];
            J=P.second+dj[i];
            
            if(I>=0 && I<grid.size() && J>=0 && J<grid[0].size() &&lake[I][J]==-1 && grid[I][J]=='W'){
                lake[I][J]=n;
                Q.push(make_pair(I,J));
            }
        }
    }
    
    area.push_back(cont);
}

int main(){
    int T,I,J,n,m;
    string s;
    
    cin>>T;
    getline(cin,s);
    getline(cin,s);
        
    for(int caso=1;caso<=T;caso++){
        grid.clear();
        
        while(1){
            getline(cin,s);
            if(s[0]!='W' && s[0]!='L') break;
            grid.push_back(s);
        }
        
        n=grid.size();
        m=grid[0].size();
        
        memset(lake,-1,sizeof(lake));
        area.clear();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(lake[i][j]==-1 && grid[i][j]=='W'){
                    bfs(i,j);
                }
            }
        }
        
        istringstream is(s);
        is>>I>>J;
        if(lake[I-1][J-1]==-1) cout<<0<<endl;
        else cout<<area[lake[I-1][J-1]]<<endl;
        
        while(getline(cin,s)){
            if(s.empty()) break;
            
            istringstream is2(s);
            is2>>I>>J;
            if(lake[I-1][J-1]==-1) cout<<0<<endl;
            else cout<<area[lake[I-1][J-1]]<<endl;
        }
        
        if(caso!=T) cout<<endl;
    }
    
    return 0;
}
