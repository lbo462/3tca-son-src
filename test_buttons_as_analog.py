"""
    Usage : python test_button_as_analog.py <r1> <r2> <r3> ...

    Test validity multiples buttons linked together to an analog value
    Computes every button combinations and determine corresponding req and analog value
"""

import sys
from typing import List

DELTA = 20  # minimum difference between the values. Determined by the system noise


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


if __name__ == "__main__":
    resistances = [float(r) for r in sys.argv[1:]]
    all_anal_values = []

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
                print(f"WARNING : {anal_value} and {val} are too close !")
        all_anal_values.append(anal_value)
