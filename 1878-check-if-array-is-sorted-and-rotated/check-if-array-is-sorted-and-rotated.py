from typing import List

class Solution:
    def check(self, nums: List[int]) -> bool:
        count = 0  # Count number of order breaks
        n = len(nums)

        for i in range(n):
            if nums[i] < nums[i-1]:  # If order breaks
                count += 1
                if count > 1:  # More than 1 break → Not sorted & rotated
                    return False
        
        return True  # 0 or 1 break → Valid sorted & rotated array
