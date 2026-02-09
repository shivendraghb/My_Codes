from typing import List

class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l, h = 0, len(letters) - 1
        pos = -1
        while l <= h:
            m = l + (h - l) // 2
            if letters[m] > target:
                pos = m
                h = m - 1
            else:
                l = m + 1
        
        return letters[0] if pos == -1 else letters[pos]
        

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        letters = list(input().split())
        target = input().strip()
        sol = Solution()
        print(sol.nextGreatestLetter(letters, target))