class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    bitset<32> bs(n);                // Step 1
    string str = bs.to_string();     // Step 2
    reverse(str.begin(), str.end()); // Step 3
    return stoul(str, 0, 2);         // Step 4
  }
};
/*
✅ Step 1: bitset<32> bs(n);
This converts the number n into a binary representation of size 32 bits.

Example:
If n = 5,
then bs = 00000000000000000000000000000101

✅ Step 2: string str = bs.to_string();
Converts the bitset into a string.

Now str = "00000000000000000000000000000101"

✅ Step 3: reverse(str.begin(), str.end());
Reverses the binary string.

str = "10100000000000000000000000000000"

✅ Step 4: return stoul(str, 0, 2);
Converts the reversed binary string back to an unsigned integer.

stoul() → String to Unsigned Long

str is the binary string.

0 is for auto-detecting the base (not important here).

2 tells it that the number is in base 2 (binary).

Final result is the reversed binary number in decimal form.


*/