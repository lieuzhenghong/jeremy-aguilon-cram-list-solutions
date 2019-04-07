/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    // Sorting helps us a lot here --- from n^2 solution to nlogn
    // We only have to look at the previous interval
    static bool cmp (Interval &a, Interval &b)
    {
        return a.start < b.start;
    }
    
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> new_intervals;
        for (auto &iv: intervals)
        {
            if (new_intervals.size()) 
            {
                if (new_intervals.back().end < iv.start) // start a new interval
                {
                    new_intervals.push_back(iv);
                }
                else
                {
                    new_intervals.back().end = max(iv.end, new_intervals.back().end);
                }
            }
            else
            {
                new_intervals.push_back(iv);
            }
        }
        return new_intervals;
    }
};
