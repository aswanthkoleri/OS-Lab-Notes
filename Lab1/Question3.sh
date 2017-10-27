read f
if [ -f $f ] 
then
	echo "it is a file"
elif [ -d $f ] 
then
	echo "it is a directory"
else
	echo "It is nothing"
fi