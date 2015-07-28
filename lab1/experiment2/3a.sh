if [ -d $1 ]
then
	echo "Is a directory"
elif [ -f $1 ]
then
	echo "Is a file"
else
	echo "Something else"
fi


