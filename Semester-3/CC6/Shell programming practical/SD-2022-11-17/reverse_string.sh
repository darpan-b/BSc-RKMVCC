# Write a shell script to reverse a string taken from command line argument
str=$1
len=`echo $str | wc -c`
for ((i=len; i>0; i--))
do
	ch=`echo $str | cut -c $i`
	echo -n $ch
done
echo ""
