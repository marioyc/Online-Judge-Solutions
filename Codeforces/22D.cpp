#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    pair<int, int> x[n];
    
    for(int i = 0;i < n;++i){
        cin >> x[i].first >> x[i].second;
        if(x[i].first < x[i].second) swap(x[i].first,x[i].second);
    }
    
    sort(x,x + n);
    int ans = 0;
    vector<int> sol;
    
    for(int i = 0,last = -100000;i < n;++i){
        if(last < x[i].second){
            last = x[i].first;
            sol.push_back(last);
            ++ans;
        }
    }
    
    cout << ans << '\n';
    
    for(int i = 0;i < ans;++i)
        cout << sol[i] << ' ';
    cout << '\n';
    
    return 0;
}
