# LeetCode Problem: 231. Power of Two
# Problem Link: https://leetcode.com/problems/power-of-two/


def is_power_of_two(number: int) -> bool:
    # A power of two has exactly one set bit.
    # number & (number - 1) removes the rightmost set bit.
    return number > 0 and (number & (number - 1)) == 0


number = 16

if is_power_of_two(number):
    print(f"{number} is a power of two")
else:
    print(f"{number} is not a power of two")


# Time complexity: O(1)
# Space complexity: O(1)
