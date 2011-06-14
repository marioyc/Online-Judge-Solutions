#include <cstdio>
#include <cstring>

using namespace std;

char s1[1000002],s2[1000002];
int to[26],to2[26];

int main(){
    int n;
    
    scanf("%d %s %s",&n,s1,s2);
    
    memset(to,-1,sizeof(to));
    memset(to2,-1,sizeof(to2));
    
    bool valid = true;
    
    for(int i = 0;i < n;++i){
        int c1 = s1[i]-'a',c2 = s2[i]-'a';
        
        if(to[c1] == -1) to[c1] = c2;
        else if(to[c1] != c2) valid = false;
        
        if(to2[c2] == -1) to2[c2] = c1;
        else if(to2[c2] != c1) valid = false;
    }
    
    puts(valid? "DA" : "NE");
    
    return 0;
}
