#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N,mm,ss,d;
    long long tm[100];
    string name[100],t;
    
    cin >> N;
    
    for(int i = 0;i < N;++i){
        cin >> name[i] >> t;
        
        int L = t.size();
        
        for(int j = 0;j < L;++j)
            if(t[j] == ':' || t[j] == '.')
                t[j] = ' ';
        
        istringstream is(t);
        is >> mm >> ss >> d;
        
        tm[i] = 600LL * mm + 10 * ss + d;
    }
    
    vector<string> ans;
    
    for(int i = 0;i < N;++i){
        bool leader = true;
        
        for(int j = 0;j < N;++j)
            if(tm[j] < tm[i] && tm[j] + 300*j < tm[i] + 300*i)
                leader = false;
        
        if(leader) ans.push_back(name[i]);
    }
    
    sort(ans.rbegin(),ans.rend());
    
    cout << ans.size() << endl;
    
    for(int i = ans.size()-1;i >= 0;--i)
        cout << ans[i] << endl;
    
    return 0;
}
