import phonetics


def get_phonetic(s):
    return phonetics.dmetaphone(s)


phonet_list = []
lines = []
outfile = "match.txt"
data = input("Enter match strings separated by space : ").split(" ")
filename = input("Enter name of the file: ")
out = open(outfile, "w")


with open(filename) as f:
    lines = [line.rstrip('\n') for line in f]

for word in lines:
    phonet_list.append(get_phonetic(word))

for word in data:
    ans = []
    ret_val = get_phonetic(word)
    for val in ret_val:
        for i in range(len(lines)):
            lis = phonet_list[i]
            w = lines[i]
            if val != '' and val in lis:
                ans.append(w)
                break
    res = " ".join(ans)
    out.write(res)
