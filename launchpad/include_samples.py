"""
    Prepend #include at the beginning of AllSamples.h

    Usage: python include_samples.py
"""


import os


def main():
    path = "src/LaunchPadLib/Samples/"
    file = "AllSamples.h"
    line = '#include "{}"'
    filenames = os.listdir(path)
    with open(f"{path}{file}", "w") as f:
        f.write(
            """#ifndef allsamples_teensy_h
#define allsamples_teensy_h
"""
        )
        for filename in filenames:
            if filename.startswith("AudioSample") and filename.endswith(".h"):
                f.write(line.format(filename) + "\n")
        f.write("""#endif""")


if __name__ == "__main__":
    main()
