# check if a number is perfect square or not
# sum of consecutive odd numbers 1+3+5... always results in perfect square (proof?)

echo "Enter a number"
read n

i=1
while [ $n -gt 0 ]
do
	n=`expr $n - $i`
	i=`expr $i + 2`
done

if [ $n -eq 0 ]
then
	echo "Perfect Square"
else
	echo "Not a Perfect Square"
fi
