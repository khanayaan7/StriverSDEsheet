class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long flag=0,y=n;
        if(y<0){flag=1;y=-y;}
        while(y){
            if(y&1){
                ans*=x;
            }
            y>>=1;
            x*=x;
        }
        if(flag==1)return 1/ans;
        return ans;
    }
};