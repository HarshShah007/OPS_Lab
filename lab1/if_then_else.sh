echo "Hello" | grep "a"
if [ $? -eq 0 ]
then
	echo "pattern found"
else
	echo "pattern not found"
fi
