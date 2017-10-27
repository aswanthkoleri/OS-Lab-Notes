echo enter the filename
read fname
if [ -f $fname ]
	then
	echo enter the word
	read w 
	sed -i /$w/d $fname
else
	echo not a filename
fi
