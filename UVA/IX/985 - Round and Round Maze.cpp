#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int r,c;
    
    node(){
    }
    
    node(int _r, int _c){
        r=_r;
        c=_c;
    }
}Q[500*500*4],aux;

int start,size;
bool M[500][500][4],visited[4][500][500];

int main(){
    int R,C,l,r,c;
    bool solved;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int ind[26];
    ind['N'-'A']=0;ind['E'-'A']=1;ind['S'-'A']=2;ind['W'-'A']=3;
    
    char s[5];
    
    while(scanf("%d %d",&R,&C)==2){
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++){
                if(i==R-1 && j==C-1) continue;
                
                scanf("%s",s);
                l=strlen(s);
                
                for(int k=0;k<4;k++) M[i][j][k]=false;
                for(int k=0;k<l;k++) M[i][j][ind[s[k]-'A']]=true;
            }
        
        for(int i=0;i<4;i++)
            for(int j=0;j<R;j++)
                fill(visited[i][j],visited[i][j]+C,false);
        
        start=size=0;
        Q[size++]=node(0,0);
        visited[0][0][0]=true;
        
        solved=false;
        
        for(int i=0;size!=0 && !solved;i++){
            for(int j=size-1;j>=0;j--){
                r=Q[start].r;
                c=Q[start].c;
                start++;
                size--;
                
                if(r==R-1 && c==C-1){
                    printf("%d\n",i);
                    solved=true;
                    break;
                }
                
                for(int k=0;k<4;k++){
                    if(!M[r][c][k]) continue;
                    if(r+dr[(k+i)%4]>=0 && r+dr[(k+i)%4]<R && c+dc[(k+i)%4]>=0 && c+dc[(k+i)%4]<C && !visited[i%4][r+dr[(k+i)%4]][c+dc[(k+i)%4]]){
                        Q[start+size]=node(r+dr[(k+i)%4],c+dc[(k+i)%4]);
                        size++;
                        visited[i%4][r+dr[(k+i)%4]][c+dc[(k+i)%4]]=true;
                    }
                }
            }
        }
        
        if(!solved) printf("no path to exit\n");
    }
    
    return 0;
}
