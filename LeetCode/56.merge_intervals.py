class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        new_intervals = []
        for i in range(0, len(intervals)):
            cur_interval = intervals[i]
            if len(new_intervals) == 0:
                new_intervals.append(cur_interval)
            else:
                last_interval = new_intervals[-1]
                if cur_interval[1] <= last_interval[1]:
                    continue
                elif cur_interval[0] > last_interval[1]:
                    new_intervals.append(cur_interval)
                else:
                    new_intervals[-1][1] = cur_interval[1]
        return new_intervals