import itertools
import collections
f = open("AIRCREW.IN.txt", "r")
cases = int(f.readline())
f1 = open("AIRCREW.OUT.txt", "w")
list_index2 = []
list_pilot = collections.deque()
for i in range(cases):
	temp = f.readline()
	list_pilot.append(list(map(int, temp.split())))
	list_index2.append(i)
list_index2=list(itertools.permutations(list_index2))
min_sum = 10e7
for i in range(len(list_index2)):
	sum1 = 0
	check = 0
	for k in range(cases):
		if k%2 == 0:
			if list_index2[i][k] < list_index2[i][k+1]:
				check = 1
				break
	if check == 0:
		for j in range(cases):
			if j%2 == 0:
				sum1+=list_pilot[list_index2[i][j]][0]
			else:
				sum1+=list_pilot[list_index2[i][j]][1]
		if sum1<min_sum:
			min_sum = sum1

f1.write(str(min_sum) + "\n")
print(min_sum)

f.close()
f1.close()