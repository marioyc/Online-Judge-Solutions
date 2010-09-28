#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

char s[10001];
string ans[10000];

void generate(int &pos, int h){
    ans[h] += s[pos];
    --pos;
    
    if(islower(s[pos+1])) return;
    
    generate(pos,h+1);
    generate(pos,h+1);
}

int main(){
    int T,L,pos;
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%s",s);
        L = strlen(s);
        fill(ans,ans+L,"");
        
        pos = L-1;
        generate(pos,0);
        
        for(int i=L-1;i>=0;--i) printf("%s",ans[i].c_str());
        printf("\n");
    }
    
    return 0;
}
