class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
       int x = abs(start[0] - target[0]);
       int y = abs(start[1] - target[1]);
       return !((x + y) % 2);
        

    }
};