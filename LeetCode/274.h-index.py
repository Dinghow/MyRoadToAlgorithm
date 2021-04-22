class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        h_indexs = []
        for i, item in enumerate(citations):
            if item >= i+1:
                h_indexs.append(i+1)
        return max(h_indexs) if len(h_indexs) else 0