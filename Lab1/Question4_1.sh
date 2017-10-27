echo "Enter the filename"
read fname
if [ -f $fname ]
then 
echo Enter the starting line
read s
echo enter the ending line 
read e
sed -n $s,$e\p $fname 
else
echo It is not a filename
fi
