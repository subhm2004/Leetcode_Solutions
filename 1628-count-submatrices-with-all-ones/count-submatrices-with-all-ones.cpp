class Solution {
public:
    // Ye function histogram mein saare possible rectangles count karta hai
    // Jo sirf 1s se bane hain (height > 0 wale areas mein)
    int rectangles_in_histogram(vector<int>& heights) {
        int n = heights.size();  // Histogram mein kitne bars hain
        int count = 0;           // Total rectangles ka counter
        
        // Har position ko RIGHT BOUNDARY maan kar rectangles count karte hain
        // Matlab position 'i' sabse rightmost corner hai rectangle ka
        for (int i = 0; i < n; i++) {
            int minHeight = heights[i];  // Current bar ki height se shuru karte hain
            
            // Ab position 'i' se LEFT ki taraf extend karte hain
            // Condition: heights[j] > 0 (matlab us position pe 1s hain)
            for (int j = i; j >= 0 && heights[j] > 0; j--) {
                
                // j se i tak ke saare bars mein MINIMUM height nikalo
                // Ye isliye kyunki rectangle ki height = minimum height hogi
                // us range mein (rectangle mein saare cells 1 hone chahiye)
                minHeight = min(minHeight, heights[j]);
                
                // YE LINE SABSE IMPORTANT HAI - SAMJHO ISKO:
                // Current width = (i - j + 1)  [j se i tak]
                // Maximum height = minHeight
                // 
                // Ab kitne rectangles ban sakte hain?
                // Height 1 se minHeight tak ke saare possible rectangles:
                // - Height 1 ka rectangle (width = i-j+1)
                // - Height 2 ka rectangle (width = i-j+1)  
                // - Height 3 ka rectangle (width = i-j+1)
                // ... aur so on till minHeight
                //
                // Total rectangles = minHeight (kyunki har height ke liye ek rectangle)
                count += minHeight;
                
                /*
                EXAMPLE SAMJHANE KE LIYE:
                Agar heights = [3, 2, 4] aur i = 2 (position 2 ko right boundary maan rahe)
                
                j = 2: minHeight = 4, width = 1
                       Rectangles: height 1,2,3,4 ke 4 rectangles = count += 4
                
                j = 1: minHeight = min(4,2) = 2, width = 2  
                       Rectangles: height 1,2 ke 2 rectangles = count += 2
                
                j = 0: minHeight = min(2,3) = 2, width = 3
                       Rectangles: height 1,2 ke 2 rectangles = count += 2
                
                Total for i=2: 4 + 2 + 2 = 8 rectangles
                */
            }
        }
        
        return count;
    }
    
    // Main function jo matrix mein saare submatrices count karta hai
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();      // Matrix mein kitni rows hain
        int n = mat[0].size();   // Matrix mein kitne columns hain  
        int totalCount = 0;      // Total submatrices ka counter
        
        // Histogram approach use kar rahe hain
        // Har column ke liye consecutive 1s ki height track karte hain
        vector<int> heights(n, 0);  // Initially saari heights 0
        
        // Matrix ki har row ko process karte hain
        for (int i = 0; i < m; i++) {
            
            // Current row (i) ke liye heights array update karte hain
            for (int j = 0; j < n; j++) {
                
                if (mat[i][j] == 1) {
                    // Agar current cell 1 hai, to height increase karo
                    // Matlab consecutive 1s continue ho rahe hain upar se
                    heights[j]++;
                } else {
                    // Agar current cell 0 hai, to height reset kar do
                    // Kyunki consecutive 1s ka sequence break ho gaya
                    heights[j] = 0;
                }
            }
            
            /*
            HEIGHTS ARRAY KA MATLAB:
            heights[j] = Column j mein row i tak consecutive 1s ki count
            
            Example: 
            Matrix = [[1,0,1],
                      [1,1,0], 
                      [1,1,0]]
            
            Row 0 ke baad: heights = [1, 0, 1]  
            Row 1 ke baad: heights = [2, 1, 0]  (column 0 mein 2 consecutive 1s)
            Row 2 ke baad: heights = [3, 2, 0]  (column 0 mein 3, column 1 mein 2)
            */
            
            // Ab current heights ko histogram maan kar saare rectangles count karo
            // Jo is row (i) ko BOTTOM BOUNDARY maan kar bante hain
            totalCount += rectangles_in_histogram(heights);
            
            /*
            YE KAISE KAAM KARTA HAI:
            - Har row ko process karne ke baad, us row tak ki histogram ban jaati hai
            - Histogram mein har bar ki height = us column mein consecutive 1s
            - rectangles_in_histogram() function us histogram mein saare rectangles count karta hai
            - Ye saare rectangles current row ko bottom boundary maan kar bante hain
            */
        }
        
        return totalCount;
    }
};

/*
COMPLETE ALGORITHM WALKTHROUGH:

Input Matrix:
[1, 0, 1]
[1, 1, 0]
[1, 1, 0]

STEP BY STEP EXECUTION:

Row 0: mat[0] = [1, 0, 1]
heights update: [1, 0, 1]
rectangles_in_histogram([1, 0, 1]):
- i=0: minHeight=1, rectangles=1
- i=1: heights[1]=0, skip  
- i=2: minHeight=1, rectangles=1
Total for row 0: 2

Row 1: mat[1] = [1, 1, 0]  
heights update: [2, 1, 0]  (column 0: 2 consecutive, column 1: 1 consecutive)
rectangles_in_histogram([2, 1, 0]):
- i=0: 
  j=0: minHeight=2, rectangles=2
  Total for i=0: 2
- i=1:
  j=1: minHeight=1, rectangles=1
  j=0: minHeight=min(1,2)=1, rectangles=1  
  Total for i=1: 2
- i=2: heights[2]=0, skip
Total for row 1: 4

Row 2: mat[2] = [1, 1, 0]
heights update: [3, 2, 0]  (column 0: 3 consecutive, column 1: 2 consecutive)  
rectangles_in_histogram([3, 2, 0]):
- i=0:
  j=0: minHeight=3, rectangles=3
  Total for i=0: 3
- i=1: 
  j=1: minHeight=2, rectangles=2
  j=0: minHeight=min(2,3)=2, rectangles=2
  Total for i=1: 4  
- i=2: heights[2]=0, skip
Total for row 2: 7

FINAL ANSWER: 2 + 4 + 7 = 13 ✓

TIME COMPLEXITY: O(m × n²)  
SPACE COMPLEXITY: O(n)

YE APPROACH EFFICIENT HAI KYUNKI HAR RECTANGLE SIRF EK BAAR COUNT HOTA HAI!
*/