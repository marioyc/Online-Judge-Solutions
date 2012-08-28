#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    string line;
    vector<int> p,e;
    int x;
    
    while(true){
        getline(cin,line);
        istringstream is(line);
        
        bool done = false;
        p.clear();
        e.clear();
        
        while(is >> x){
            if(x == 0) done = true;
            else{
                p.push_back(x);
                is >> x;
                e.push_back(x);
            }
        }
        
        if(done) break;
        
        int n = 1;
        
        for(int i = p.size() - 1;i >= 0;--i)
            for(int j = e[i] - 1;j >= 0;--j)
                n *= p[i];
        
        ++n;
        
        p.clear();
        e.clear();
        
        for(int i = 2;i <= n / i;++i){
            if(n % i == 0){
                int cont = 0;
                p.push_back(i);
                
                while(n % i == 0){
                    n /= i;
                    ++cont;
                }
                
                e.push_back(cont);
            }
        }
        
        if(n > 1){
            p.push_back(n);
            e.push_back(1);
        }
        
        bool first = true;
        
        for(int i = p.size() - 1;i >= 0;--i){
            if(!first) cout << ' ';
            first = false;
            
            cout << p[i] << ' ' << e[i];
        }
        
        cout << '\n';
    }
    
    return 0;
}
