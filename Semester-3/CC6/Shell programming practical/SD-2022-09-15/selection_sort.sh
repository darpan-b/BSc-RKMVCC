echo "Enter the size of the array"
read n

echo "Enter" $n "numbers"

for ((i=0; i<n; i++))
do
	read a[$i]
done

for ((i=0; i<n; i++))
do
	minidx=$i
	for ((j=i+1; j<n; j++))
	do
		if [ ${a[$minidx]} -gt ${a[$j]} ]
		then
			minidx=$j
		fi
	done

	temp=${a[$minidx]}
	a[$minidx]=${a[$i]}
	a[$i]=$temp
done

echo "Sorted array = "
for ((i=0; i<n; i++))
do
	echo ${a[$i]}
done

