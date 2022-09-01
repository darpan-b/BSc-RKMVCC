# Write a shell script to add n random numbers using array.

echo "Enter number of elements in the array:"
read n

echo "Enter" n "numbers"
for (( i=0; i<n; i++ ))
do
	read a[$i]
done

sum=0

for (( i=0; i<n; i++ ))
do
	sum=`expr $sum + ${a[$i]}`
done

echo "Sum =" $sum
