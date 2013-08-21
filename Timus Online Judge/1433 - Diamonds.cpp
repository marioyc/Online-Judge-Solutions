#include <cstdio>

using namespace std;

int ind[][4] = {
    {0,1,2,3},{0,2,3,1},{0,3,1,2},
    {1,0,3,2},{1,3,2,0},{1,2,0,3},
    {2,0,1,3},{2,1,3,0},{2,3,0,1},
    {3,0,2,1},{3,2,1,0},{3,1,0,2}
};

int main(){
    char s[5],s2[5];
    
    scanf("%s %s",s,s2);
    
    bool eq = false;
    
    for(int i = 0;i < 12 && !eq;++i){
        eq = true;
        
        for(int j = 0;j < 4;++j)
            if(s[j] != s2[ ind[i][j] ])
                eq = false;
    }
    
    puts(eq? "equal" : "different");
    
    return 0;
}
