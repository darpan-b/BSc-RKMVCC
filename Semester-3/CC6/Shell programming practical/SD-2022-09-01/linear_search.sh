# Linear search on an array

echo "Enter the number of elements in the array"
read n

echo "Enter" $n "numbers"
for (( i=0; i<n; i++ ))
do
	read a[$i]
done

echo "Enter the number to be searched in the array:"
read key

present=-1

for (( i=0; i<n; i++ ))
do
	if [ ${a[$i]} -eq $key ]
	then
		present=$i
	fi
done

if [ $present -eq -1 ]
then
	echo $key "not present in the array"
else
	echo $key "present at index" $present "in the array"
fi
