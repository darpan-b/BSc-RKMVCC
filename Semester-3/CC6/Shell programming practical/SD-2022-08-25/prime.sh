# program to check whether a number is prime

echo "Enter a number"
read n

if [ $n -le 1 ]
then
	echo "Not prime"
	exit
fi

for (( i=2; i*i <= n; i++ ))
do
	if [ `expr $n % $i` -eq 0 ]
	then
		echo "Not a prime number"
		exit
	fi
done

echo "Prime number"
