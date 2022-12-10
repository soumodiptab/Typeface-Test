# pip install fuzzywuzzy
# pip install python-Levenshtein

from fuzzywuzzy import process
from fuzzywuzzy import fuzz
sol = []

inp = input("Enter the phonetic word: ")
file = input("Enter the name of the file: ")

f = open(file, 'r')

for line in f.readlines():
    word = line.rstrip('\n')

    matchval = fuzz.ratio(inp, word)
    if (matchval >= 50):
        sol.append(word)

print(sol)
