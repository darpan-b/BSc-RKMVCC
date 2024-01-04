# Program to check whether a given number is even or odd
print('Enter a number')
num = int(input())
if num % 2 == 0:
	print('Even')
else:
	print('Odd')

# Program to print all even numbers in range [0,10]
for i in range(11):
	if i % 2 == 0:
		print(i)

# Program to print all numbers divisible by 7 in range [0,100]
for i in range(101):
	if i % 7 == 0:
		print(i)
# while
ctr = 0
while ctr <= 100:
	if ctr % 7 == 0:
		print(ctr)
	ctr += 1



