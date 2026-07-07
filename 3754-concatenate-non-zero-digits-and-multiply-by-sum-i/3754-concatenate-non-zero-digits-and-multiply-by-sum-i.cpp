class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;
        int i = 0;
        while(n) {
            int digi = n % 10;
            n /= 10;
            if(digi == 0) continue;
            x =  digi * pow(10, i) + x;;
            i++;
            sum += digi;
        }
        return 1LL * x * sum;
    }
};