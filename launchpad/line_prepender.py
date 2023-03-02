"""
    Prepend #include "avr/pgmspace.h" at the beginning of every AudioSample.h
    The include is required by the use of PROGMEM in theses files

    Usage: python line_prepender.py
"""


import os


def main():
    path = "src/LaunchPadLib/Samples/"
    line = '#include "avr/pgmspace.h"'
    filenames = os.listdir(path)
    for filename in filenames:
        if filename.startswith("AudioSample") and filename.endswith(".h"):
            with open(f"{path}{filename}", "r+") as f:
                content = f.read()
                if not content.startswith(line):
                    f.seek(0, 0)
                    f.write(line.rstrip("\r\n") + "\n" + content)


if __name__ == "__main__":
    main()
