read -p "Enter element: " element
echo "Enter the list: "
read -a list
found=0
for item in ${list[@]}
do
	if [ $item == $element ]
	then
		found=1
		break
	fi
done

if [ $found -eq 0 ]
then
	echo "Not found."
else
	echo "Item found."
fi

