#include <cstdio>

using namespace std;

int main(){
    int N;
    char s[1000][3];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%s\n",s[i]);
    
    char c = getchar();
    
    for(int i = 0;i < N;++i)
        if(s[i][0] == c)
            puts(s[i]);
    
    return 0;
}
