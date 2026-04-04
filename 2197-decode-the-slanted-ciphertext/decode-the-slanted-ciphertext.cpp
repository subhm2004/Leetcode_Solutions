class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();

        int total_columns = n / rows;
        string result = "";

        // har column se diagonal traverse
        for(int col = 0; col < total_columns; col++) {
            int i = 0;
            int j = col;

            while(i < rows && j < total_columns) {
                result += encodedText[i * total_columns + j];
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
2D → 1D Mapping hoti hai to  int index = i * total_columns + j;
mtlb jo matrix[i][j] me value thi ab wo arr[index] me milegi 

1D → 2D Mapping hoti hai to  
int i = index / total_columns
int j = index % total_columns
mtlb jo arr[index] me value thi ab wo matrix[i][j] me milegi 

*/