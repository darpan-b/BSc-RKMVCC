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

echo "Enter the number to be searched in the array"
read key

lo=0
hi=`expr $n - 1`

while [ $lo -le $hi ]
do
	mid=`expr $lo + $hi`
	mid=`expr $mid / 2`

	if [ ${a[$mid]} -eq $key ]
	then
		echo $key "found at index" $mid
		exit
	elif [ ${a[$mid]} -gt $key ]
	then
		hi=`expr $mid - 1`
	else
		lo=`expr $mid + 1`
	fi
done

echo $key "is not present in the array"

