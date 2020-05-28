class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;  // x 异或 y

        int counter = 0;

        while (n > 0)
        {
            counter += n & 1;
            n >>= 1;    // 
        }
        
        return counter;

        // int num1[33], num2[33]; // 分别记录两个数字的二进制
        // int pos = 31;   //
        // while(x != 0)
        // {
        //     num1[pos--] = x % 2;
        //     x /= 2;
        // }
        // pos = 31;
        // while(y != 0)
        // {
        //     num2[pos--] = y % 2;
        //     y /= 2;
        // }
        // int ans = 0;
        // for (int i = 0; i < 32; i++)
        // {
        //     if(num1[i] != num2[i])
        //         ans++;
        // }
        // return ans;
    }
};

