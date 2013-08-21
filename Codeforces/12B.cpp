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

int main(){
    ios::sync_with_stdio(0);
    
    string s,s2;
    
    cin >> s >> s2;
    
    string ans = s;
    
    sort(s.begin(),s.end());
    
    do{
        if(s[0] != '0')
            ans = min(ans,s);
    }while(next_permutation(s.begin(),s.end()));
    
    if(s2 == ans) cout << "OK\n";
    else cout << "WRONG_ANSWER\n";
    
    return 0;
}
