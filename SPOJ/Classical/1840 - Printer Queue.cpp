#include<cstdio>

using namespace std;

int main(){    
    int T,n,m,aux,ans,pos,print;
    int priority[100];
    bool printed[100];
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d",&n,&m);
        
        for(int j=0;j<n;j++){
            scanf("%d",&priority[j]);
            printed[j]=false;
        }
        
        pos=0;
        ans=0;
        
        while(!printed[m]){
            print=-1;
            ans++;
            
            for(int i=0;i<n;i++){
                if(!printed[(pos+i)%n] && (print==-1 || priority[(pos+i)%n]>priority[print])) print=(pos+i)%n;
            }
            
            printed[print]=true;
            pos=print;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
