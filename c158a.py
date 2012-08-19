n, k = [int(x) for x in raw_input().split()]
scores = [int(x) for x in raw_input().split()]

result = 0

for i in range(n):
    if scores[i] >= scores[k-1] and scores[i] > 0:
        result += 1
    else:
        break

print result
