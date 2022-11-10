# Write a shell script to check whether a given string is palindrome or not.

echo "Enter a string"
read str
len=`echo $str | wc -c`
for ((i=1; i<=len/2; i++))
do
	c1=`echo $str | cut -c $i`
	other_char=`expr $len - $i`
	c2=`echo $str | cut -c $other_char`
	if [ $c1 != $c2 ]
	then
		echo "Not palindrome"
		exit
	fi
done
echo "Palindrome"
