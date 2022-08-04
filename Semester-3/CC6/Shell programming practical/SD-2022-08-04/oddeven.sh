# program to check if a given number is odd or even

echo "Enter a number"
read a
rem_mod_2=`expr $a % 2`

if [ $rem_mod_2 -eq 0 ]
# if [ `expr $a % 2` -eq 0 ] -> this works too
then
	echo "Even number"
else
	echo "Odd number"
fi

