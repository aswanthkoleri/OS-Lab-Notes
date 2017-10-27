echo "how many files?"
read n
for ((i = 0 ; i<$n ; i++))
do
echo "Enter the file name"
read f 
if [ -f $f ] 
	then
	echo ${f^^}
	r=${f^^}
	mv $f $r
	tr '[:lower:]' '[:upper:]' < $r
fi
done
