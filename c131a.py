w = raw_input()
swap = True
for i, c in enumerate(w):
    if i > 0 and c >= 'a' and c <= 'z':
        swap = False
        break
print w.swapcase() if swap else w
