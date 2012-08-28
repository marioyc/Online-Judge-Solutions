#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    string line,s;
    int n,a[400];
    
    while(true){
        getline(cin,line);
        
        if(line == "#") break;
        
        istringstream is(line);
        
        string name;
        
        while(is >> s){
            if(s[0] >= 'a' && s[0] <= 'z') name += (char)(s[0] + 'A' - 'a');
            else name += s[0];
        }
        
        cin >> n;
        
        int sum = 0;
        
        for(int i = 0;i < n;++i){
            cin >> a[i];
            a[n + i] = a[i];
            sum += a[i];
        }
        
        getline(cin,line);
        
        int ans = n;
        
        for(int i = 0;i < n;++i){
            int sum2,cont = 0;
            
            for(int j = 0;j < n;){
                int e = j;
                sum2 = 0;
                ++cont;
                
                while(e < n){
                    sum2 += a[i + e];
                    ++e;
                    
                    if(sum * (e - j) == sum2 * n) break;
                }
                
                j = e;
            }
            
            ans = min(ans,n - cont);
        }
        
        cout << name << ": " << ans << '\n';
    }
    
    return 0;
}
