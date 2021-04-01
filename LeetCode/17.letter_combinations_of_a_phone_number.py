class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        def add_letter(digit, ans):
            num2letters = [' ', ' ', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
            letters = num2letters[int(digit)]
            new_ans = []
            if len(ans) == 0:
                for letter in letters:
                    new_ans.append(letter)
            else: 
                for word in ans:
                    for letter in letters:
                        new_ans.append(word+letter)
            return new_ans

        if len(digits) == 0:
            return ans
        for digit in digits:
            ans = add_letter(digit, ans)

        return ans