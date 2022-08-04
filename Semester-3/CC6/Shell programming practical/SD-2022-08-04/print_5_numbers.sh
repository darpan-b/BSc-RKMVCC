# program to print from 1 to 5 using while loop

i=1
while [ $i -le 5 ]
do
	echo $i
	i=`expr $i + 1`
done

