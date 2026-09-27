# LeetCode Problem: 4. Median of Two Sorted Arrays
# Problem Link: https://leetcode.com/problems/median-of-two-sorted-arrays/


class Solution:

    def solve(self, nums1, nums2, k, astart, aend, bstart, bend):
        
        if aend < astart:
            return nums2[k-astart]
        if bend < bstart:
            return nums1[k-bstart]

        aindex = (astart+aend)//2
        bindex = (bstart+bend)//2
        avalue = nums1[aindex]
        bvalue = nums2[bindex]

        if aindex + bindex < k:
            if avalue > bvalue:
                return self.solve(nums1, nums2, k, astart, aend, bindex+1, bend)
            else:
                return self.solve(nums1, nums2, k, aindex+1, aend, bstart, bend)
        else:
            if avalue > bvalue:
                return self.solve(nums1, nums2, k, astart, aindex-1, bstart, bend)
            else:
                return self.solve(nums1, nums2, k, astart, aend, bstart, bindex-1)

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a = len(nums1)
        b = len(nums2)
        k = (a+b)//2

        if (a+b)%2 != 0:
            return self.solve(nums1, nums2, k, 0, a-1, 0, b-1)
        return (self.solve(nums1, nums2, k-1, 0, a-1, 0, b-1) + self.solve(nums1, nums2, k, 0, a-1, 0, b-1))/2


# Time complexity: O(log m + log n)
# Space complexity: O(log m + log n) due to the recursive call stack
# Here, m and n are the lengths of nums1 and nums2.
