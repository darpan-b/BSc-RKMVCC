# program to check whether a given number is palindrome

echo "Enter a number"
read n

m=$n
rev=0

while [ $n -gt 0 ]
do
	d=`expr $n % 10`
	rev=`expr $rev \* 10 + $d`
	n=`expr $n / 10`
done

if [ $rev -eq $m ]
then
	echo "Palindrome"
else
	echo "Not palindrome"
fi
