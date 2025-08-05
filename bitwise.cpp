#include <iostream>
using namespace std;

// 1. Count number of set bits (Brian Kernighan's algorithm)
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1); // removes the rightmost set bit
        count++;
    }
    return count;
}

// 2. Check if number is power of 2
bool isPowerOfTwo(int n)
{
    return n > 0 && (n & (n - 1)) == 0;
}

// 3. Set ith bit
int setBit(int n, int i)
{
    return n | (1 << i);
}

// 4. Clear ith bit
int clearBit(int n, int i)
{
    return n & ~(1 << i);
}

// 5. Toggle ith bit
int toggleBit(int n, int i)
{
    return n ^ (1 << i);
}

// 6. Check ith bit
bool checkBit(int n, int i)
{
    return (n >> i) & 1;
}

// 7. Find rightmost set bit
int rightmostSetBit(int n)
{
    return n & (-n);
}

// 8. Swap two numbers using XOR
void xorSwap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}

// 9. Reverse bits (32-bit number)
unsigned int reverseBits(unsigned int n)
{
    unsigned int rev = 0;
    for (int i = 0; i < 32; i++)
    {
        rev <<= 1;
        if (n & 1)
            rev |= 1;
        n >>= 1;
    }
    return rev;
}

// 10. Reverse digits of number
int reverseNumber(int n)
{
    int rev = 0;
    while (n != 0)
    {
        rev = rev * 10 + (n % 10);
        n /= 10;
    }
    return rev;
}

int main()
{
    int a = 5, b = 3;
    cout << "Basic Bitwise Operations (a = 5, b = 3):\n";
    cout << "a & b: " << (a & b) << endl;
    cout << "a | b: " << (a | b) << endl;
    cout << "a ^ b: " << (a ^ b) << endl;
    cout << "~a: " << (~a) << endl;
    cout << "a << 1: " << (a << 1) << endl;
    cout << "a >> 1: " << (a >> 1) << endl;

    cout << "\nUtilities:\n";
    cout << "Count set bits in 29: " << countSetBits(29) << endl;
    cout << "Is 32 power of 2? " << (isPowerOfTwo(32) ? "Yes" : "No") << endl;
    cout << "Set 2nd bit in 5: " << setBit(5, 2) << endl;
    cout << "Clear 2nd bit in 7: " << clearBit(7, 2) << endl;
    cout << "Toggle 1st bit in 6: " << toggleBit(6, 1) << endl;
    cout << "Is 3rd bit in 8 set? " << (checkBit(8, 3) ? "Yes" : "No") << endl;
    cout << "Rightmost set bit in 12: " << rightmostSetBit(12) << endl;

    cout << "\nSwapping using XOR:\n";
    int x = 10, y = 15;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    xorSwap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    cout << "\nReverse 32-bit bits of 5: " << reverseBits(5) << endl;
    cout << "Reverse digits of 1234: " << reverseNumber(1234) << endl;

    return 0;
}
