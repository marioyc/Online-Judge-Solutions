#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
    int val;
    
    node(){}
    
    node(int _val){
        val = _val;
    }
    
    bool operator < (node X)const{
        return abs(val)>abs(X.val);
    }
};

int main(){
    char type;
    int val;
    
    priority_queue<node> Q;
    
    while(cin>>type){
        if(type=='r') Q.pop();
        else{
            cin>>val;
            Q.push(node(val));
        }
    }
    
    long long ans = -1,aux;
    
    while(!Q.empty()){
        aux = Q.top().val;
        Q.pop();
        ans = aux*aux;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
