/*
ID:zion_ba1
LANG:C++
TASK:stroll
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main(){
    freopen("stroll.in","r",stdin);
    freopen("stroll.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int P; scanf("%d",&P);
    
    int children[P][2];
    
    for(int i=1,u,a,b;i<P;i++){
        scanf("%d %d %d",&u,&a,&b);
        u--; a--; b--;
        children[u][0]=a;
        children[u][1]=b;
    }
    
    int ans=0;
    
    queue< pair<int, int> > Q;
    Q.push(make_pair(0,0));
    
    while(!Q.empty()){
        pair<int,int> aux=Q.front();
        Q.pop();
        
        if(aux.first==-1){
            ans=aux.second;
            continue;
        }
        
        Q.push(make_pair(children[aux.first][0],aux.second+1));
        Q.push(make_pair(children[aux.first][1],aux.second+1));
    }
    
    printf("%d\n",ans);
    
    return 0;
}
