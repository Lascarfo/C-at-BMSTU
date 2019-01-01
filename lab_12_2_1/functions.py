
import ctypes

# void shift(int len, int k, int *arr)

lib = ctypes.CDLL('lib.so')
_shift = lib.shift
_shift.argtypes = (ctypes.c_int, ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_shift.restype = ctypes.c_int


def shift(k, arr):
    arr_len = len(arr)
    arr_p = (ctypes.c_int * arr_len)(*arr)
    rc = _shift(arr_len, k, arr_p)
    return arr_p, rc

arr = [1, 2, 3, 4, 5]


print(shift(3, arr))


# int squares(int len, int *arr1, int *arr2)

_squares = lib.squares
_squares.argtypes = (ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int))
_squares.restype = ctypes.c_int


def squares(arr1, arr2):
    arr_len = len(arr1)
    arr1_p = (ctypes.c_int * arr_len)(*arr1)
    arr2_p = (ctypes.c_int * arr_len)(*arr2)
    rc = _squares(arr_len, arr1_p, arr2_p)
    return arr2_p, rc


arr = [2, 3, 4]
arr2 = []

print(squares(arr, arr2))