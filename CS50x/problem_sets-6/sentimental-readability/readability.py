# TODO
from cs50 import get_string

text = get_string("Text: ")


def main():
    a = count_letters(text)
    b = count_words(text)
    c = count_sentences(text)
    # to count index and print text's grade
    calculator(a, b, c)


def count_letters(txt):
    letter_counter = 0
    for i in txt:
        if (i >= "a" and i <= "z") or (i >= "A" and i <= "Z"):
            letter_counter += 1

    return letter_counter


def count_words(txt):
    word_counter = 1
    for i in txt:
        if i == " ":
            word_counter += 1

    return word_counter


def count_sentences(txt):
    sntc_counter = 0
    for i in txt:
        if i == "?" or i == "!" or i == ".":
            sntc_counter += 1

    return sntc_counter


def calculator(lttr, wrd, snt):
    L = 100 * (lttr / wrd)
    S = 100 * (snt / wrd)

    # "Coleman-Liau index" formula
    index = 0.0588 * L - 0.296 * S - 15.8

    # round up the index
    grade = round(index)

    if grade >= 16:
        print("Grade 16+")
    elif grade <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


main()