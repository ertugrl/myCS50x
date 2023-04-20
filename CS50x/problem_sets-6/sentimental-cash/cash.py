# TODO
from cs50 import get_float

while True:
    cash = get_float("Change owed: ")
    if cash > 0:
        # to make the calculation easier
        cash = cash * 100
        # if input is valid
        break

counter = 0

while cash >= 25:
    cash -= 25
    counter += 1
while cash >= 10:
    cash -= 10
    counter += 1
while cash >= 5:
    cash -= 5
    counter += 1
while cash >= 1:
    cash -= 1
    counter += 1

print(counter)