#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char s[200001];
stack<char> S;

int main(){
    scanf("%s",s);
    
    int len = strlen(s);
    
    for(int i = 0;i<len;++i){
        char c = (S.empty()? 0 : S.top());
        if(c==s[i]) S.pop();
        else S.push(s[i]);
    }
    
    memset(s,0,sizeof(s));
    len = S.size();
    
    for(int i = 0;i<len;++i){
        s[len-1-i] = S.top();
        S.pop();
    }
    
    puts(s);
    
    return 0;
}
