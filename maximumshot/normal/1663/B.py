x = int(input())
mn = 10 ** 10
for y in [1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000]:
    if y > x:
        mn = min(mn, y)
print(mn)