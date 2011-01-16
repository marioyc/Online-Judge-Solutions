#include <cstdio>

using namespace std;

char M[3][4];

bool check(){
    if(M[0][0]!=M[2][2]) return false;  
    if(M[0][1]!=M[2][1]) return false;
    if(M[0][2]!=M[2][0]) return false;  
    if(M[1][0]!=M[1][2]) return false;
    
    return true;
}

int main(){
    for(int i = 0;i<3;++i) scanf("%s",M[i]);
    
    if(check()) puts("YES");
    else puts("NO");
    
    return 0;
}
