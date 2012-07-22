#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int A,a,B,b,R;
    
    scanf("%d %d %d %d %d %d",&A,&a,&B,&b,&R);
    
    if(A + B <= R || (min(A,B) <= max(a,b) && max(A,B) <= R)) puts("Yes");
    else puts("No");
    
    return 0;
}
