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

int a,b,c,d,n;
char ans[101][101];

void print(){
    int r = max(b,d);
    
    for(int i = 0;i < r;++i)
        cout << ans[i] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> a >> b >> c >> d >> n;
    
    int x[n];
    for(int i = 0;i < n;++i)
        cin >> x[i];
    
    int r1 = min(b,d),c1 = a + c;
    int r2 = max(b,d) - r1,c2 = (b > d? a : c);
    
    int pcheck;
    
    for(int i = 0,sum = 0;i < n;++i){
        sum += x[i];
        
        if(sum == r1 * c1){
            pcheck = -1;
            break;
        }else if(sum > r1 * c1){
            pcheck = i;
            break;
        }
    }
    
    char M1[r1][c1],M2[r2][c2];
    int pos = 0;
    
    for(int i = 0;i < r1;++i){
        for(int j = 0;j < c1;++j){
            if(i & 1) M1[i][c1 - 1 - j] = 'a' + pos;
            else M1[i][j] = 'a' + pos;
            --x[pos];
            if(x[pos] == 0) ++pos;
        }
    }
    
    for(int i = 0;i < r2;++i){
        for(int j = 0;j < c2;++j){
            if(i & 1) M2[i][c2 - 1 - j] = 'a' + pos;
            else M2[i][j] = 'a' + pos;
            --x[pos];
            if(x[pos] == 0) ++pos;
        }
    }
    
    for(int i = 0;i < r1 + r2;++i)
        for(int j = 0;j < c1;++j)
            ans[i][j] = '.';
    
    cout << "YES\n";
    
    for(int rev1 = 0;rev1 < 2;++rev1){
        if(rev1){
            for(int i = 0;i < r1;++i)
                for(int j = 0;j < c1;++j)
                    ans[i][j] = M1[i][c1 - 1 - j];
        }else{
            for(int i = 0;i < r1;++i)
                for(int j = 0;j < c1;++j)
                    ans[i][j] = M1[i][j];
        }
        
        for(int rev2 = 0;rev2 < 2;++rev2){
            if(rev2){
                if(b > d){
                    for(int i = 0;i < r2;++i)
                        for(int j = 0;j < c2;++j)
                            ans[r1 + i][j] = M2[i][c2 - 1 - j];
                }else{
                    for(int i = 0;i < r2;++i)
                        for(int j = 0;j < c2;++j)
                            ans[r1 + i][a + j] = M2[i][c2 - 1 - j];
                }
            }else{
                if(b > d){
                    for(int i = 0;i < r2;++i)
                        for(int j = 0;j < c2;++j)
                            ans[r1 + i][j] = M2[i][j];
                }else{
                    for(int i = 0;i < r2;++i)
                        for(int j = 0;j < c2;++j)
                            ans[r1 + i][a + j] = M2[i][j];
                }
            }
            
            if(pcheck == -1){
                print();
                return 0;
            }
            
            bool found = false;
            
            if(b > d){
                for(int i = 0;i < a;++i)
                    if(ans[r1 - 1][i] == 'a' + pcheck && ans[r1][i] == 'a' + pcheck)
                        found = true;
            }else{
                for(int i = a;i < a + c;++i)
                    if(ans[r1 - 1][i] == 'a' + pcheck && ans[r1][i] == 'a' + pcheck)
                        found = true;
            }
            
            if(found){
                print();
                return 0;
            }
        }
    }
    
    return 0;
}
