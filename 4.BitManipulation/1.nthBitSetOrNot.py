def is_ith_bit_set(number: int, i: int) -> bool:
    # Bit positions are zero-indexed from the right.
    mask = 1 << i
    return (number & mask) != 0


number = 10  # Binary: 1010
i = 1

if is_ith_bit_set(number, i):
    print(f"Bit {i} is set")
else:
    print(f"Bit {i} is not set")


# Time complexity: O(1)
# Space complexity: O(1)
