/*
ID: zion_ba1
LANG: C++
TASK: barn1
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    freopen("barn1.in","r",stdin);
    freopen("barn1.out","w",stdout);
    
    int M,S,C,x;
    bool used[200];
    
    scanf("%d %d %d",&M,&S,&C);
    
    fill(used,used+S,false);
    
    for(int i=0;i<C;i++){
        scanf("%d",&x);
        used[x-1]=true;
    }
    
    int s,e;
    int no_cow[200],sz=0;
    
    for(int i=0;i<S;i++)
        if(used[i]){
            s=i;
            break;
        }
    
    for(int i=S-1;i>=0;i--)
        if(used[i]){
            e=i+1;
            break;
        }
    
    int total=e-s;
    
    int i=s;
    
    while(i<e){
        while(i<e && used[i]) i++;
        
        if(i<e && !used[i]) no_cow[sz++]=0;
        
        while(i<e && !used[i]){
            no_cow[sz-1]++;
            i++;
        }
    }
    
    sort(no_cow,no_cow+sz);
    
    for(int j=0;j<min(sz,M-1);j++) total-=no_cow[sz-1-j];
    
    printf("%d\n",total);
    
    return 0;
}
