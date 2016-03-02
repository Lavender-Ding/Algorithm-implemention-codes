class Solution {
public:
    void generate(vector<string>& parenthesis,int left,int leftstk,int head,string onestr,int n)
    {
        if(head==n*2)
        {
            parenthesis.push_back(onestr);
            return;
        }
        if(leftstk>0) generate(parenthesis,left,leftstk-1,head+1,onestr+")",n);
        if(left<n) generate(parenthesis,left+1,leftstk+1,head+1,onestr+"(",n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        string onestr;
        generate(parenthesis,0,0,0,onestr,n);
        return parenthesis;
    }
};
