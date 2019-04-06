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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto cmp = [](Interval &a, Interval &b) {
            if (a.start < b.start) {
                return true;
            }
            else if (b.start > a.start) {
                return false;
            }
            else if (a.end < b.end) {
                return true;
            }
            else return false;
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        // Check for overlap:
        int rem = 0;
        int pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[pre].end) {
                rem++;
            }
            else pre = i;
        }
        return rem;
    }
};
