# write a shell script to print those lines that do not contain a particular word

echo "Enter the filename"
read filename
echo "Enter word"
read word
grep -v $word $filename

