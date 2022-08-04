# program to find the largest among three numbers

echo "Enter three numbers"
read a
read b
read c

if [ $a -ge $b -a $a -ge $c ]
then
	echo $a "is the largest number"
elif [ $b -ge $a -a $b -ge $c ]
then
	echo $b "is the largest number"
else
	echo $c "is the largest number"
fi

