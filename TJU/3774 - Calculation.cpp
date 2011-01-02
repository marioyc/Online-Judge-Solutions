#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    int x;
    char c;
    
    while(cin>>line){
        vector<int> num;
        vector<char> op;
        
        istringstream is(line);
        
        is>>x;
        num.push_back(x);
        
        while(is>>c){
            is>>x;
            op.push_back(c);
            num.push_back(x);
        }
        
        num.push_back(0);
        op.push_back('+');
        
        int N = num.size();
        long long ans = 0,tmp = num[0];
        
        for(int i = 1,sign = 1;i<N;++i){
            if(op[i-1]=='-' || op[i-1]=='+'){
                ans += sign*tmp;
                tmp = num[i];
                if(op[i-1]=='-') sign = -1;
                else sign = 1;
            }else{
                if(op[i-1]=='*') tmp *= num[i];
                else tmp /= num[i];
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
