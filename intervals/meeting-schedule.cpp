// https://neetcode.io/problems/meeting-schedule/question

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() == 0) return true;
        map<int, int> times;
        for (int i = 0; i < intervals.size(); i++) {
            if (times.contains(intervals[i].start)) return false;
            times[intervals[i].start] = intervals[i].end;
        }
        int start = -1;
        int end = -1;
        for (auto& p : times) {
            start = p.first;
            if (start < end) return false;
            end = p.second;
        }
        return true;
    }
};
