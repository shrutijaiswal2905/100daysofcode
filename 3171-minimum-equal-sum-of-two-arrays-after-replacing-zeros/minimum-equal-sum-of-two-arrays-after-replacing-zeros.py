class Solution:
    def minSum(self, nums1: List[int], nums2: List[int]) -> int:
        sum_nums1 = sum(nums1) + nums1.count(0)
        sum_nums2 = sum(nums2) + nums2.count(0)
        if sum_nums1 > sum_nums2:
            return self.minSum(nums2, nums1)
        if sum_nums1 == sum_nums2:
            return sum_nums1
        return -1 if nums1.count(0) == 0 else sum_nums2