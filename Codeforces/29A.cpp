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
    
    int n;
    
    cin >> n;
    
    int x[n],d[n];
    
    for(int i = 0;i < n;++i)
        cin >> x[i] >> d[i];
    
    for(int i = 0;i < n;++i)
        for(int j = i + 1;j < n;++j)
            if(x[i] + d[i] == x[j] && x[j] + d[j] == x[i]){
                cout << "YES\n";
                return 0;
            }
    
    cout << "NO\n";
    
    return 0;
}
