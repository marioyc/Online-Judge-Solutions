#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int main(){
    int N,M,a[100][100],mn,mx,x,r,c,r2,c2;
    bool visited[100][100],solved;
    pair<int, int> aux;
    
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    
    while(1){
        scanf("%d %d",&N,&M);
        if(N<0) break;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&a[i][j]);
                if(i==0 && j==0) mn=mx=a[i][j];
                else{
                    mn<?=a[i][j];
                    mx>?=a[i][j];
                }
            }
        }
        
        x=mx-mn;
        
        if(x==0) printf("At least one pattern exists.\n");
        else{
            solved=false;
            for(int k=1;k<=x && !solved;k++){
                if(x%k==0){
                    queue< pair<int, int> > Q;
                    
                    for(int i=0;i<N;i++){
                        for(int j=0;j<M;j++){
                            if(a[i][j]==mn){
                                visited[i][j]=true;
                                Q.push(make_pair(i,j));
                            }else visited[i][j]=false;
                        }
                    }
                    
                    while(!Q.empty()){
                        aux=Q.front();
                        Q.pop();
                        
                        r=aux.first;
                        c=aux.second;
                        
                        if(a[r][c]==mx){
                            solved=true;
                            break;
                        }
                        
                        for(int y=0;y<4;y++){
                            r2=r+dr[y];
                            c2=c+dc[y];
                            
                            if(r2>=0 && r2<N && c2>=0 && c2<M && !visited[r2][c2] && a[r2][c2]==a[r][c]+k){
                                visited[r2][c2]=true;
                                Q.push(make_pair(r2,c2));
                            }
                        }
                    }
                }
            }
            
            if(solved) printf("At least one pattern exists.\n");
            else printf("No pattern can be found.\n");
        }
    }
    
    return 0;
}
