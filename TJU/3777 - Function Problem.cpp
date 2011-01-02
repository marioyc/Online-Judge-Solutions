#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> solve(int A, int B, int C){
    vector<double> ret;
    double x;
    
    if(A!=0){
        int det = B*B-4*A*C;
        
        if(det>=0){
            if(det>0){
                x = (-B-sqrt(det))/2/A;
                if(x>=0 && x<=1000) ret.push_back(x);
            }
            
            x = (-B+sqrt(det))/2/A;
            if(x>=0 && x<=1000) ret.push_back(x);
        }
    }else if(B!=0){
        x = -(double)C/B;
        if(x>=0 && x<=1000) ret.push_back(x);
    }
    
    return ret;
}

double f(int A, int B, int C, double x){
    return A*x*x+B*x+C;
}

int main(){
    int T,A1,B1,C1,A2,B2,C2;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d %d %d",&A1,&B1,&C1,&A2,&B2,&C2);
        vector<double> sol = solve(A2-A1,B2-B1,C2-C1);
        
        sol.push_back(0);
        sol.push_back(1000);
        
        double ans = max(f(A1,B1,C1,0),f(A2,B2,C2,0)),x;
        
        if(A1!=0){
            x = -B1/2.0/A1;
            if(x>=0 && x<=1000) sol.push_back(x);
        }
        
        if(A2!=0){
            x = -B2/2.0/A2;
            if(x>=0 && x<=1000) sol.push_back(x);
        }
        
        sort(sol.begin(),sol.end());
        int n = sol.size();
        
        for(int i = 1;i<n;++i)
            ans = min(ans,max(f(A1,B1,C1,sol[i]),f(A2,B2,C2,sol[i])));
        
        printf("%.4f\n",ans);
    }
    
    return 0;
}
