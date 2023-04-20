# TODO
from cs50 import get_int

row = get_int("Height: ")

while row < 1 or row > 8:
    row = get_int("Height: ")

# each row
for i in range(1, row+1):
    print(" "*(row - i) + "#"*i + "  " + "#"*i)