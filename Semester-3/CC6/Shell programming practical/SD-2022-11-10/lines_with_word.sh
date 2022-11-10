# write a shell script to print those particular lines containing a particular word

echo "Enter a filename"
read filename
echo "Enter the word"
read wd
grep -i $wd $filename

