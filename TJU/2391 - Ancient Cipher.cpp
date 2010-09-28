#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    char s1[101],s2[101];
    int a[101],b[101];
    
    scanf("%s %s",s1,s2);
    
    int n=strlen(s1);
    
    fill(a,a+n+1,0);
    fill(b,b+n+1,0);
    
    for(char c='A';c<='Z';c++) a[count(s1,s1+n,c)]++;
    for(char c='A';c<='Z';c++) b[count(s2,s2+n,c)]++;
    
    bool ok=true;
    
    for(int i=0;i<=n;i++) ok=ok && (a[i]==b[i]);
    
    if(ok) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
