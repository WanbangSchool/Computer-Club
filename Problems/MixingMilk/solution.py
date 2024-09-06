N = 3  # The number of buckets (which is 3)
TURN_NUM = 100

# capacity[i] is the maximum capacity of bucket i
capacity = [0 for _ in range(N)]
# milk[i] is the current amount of milk in bucket i
milk = [0 for _ in range(N)]
with open("mixmilk.in") as read:
	for i in range(N):
		capacity[i], milk[i] = map(int, read.readline().split())

for i in range(TURN_NUM):
	bucket1 = i % N
	bucket2 = (i + 1) % N

	"""
	The amount of milk to pour is the minimum of the remaining milk
	in bucket 1 and the available capacity of bucket 2
	"""
	amt = min(milk[bucket1], capacity[bucket2] - milk[bucket2])

	milk[bucket1] -= amt
	milk[bucket2] += amt

with open("mixmilk.out", "w") as out:
	for m in milk:
		print(m, file=out)