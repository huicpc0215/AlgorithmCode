class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long res = 0;
        long long lm=m,ln=n;
        for(int i=0;i<32;i++){
            if( (1ll<<i) & (lm) ){
                if( ( m & ( (1ll<<i)-1) ) + n - m  < (1ll << i) )
                    res |= 1ll<<i;
            }
        }
        return res;
    }
};
