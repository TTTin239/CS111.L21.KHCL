import itertools
import collections
nb_pilot=int(input())
list_index2=[]
list_pilot=collections.deque()
for i in range(nb_pilot):
    list_in4=list(map(int,input().split()))
    list_pilot.append(list_in4)
    list_index2.append(i)
list_index2=list(itertools.permutations(list_index2))
min_sum=1e7
for i in range (len(list_index2)):
    sum1=0
    check=0
    for k in range(nb_pilot):
        if k %2 ==0:
            if list_index2[i][k]<list_index2[i][k+1]:
                check=1
                break
    if check==0:
        for j in range(nb_pilot):    
            if j %2==0:
                sum1+=list_pilot[list_index2[i][j]][0]
            else:
                sum1+=list_pilot[list_index2[i][j]][1]
        if sum1<min_sum:
            min_sum=sum1
print(min_sum)

