echo "Enter the size of the array"
read n

echo "Enter" n "numbers"
for ((i=0; i<n; i++))
do
	read a[$i]
done

for ((i=0; i<n; i++))
do
	for ((j=i+1; j<n; j++))
	do
		if [ ${a[$i]} -gt ${a[$j]} ]
		then
			temp=${a[$i]}
			a[$i]=${a[$j]}
			a[$j]=$temp
		fi
	done
done

echo "Sorted array is"
for ((i=0; i<n; i++))
do
	echo ${a[$i]}
done

