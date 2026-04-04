class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        int cols = n / rows;
        string result = "";

        // har column se diagonal traverse
        for(int col = 0; col < cols; col++) {
            int i = 0;
            int j = col;

            while(i < rows && j < cols) {
                result += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        // trailing spaces remove kar dete hai 
        while(!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
/*
2D → 1D Mapping hoti hai to  int index = i * cols + j;
mtlb jo matrix[i][j] me value thi ab wo arr[index] me milegi 

1D → 2D Mapping hoti hai to  
int i = index / cols
int j = index % cols
mtlb jo arr[index] me value thi ab wo matrix[i][j] me milegi 

*/