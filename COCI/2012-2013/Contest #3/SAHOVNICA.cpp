#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int R,C,A,B;
char M[101][101];

void paint(int r, int c, int color){
    for(int i = 0;i < A;++i)
        for(int j = 0;j < B;++j)
            M[r + i][c + j] = (color == 0? 'X' : '.');
}

int main(){
    ios::sync_with_stdio(0);
    
    scanf("%d %d %d %d",&R,&C,&A,&B);
    memset(M,0,sizeof M);
    
    for(int i = 0,c = 0;i < R;++i,c ^= 1)
        for(int j = 0,c2 = c;j < C;++j, c2 ^= 1)
            paint(A * i,B * j,c2);
    
    for(int i = 0;i < R*A;++i) puts(M[i]);
    
    return 0;
}
