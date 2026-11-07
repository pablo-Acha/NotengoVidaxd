# lee ambos outputs y encuentra la primera diferencia

with open("out1.txt") as f1, open("out2.txt") as f2:
    a = f1.readlines()
    b = f2.readlines()

n = min(len(a), len(b))

for i in range(n):
    if a[i].strip() != b[i].strip():
        print("DIFFERENCE FOUND at line", i+1)
        print("Correct :", a[i].strip())
        print("Wrong   :", b[i].strip())
        break
else:
    if len(a) != len(b):
        print("Different number of lines!")
    else:
        print("No differences found ✅")