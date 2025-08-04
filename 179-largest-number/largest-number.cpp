class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Step 1: Sabse pehle vector<int> ko vector<string> mein convert karna hai
        // Kyunki string concatenation aur comparison karna hai
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));  // har integer ko string mein convert kar rahe
        }
        
        // Step 2: Custom sorting using lambda function
        // Ye sabse important part hai - concatenation ke basis pe sorting
        sort(numStrings.begin(), numStrings.end(), 
             [](const string& a, const string& b) { 
                 // Agar a+b > b+a hai to a pehle aana chahiye
                 // Example: a="3", b="30" 
                 // a+b = "330", b+a = "303"
                 // Since "330" > "303", so "3" should come before "30"
                 return a + b > b + a; 
             });
        
        // Step 3: Sorted strings ko concatenate karke final result banayenge
        string result;
        for (const string& str : numStrings) {
            result += str;  // sabko jod rahe hain
        }
        
        // Step 4: Edge case handle karna - agar sabhi numbers 0 hain
        // Example: [0,0,0] ka result "000" hoga, but hume "0" return karna hai
        if (result[0] == '0') {
            return "0";
        }
        
        return result;
    }
};

/*
Algorithm ka main logic:
- Numbers ko strings mein convert karo
- Custom comparator use karke sort karo
- Comparator mein check karo ki a+b bada hai ya b+a
- Jo combination bada number banata hai, woh pehle aayega
- Finally sabko concatenate kar do

=== DRY RUN EXAMPLE ===
Input: nums = [3, 30, 34, 5, 9]

Step 1: Convert to strings
numStrings = ["3", "30", "34", "5", "9"]

Step 2: Custom sorting with lambda comparator
Comparisons during sorting:

"3" vs "30":
- a+b = "3"+"30" = "330"
- b+a = "30"+"3" = "303" 
- "330" > "303" ✓, so "3" comes before "30"

"34" vs "3":
- a+b = "34"+"3" = "343"
- b+a = "3"+"34" = "334"
- "343" > "334" ✓, so "34" comes before "3"

"5" vs "34":
- a+b = "5"+"34" = "534"
- b+a = "34"+"5" = "345"
- "534" > "345" ✓, so "5" comes before "34"

"9" vs "5":
- a+b = "9"+"5" = "95"
- b+a = "5"+"9" = "59"
- "95" > "59" ✓, so "9" comes before "5"

After complete sorting: ["9", "5", "34", "3", "30"]

Step 3: Concatenate strings
result = "9" + "5" + "34" + "3" + "30" = "9534330"

Step 4: Check edge case
result[0] = '9' ≠ '0', so no edge case

Final Answer: "9534330"

Verification: Ye largest possible number hai jo in digits se ban sakta hai!
*/