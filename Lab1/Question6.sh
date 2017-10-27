echo enter the no elements 
read no
echo enter the elements
for ((i=0;i<$no;i++))
do
	read n
	ar[i]=$n
done
for ((i=0;i<$no;i++))
do 
echo ${ar[i]}
done