#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct p{
    int x,y;
    
    p(){
    }    
    p(int a, int b){
        x=a;
        y=b;
    }
};

struct seg{
    p p1,p2;
    
    seg(p a, p b){
        p1.x=a.x;
        p1.y=a.y;
        p2.x=b.x;
        p2.y=b.y;
    }
};

int N,M;
vector<seg> v;

int area(p A, p B, p C){
    return A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
}

bool intersection(seg A, seg B){
    if(A.p1.x==B.p1.x && A.p1.y==B.p1.y) return false;
    if(A.p1.x==B.p2.x && A.p1.y==B.p2.y) return false;
    if(A.p2.x==B.p1.x && A.p2.y==B.p1.y) return false;
    if(A.p2.x==B.p2.x && A.p2.y==B.p2.y) return false;
    
    if(area(A.p1,B.p2,A.p2)*area(A.p1,B.p1,A.p2)<0 && area(B.p1,A.p2,B.p2)*area(B.p1,A.p1,B.p2)<0) return true;
    return false;
}

int di[]={1,1,-1,-1,2,2,-2,-2};
int dj[]={2,-2,2,-2,1,-1,1,-1};
int I,J;
bool unidos[21][21][21][21];
bool used[21][21];
bool visited[21][21];

bool dfs(){
    pair<int, int> P;
    memset(visited,false,sizeof(visited));
    
    for(int i=0;i<=N;i++){
        if(used[0][i] && !visited[0][i]){
            stack< pair<int, int> > S;
            
            S.push(make_pair(0,i));
            visited[0][i]=true;
            
            while(!S.empty()){
                P=S.top();
                S.pop();
                
                if(P.first==N) return true;
                
                for(int j=0;j<8;j++){
                    I=P.first+di[j];
                    J=P.second+dj[j];
                    
                    if(I>=0 && I<=N && J>=0 && J<=N && !visited[I][J] && unidos[P.first][P.second][I][J]){
                        visited[I][J]=true;
                        S.push(make_pair(I,J));
                    }
                }
            }
        }
    }
    
    return false;
}

int main(){    
    int x,y;
    bool ok;
    bool color[21][21];
    
    while(1){        
        cin>>N>>M;
        if(N==0) break;
        
        v.clear();
        
        memset(unidos,false,sizeof(unidos));
        memset(used,false,sizeof(used));
        
        for(int i=0;i<M;i++){
            cin>>x>>y;
            
            used[x][y]=true;
            color[x][y]=i%2;
            
            for(int j=0;j<8;j++){
                I=x+di[j];
                J=y+dj[j];
                
                if(I>=0 && I<=N && J>=0 && J<=N && used[I][J] && color[I][J]==i%2){
                    ok=true;
                    
                    for(int k=0;k<v.size();k++){
                        if(intersection(seg(p(x,y),p(I,J)),v[k])){
                            ok=false;
                            break;
                        }
                    }
                    
                    if(ok){
                        v.push_back(seg(p(x,y),p(I,J)));
                        if(i%2==0) unidos[x][y][I][J]=unidos[I][J][x][y]=true;
                    }
                }
            }
        }
        
        if(dfs()) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}
