/*
ID:zion_ba1
LANG:C++
TASK:echo
*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    freopen("echo.in","r",stdin);
    freopen("echo.out","w",stdout);
    
    char s1[81],s2[81];
    
    scanf("%s %s",s1,s2);
    
    int n=strlen(s1),m=strlen(s2),L=min(m,n),ans=0;
    bool valid;
    
    for(int i=0;i<L;i++){
        valid=true;
        for(int j=0;j<=i;j++) if(s1[j]!=s2[m-i-1+j]) valid=false;
        if(valid) ans=max(ans,i+1);
    }
    
    for(int i=0;i<L;i++){
        valid=true;
        for(int j=0;j<=i;j++) if(s2[j]!=s1[n-i-1+j]) valid=false;
        if(valid) ans=max(ans,i+1);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
