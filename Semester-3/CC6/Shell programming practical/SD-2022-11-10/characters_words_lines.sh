# write a shell script to count number of characters, words and lines from a file

echo "Enter a filename"
read myfile
ch=`cat $myfile | wc -c`
wd=`cat $myfile | wc -w`
l=`grep -c "." $myfile`
echo $ch
echo $wd
echo $l

