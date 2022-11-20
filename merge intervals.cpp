/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> output;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    pair<int, int> p = {intervals[0][0], intervals[0][1]};
    for(int i = 1; i < n; i++){
        if(intervals[i][0] <= p.second){
            p.second = max(p.second, intervals[i][1]);
        }else{
            vector<int> p1(2);
            p1[0] = p.first;
            p1[1] = p.second;
            output.push_back(p1);
            p.first = intervals[i][0];
            p.second = intervals[i][1];
        }
    }
    output.push_back({p.first, p.second});
    return output;
}
