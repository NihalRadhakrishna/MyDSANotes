# LeetCode Problem: 191. Number of 1 Bits
# Problem Link: https://leetcode.com/problems/number-of-1-bits/


def count_set_bits(number: int) -> int:
    count = 0

    # Each operation removes the rightmost set bit.
    while number > 0:
        number = number & (number - 1)
        count += 1

    return count


number = 13  # Binary: 1101
print(f"Number of set bits: {count_set_bits(number)}")


# Time complexity: O(number of set bits)
# Space complexity: O(1)
