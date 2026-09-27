# LeetCode Problem: 2220. Minimum Bit Flips to Convert Number
# Problem Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/


def min_bit_flips(start: int, goal: int) -> int:
    # XOR sets a bit wherever start and goal have different bits.
    different_bits = start ^ goal
    flips = 0

    # Count the set bits using Brian Kernighan's algorithm.
    while different_bits > 0:
        different_bits &= different_bits - 1
        flips += 1

    return flips


start = 10  # Binary: 1010
goal = 7    # Binary: 0111

print(f"Minimum bit flips: {min_bit_flips(start, goal)}")


# Time complexity: O(number of different bits)
# Space complexity: O(1)
