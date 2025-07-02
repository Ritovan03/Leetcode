#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        // Min-heap to track the earliest ending meeting
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto& interval : intervals) {
            // If the earliest ending meeting is done before the current starts
            if (!minHeap.empty() && minHeap.top() <= interval.start) {
                minHeap.pop(); // Reuse the room
            }
            minHeap.push(interval.end);
        }

        return minHeap.size(); // Number of rooms required
    }
};
