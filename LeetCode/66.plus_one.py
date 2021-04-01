class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        num = 0
        num_plus = list()
        for item in digits:
            num *= 10
            num += item
        num += 1
        num = str(num)
        for i in num:
            num_plus.append(int(i))
        return num_plus