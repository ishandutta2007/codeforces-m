ar = [
'a 1 0 0 1 0',
'b 1 1 0 2 0',
'c 2 0 0 1 1',
'd 2 1 0 1 2',
'e 1 1 0 1 1',
'f 2 1 0 2 1',
'g 2 2 0 2 2',
'h 1 2 0 2 1',
'i 1 1 0 1 1',
'j 1 2 0 1 2',
'k 1 0 1 2 0',
'l 1 1 1 3 0',
'm 2 0 1 2 1',
'n 2 1 1 2 2',
'o 1 1 1 2 1',
'p 2 1 1 3 1',
'q 2 2 1 3 2',
'r 1 2 1 3 1',
's 1 1 1 2 1',
't 1 2 1 2 2',
'u 1 0 2 2 1',
'v 1 1 2 3 1',
'w 1 2 1 1 3',
'x 2 0 2 2 2',
'y 2 1 2 2 3',
'z 1 1 2 2 2',
]
n = int(input())
inp = [input() for i in range(n)]
for a in inp:
    for b in ar:
        if b[2:] == a:
            print(b[0], end='')
            break
print()