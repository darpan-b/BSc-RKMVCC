# program to check if a number is a perfect number or not
# 6 is a perfect number:
# factors of 6 = 1, 2, 3, 6
# other than 6 sum = 1+2+3 = 6, hence 6 is a perfect number


echo "Enter a number"
read n

sum=0
fac=1

while [ $fac -lt $n ]
do
	if [ `expr $n % $fac` -eq 0 ]
	then
		sum=`expr $sum + $fac`
	fi
	fac=`expr $fac + 1`
done

if [ $sum -eq $n ]
then
	echo "Perfect number"
else
	echo "Not a perfect number"
fi

