import ctypes
import pathlib
import os
import sys

proj_folder = pathlib.Path(f'{os.getcwd()}\{__file__}').parent

if __name__ == "__main__":
    # Load the shared library into ctypes

    if sys.platform.startswith("win"):
        c_lib = ctypes.CDLL("./cmult.dll")
    else:
        c_lib = ctypes.CDLL("./libcmult.so")

x, y = 6, 2.3
answer = c_lib.cmult(x, ctypes.c_float(y))
print(answer)
