/*
 * Leetcode 50
 * 快速幂实现
 */
double myPow(double x, int n)
{
    double ans = 1.0;

    // 必须使用long long来存储n，int的范围为-2147483648~2147483647
    // 若n=-2147483648，取反时无法使用int存储。
    long long N=n;
    if(N==0)
    {
        return ans;
    }
    else if(N<0)
    {
        N=-N;
        x=1/x;
    }

    while(N){
        if(N&1){
            ans*=x;
        }
        x*=x;
        N=N>>1;
    }
    return ans;
}