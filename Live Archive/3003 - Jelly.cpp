#include <cstdio>

using namespace std;

int main(){
    char name[100][11];
    int N,vol[100];
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i = 0,x,y,z;i<N;++i){
            scanf("%s %d %d %d",name[i],&x,&y,&z);
            vol[i] = x*y*z;
        }
        
        int mn = 0,mx = 0;
        
        for(int i = 1;i<N;++i){
            if(vol[i]<vol[mn]) mn = i;
            if(vol[i]>vol[mx]) mx = i;
        }
        
        if(vol[mn]==vol[mx]) puts("No child has lost jelly.");
        else printf("%s has lost jelly to %s.\n",name[mn],name[mx]);
    }
    
    return 0;
}
