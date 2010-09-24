#include<cstdio>
#include<queue>
#include<map>

using namespace std;

int M[1000][1001];
bool visited[1000][1000];

int main(){    
    int R,C,cont=0;
    
    scanf("%d %d\n",&R,&C);
    
    
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++) scanf("%d",&M[i][j]);
    for(int i=0;i<R;i++) fill(visited[i],visited[i]+C,false);
    
    queue< pair<int, int> > Q;
    int di[]={1,-1,0,0,1,1,-1,-1};
    int dj[]={0,0,1,-1,1,-1,1,-1};
    int r,c,r2,c2;
    
    for(int i=0;i<R;i++)
        for(int j=C-1;j>=0;j--)
            if(!visited[i][j] && M[i][j]!=0){
                cont++;
                Q.push(make_pair(i,j));
                visited[i][j]=true;
                
                while(!Q.empty()){
                    r=Q.front().first;
                    c=Q.front().second;
                    Q.pop();
                    
                    for(int k=0;k<8;k++){
                        r2=r+di[k];
                        c2=c+dj[k];
                        
                        if(r2>=0 && r2<R  && c2>=0 && c2<C && !visited[r2][c2] && M[r2][c2]!=0){
                            visited[r2][c2]=true;
                            Q.push(make_pair(r2,c2));
                        }
                    }
                }
            }
    
    printf("%d\n",cont);
    
    return 0;
}
