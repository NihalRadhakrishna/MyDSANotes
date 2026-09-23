# Reversal approach (optimized)
def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if k == 0:
            return nums
        n = len(nums)
        k = k % n
        nums.reverse()
        nums[:k] = nums[:k][::-1]
        nums[k:] = nums[k:][::-1]
        return nums

# Time complexity: O(n)
# Space complexity: O(1)


# Extra array approach
def rotate_extra_array(nums: list[int], k: int) -> None:
        if not nums:
                return

        n = len(nums)
        k %= n
        rotated = [0] * n

        for i in range(n):
                rotated[(i + k) % n] = nums[i]

        nums[:] = rotated

# Time complexity: O(n)
# Space complexity: O(n)


# Brute-force constant-space approach
def rotate_brute_force(nums: list[int], k: int) -> None:
        if not nums:
                return

        k %= len(nums)

        for _ in range(k):
                last_element = nums.pop()
                nums.insert(0, last_element)

# Time complexity: O(n * k)
# Space complexity: O(1)