read -p "Enter a word: " word
read -p "Enter file name: " file

echo "`grep -o $word $file | wc -l`"
