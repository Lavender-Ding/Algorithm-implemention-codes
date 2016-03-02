class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len=matrix.size(),j,i,k;
        for(k=0;k<len/2;k++){
            i=k;
            for(j=k;j<len-k-1;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[len-1-j][i];
                matrix[len-1-j][i]=matrix[len-1-i][len-1-j];
                matrix[len-1-i][len-1-j]=matrix[j][len-1-i];
                matrix[j][len-1-i]=tmp;
            }
        }
    }
};
