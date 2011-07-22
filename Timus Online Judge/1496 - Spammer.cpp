#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    string s[100];
    
    cin >> N;
    
    for(int i = 0;i < N;++i)
        cin >> s[i];
    
    sort(s,s + N);
    
    for(int i = 0,j;i < N;i = j){
        j = i;
        
        while(j < N && s[j] == s[i]) ++j;
        
        if(j-i > 1) cout << s[i] << endl;
    }
    
    return 0;
}
