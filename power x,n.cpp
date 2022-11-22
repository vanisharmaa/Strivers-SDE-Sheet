/*
Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
*/
double myPow(double x, int n) {
    double ans = 1;
    bool neg = false;
    long long num = n;
    if (n < 0){
        neg = true;
        num *= -1;
    }
    while(num > 0){
        if(num % 2 == 1){
            ans *= x;
            num--;
        }
        else{
            x *= x;;
            num /= 2;
        }
    }
    if(neg){
        ans = 1.0/ans;
    }
    return ans;
}
