/*
数的三次方根,浮点数二分查找
bool check(double x) {} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
*/
#include <iostream>
#include <math.h>
using namespace std;

double bsearch(double l, double r, double n){
    while(r - l > 1e-8){ 
        double mid = (l + r)/2;
        if (pow(mid, 3) < n) l = mid;
        else r = mid;
    }
    return l;
}


int main(){
    double n;
    scanf("%lf", &n);
    
    double res = bsearch(-1000, 1000, n);
    printf("%lf", res);
     return 0;
}







 


    
 