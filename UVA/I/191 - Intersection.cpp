#include<cstdio>
#include<algorithm>

using namespace std;

int area(int x1, int y1, int x2, int y2, int x3, int y3){
    return x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
}

bool intersection(int &x1, int &y1, int &x2, int &y2, int &x3, int &y3, int &x4, int &y4){
    int a1,a2,a3,a4;

    a1=area(x1,y1,x3,y3,x2,y2);
    a2=area(x1,y1,x4,y4,x2,y2);
    a3=area(x3,y3,x1,y1,x4,y4);
    a4=area(x3,y3,x2,y2,x4,y4);
    
    if(a1*a2<0 && a3*a4<0) return true;
    if(a1==0 && (x3-x1)*(x3-x2)<=0 && (y3-y1)*(y3-y2)<=0) return true;
    if(a2==0 && (x4-x1)*(x4-x2)<=0 && (y4-y1)*(y4-y2)<=0) return true;
    if(a3==0 && (x1-x3)*(x1-x4)<=0 && (y1-y3)*(y1-y4)<=0) return true;
    if(a4==0 && (x2-x3)*(x2-x4)<=0 && (y2-y3)*(y2-y4)<=0) return true;
    
    return false;
}

int main(){
    int T;
    int xstart,ystart,xend,yend,xleft,ytop,xright,ybottom;
    bool intersect;
    
    scanf("%d",&T);
        
    for(int caso=1;caso<=T;caso++){
        intersect=false;
        
        scanf("%d %d %d %d %d %d %d %d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);
        
        if(xleft>xright) swap(xleft,xright);
        if(ybottom>ytop) swap(ybottom,ytop);
        
        if(intersection(xstart,ystart,xend,yend,xleft,ytop,xright,ytop)) intersect=true;
        else if(intersection(xstart,ystart,xend,yend,xleft,ybottom,xright,ybottom)) intersect=true;
        else if(intersection(xstart,ystart,xend,yend,xleft,ytop,xleft,ybottom)) intersect=true;
        else if(intersection(xstart,ystart,xend,yend,xright,ytop,xleft,ybottom)) intersect=true;
        else if(xstart>=xleft && xstart<=xright && xend>=xleft && xend<=xright && ystart>=ybottom && ystart<=ytop && yend>=ybottom && yend<=ytop) intersect =true;
        
        if(intersect) printf("T\n",caso);
        else printf("F\n",caso);
    }
    
    return 0;
}
