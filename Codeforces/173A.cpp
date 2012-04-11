#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    char s1[1001],s2[1001];
    
    scanf("%s %s",s1,s2);
    
    int L1 = strlen(s1),L2 = strlen(s2);
    int L = L1 * L2;
    
    int sum1 = 0,sum2 = 0;
    
    for(int i = 0;i < L;++i){
        if(s1[i % L1] == s2[i % L2]) ;
        else{
            if(s1[i % L1] == 'R' && s2[i % L2] == 'S') ++sum1;
            else if(s1[i % L1] == 'S' && s2[i % L2] == 'P') ++sum1;
            else if(s1[i % L1] == 'P' && s2[i % L2] == 'R') ++sum1;
            else ++sum2;
        }
    }
    
    int ans1 = n / L * sum1,ans2 = n / L * sum2;
    
    n %= L;
    
    for(int i = 0;i < n;++i){
        if(s1[i % L1] == s2[i % L2]) ;
        else{
            if(s1[i % L1] == 'R' && s2[i % L2] == 'S') ++ans1;
            else if(s1[i % L1] == 'S' && s2[i % L2] == 'P') ++ans1;
            else if(s1[i % L1] == 'P' && s2[i % L2] == 'R') ++ans1;
            else ++ans2;
        }
    }
    
    printf("%d %d\n",ans2,ans1);
    
    return 0;
}
