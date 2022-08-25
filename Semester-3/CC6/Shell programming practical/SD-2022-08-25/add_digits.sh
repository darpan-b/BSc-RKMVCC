# program to add the digits of a number

echo "Enter a number"
read n

sum=0

while [ $n -gt 0 ]
do
    d=`expr $n % 10`
    sum=`expr $sum + $d`
    n=`expr $n / 10`
done

echo "Sum of digits" $sum
