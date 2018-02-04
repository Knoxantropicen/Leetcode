/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(const Interval& i1, const Interval& i2) { return i1.start < i2.start; }

// Time: O(n*log(n)), Space: O(log(n))
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), comp); // sort by start value
        vector<Interval> result;
        int s = intervals[0].start, e = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= e) e = max(e, intervals[i].end);
            else {
                result.push_back(Interval(s, e));
                s = intervals[i].start; e = intervals[i].end;
            }
        }
        result.push_back(Interval(s, e));
        return result;
    }
};