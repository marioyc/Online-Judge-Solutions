/*
ID:zion_ba1
LANG:C++
TASK:rplow
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    freopen("rplow.in","r",stdin);
    freopen("rplow.out","w",stdout);
    
    int X,Y,I,xll,yll,xur,yur;
    scanf("%d %d %d",&X,&Y,&I);
    
    bool M[X][Y];
    for(int i=0;i<X;i++) fill(M[i],M[i]+Y,false);
    
    for(int i=0;i<I;i++){
        scanf("%d %d %d %d",&xll,&yll,&xur,&yur);
        
        for(int x=xll-1;x<xur;x++) fill(M[x]+yll-1,M[x]+yur,true);
    }
    
    int ans=0;
    
    for(int i=0;i<X;i++) ans+=count(M[i],M[i]+Y,true);
    
    printf("%d\n",ans);
    
    return 0;
}
