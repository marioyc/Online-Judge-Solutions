#include <cstdio>
#include <cmath>

using namespace std;

double triArea(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3){
    return fabs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)/2;
}

double quadArea(double &x1, double &y1, double &x2, double &y2, double &x3, double &y3, double &x4, double &y4){
    return triArea(x1,y1,x2,y2,x3,y3)+triArea(x3,y3,x4,y4,x1,y1);
}

int main(){
    int tc=1;
    double x[4],y[4],midx[4],midy[4],best,S,A1,A2,a1,a2,dif;
    bool zeroes=false;
    
    while(1){
        zeroes=true;
        
        for(int i=0;i<4;i++){
            scanf("%lf %lf",&x[i],&y[i]);
            if(x[i]!=0 || y[i]!=0) zeroes=false;
        }
        
        if(zeroes) break;
        
        for(int i=0;i<4;i++){
            midx[i]=(x[i]+x[(i+1)&3])/2;
            midy[i]=(y[i]+y[(i+1)&3])/2;
        }
        
        a1=triArea(x[0],y[0],x[3],y[3],x[2],y[2]);
        a2=triArea(x[0],y[0],x[1],y[1],x[2],y[2]);
        best=fabs(a1-a2); A1=a1; A2=a2;
        
        a1=triArea(x[0],y[0],x[3],y[3],x[1],y[1]);
        a2=triArea(x[3],y[3],x[1],y[1],x[2],y[2]);
        if(fabs(a1-a2)<best){
            best=fabs(a1-a2);
            A1=a1;
            A2=a2;
        }
        
        a1=quadArea(midx[0],midy[0],x[0],y[0],x[3],y[3],midx[2],midy[2]);
        a2=quadArea(midx[0],midy[0],x[1],y[1],x[2],y[2],midx[2],midy[2]);
        if(fabs(a1-a2)<best){
            best=fabs(a1-a2);
            A1=a1;
            A2=a2;
        }
        
        a1=quadArea(midx[1],midy[1],x[1],y[1],x[0],y[0],midx[3],midy[3]);
        a2=quadArea(midx[1],midy[1],x[2],y[2],x[3],y[3],midx[3],midy[3]);
        if(fabs(a1-a2)<best){
            best=fabs(a1-a2);
            A1=a1;
            A2=a2;
        }
        
        S=quadArea(x[0],y[0],x[1],y[1],x[2],y[2],x[3],y[3]);
        
        for(int i=0;i<4;i++){
            a1=triArea(x[i],y[i],x[(i+1)&3],y[(i+1)&3],midx[(i+1)&3],midy[(i+1)&3]);
            a2=S-a1;
            if(fabs(a1-a2)<best){
                best=fabs(a1-a2);
                A1=a1;
                A2=a2;
            }
            
            a1=triArea(x[i],y[i],x[3-i],y[3-i],midx[(i+2)&3],midy[(i+2)&3]);
            a2=S-a1;
            if(fabs(a1-a2)<best){
                best=fabs(a1-a2);
                A1=a1;
                A2=a2;
            }
        }
        
        printf("Cake %d: ",tc++);
        if(A1<A2) printf("%.3f %.3f\n",A1,A2);
        else printf("%.3f %.3f\n",A2,A1);
    }
    
    return 0;
}
