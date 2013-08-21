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
    
    int n,m,v;
    
    cin >> n >> m >> v;
    
    int x = -1;
    
    if(m >= n - 1){
        for(int i = 1;n - 1 - i > 0;++i){
            if((long long)(i + 1) * i / 2 + (long long)(n - i) * (n - 1 - i) / 2 >= m){
                x = i;
                break;
            }
        }
    }
    
    if(x == -1) cout << -1 << '\n';
    else{
        int y = n - 1 - x;
        int id[n - 1];
        
        for(int i = 1,j = 0;i <= n;++i)
            if(i != v) id[j++] = i;
        
        for(int i = 0;i + 1 < x;++i)
            cout << id[i] << " " << id[i + 1] << '\n';
        cout << id[x - 1] << " " << v << '\n';
        
        for(int i = 0;i + 1 < y;++i)
            cout << id[x + i] << " " << id[x + i + 1] << '\n';
        cout << id[n - 2] << " " << v << '\n';
        
        m -= n - 1;
        
        for(int i = 0;i < x && m > 0;++i)
            for(int j = i + 2;j < x && m > 0;++j){
                cout << id[i] << " " << id[j] << '\n';
                --m;
            }
        
        for(int i = 0;i < y && m > 0;++i)
            for(int j = i + 2;j < y && m > 0;++j){
                cout << id[x + i] << " " << id[x + j] << '\n';
                --m;
            }
        
        for(int i = 0;i < x - 1 && m > 0;++i){
            cout << id[i] << " " << v << '\n';
            --m;
        }
        
        for(int i = 0;i < y - 1 && m > 0;++i){
            cout << id[x + i] << " " << v << '\n';
            --m;
        }
    }
    
    return 0;
}
