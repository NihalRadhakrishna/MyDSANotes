def set_rightmost_unset_bit(number: int) -> int:
    # Sets the rightmost 0 bit to 1.
    return number | (number + 1)


def unset_rightmost_set_bit(number: int) -> int:
    # Changes the rightmost 1 bit to 0.
    return number & (number - 1)


number = 10  # Binary: 1010

set_result = set_rightmost_unset_bit(number)
unset_result = unset_rightmost_set_bit(number)

print(f"Original number: {number:b}")
print(f"After setting the rightmost unset bit: {set_result:b}")
print(f"After unsetting the rightmost set bit: {unset_result:b}")


# Time complexity: O(1)
# Space complexity: O(1)
