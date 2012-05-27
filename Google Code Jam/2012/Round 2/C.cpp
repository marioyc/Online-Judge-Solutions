#include <iostream>
#include <vector>

using namespace std;

int nxt[2001],h[2001];
bool valid;

void solve(int l, int r){
    if(r == l + 1) return;
    
    vector<int> v;
    v.push_back(l + 1);
    
    int pos = l + 1;
    
    while(pos != r){
        pos = nxt[pos];
        
        if(pos > r){
            valid = false;
            return;
        }
        
        v.push_back(pos);
    }
    
    int m = (h[l] - h[r]) / (r - l) - 1;
    
    for(int i = v.size() - 2;i >= 0;--i){
        h[ v[i] ] = h[ v[i + 1] ] + m * (v[i + 1] - v[i]);
        solve(v[i],v[i + 1]);
    }
}

int main(){
    int T,N;
    
    cin >> T;
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N;
        
        for(int i = 1;i < N;++i)
            cin >> nxt[i];
        
        valid = true;
        vector<int> v;
        v.push_back(1);
        h[1] = 1000000000;
        
        int pos = 1;
        
        while(pos != N){
            pos = nxt[pos];
            h[pos] = 1000000000;
            
            solve(v.back(),pos);
            v.push_back(pos);
        }
        
        cout << "Case #" << tc << ":";
        
        if(!valid) cout << " Impossible\n";
        else{
            for(int i = 1;i <= N;++i)
                cout << " " << h[i];
            
            cout << '\n';
        }
    }
    
    return 0;
}
