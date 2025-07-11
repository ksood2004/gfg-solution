// User function Template for C++
class Solution {
public:
    bool isPalindrome(int num) {
        int original = num;
        int rev = 0;
        while (num > 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        return original == rev;
    }
    int reverse(int num) {
        int rev = 0;
        while (num > 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }
        return rev;
    }

    int isSumPalindrome(int n) {
         if (isPalindrome(n)) return n;
        for (int i = 0; i < 5; ++i) {
            int rev = reverse(n);
            int sum = n + rev;
            if (isPalindrome(sum)) return sum;
            n = sum;
        }
        return -1; 
    }
};
