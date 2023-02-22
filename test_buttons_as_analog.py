"""
    Usage : python test_button_as_analog.py <r1> <r2> <r3> ...

    Test validity multiples buttons linked together to an analog value
    Computes every button combinations and determine corresponding req and analog value

    Brute force model to find a valid resistance combination
"""

import sys
from typing import List

DELTA = 5  # minimum difference between the values. Determined by the system noise
AVAILABLE_RES = [
    1000000,
    100000,
    10000,
    5000,
    1000,
    330,
    220,
    100,
    10,
]


def compute_linear_combinations(variables: List[float]) -> List[float]:
    """Get values and return every values that can be made with theses"""
    possible_values = variables.copy()
    for r1 in variables:
        for r2 in variables:
            sum = r1 + r2
            if sum not in possible_values:
                possible_values.append(sum)
                for r3 in variables:
                    sum1 = sum + r3
                    sum2 = r1 + r3
                    sum3 = r2 + r3
                    if sum1 not in possible_values:
                        possible_values.append(sum1)
                    if sum2 not in possible_values:
                        possible_values.append(sum2)
                    if sum3 not in possible_values:
                        possible_values.append(sum3)
    return possible_values


def get_req(resistances: List[float]) -> float:
    """
    Take a list of resistances in // and return equivalent
    :param resistances: list of resistances value in Ohms
    :return: equivalent resistance
    """
    req_inv = 0
    for r in resistances:
        req_inv += 1 / r
    return 1 / req_inv


def get_anal_value(resistance: float) -> float:
    """Compute analog value read"""
    return 1024 * (1 - resistance / (resistance + 1000))  # big resistance


def binary_count(number_of_bit: int) -> List[List[int]]:
    """
    bit-wise count
    :return: A list of configurations for the buttons
    """
    start = [0 for _ in range(0, number_of_bit)]
    end = [1 for _ in range(0, number_of_bit)]
    configurations: List[List[int]] = []
    current = start.copy()
    previous = current.copy()
    while current != end:
        current = previous.copy()
        for i, b in enumerate(previous):
            if b == 0:
                # set bit to one and previous ones to zero
                for x in range(0, i):
                    current[x] = 0
                current[i] = 1

                break
        previous = current.copy()
        configurations.append(current.copy())
    return configurations


def validate(resistances: List[float]) -> bool:
    """Test if the proposed resitances overlap"""
    all_anal_values = []
    valid = True

    for c in binary_count(len(resistances)):
        # keep only pressed buttons of the current config
        pressed_resistances = []
        for i, b in enumerate(c):
            if b:
                pressed_resistances.append(resistances[i])

        req = get_req(pressed_resistances)
        anal_value = get_anal_value(req)

        print(f"{c} -> {anal_value}")

        # compare with previous values
        for val in all_anal_values:
            if anal_value + DELTA > val > anal_value - DELTA:
                print(f"{val} and {anal_value} too close. ({len(all_anal_values)})")
                valid = False
                return valid  # comment to continue searching
        all_anal_values.append(anal_value)
    return valid


def main():
    number_of_buttons = int(sys.argv[1])
    possible_combinations = compute_linear_combinations(AVAILABLE_RES)
    print(f"Computed {len(possible_combinations)} possible resistances combinations.")
    for i in range(0, len(possible_combinations) - number_of_buttons + 1):
        resistances = possible_combinations[i : i + number_of_buttons]
        print(f"Testing with {resistances} ...")
        if validate(resistances):
            print("SUCCESS: Model is valid.")
            break
        else:
            print("not valid.")


if __name__ == "__main__":
    # validate([16000, 7000, 2000, 6330, 5330])
    main()
