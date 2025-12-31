class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows>= s.length())
        {
            return s; //simply return the string as it is
        }
        
        vector<string>rows(numRows); // making empty rows
        int cur_row = 0; 
        bool down_dir = false; // direction, its bool cause its either up or down
        for (char c:s){
            rows[cur_row]+=c;

            if (cur_row == 0 || cur_row == numRows - 1){
                down_dir = !down_dir; //if its at the first row or last one change the direction of tracersal
            }
            cur_row += down_dir? 1: -1; // if going down +1 or -1 in case going up
        }
        string res;
        for (string &row : rows){
            res += row;
        }
        return res;
        
    }
};