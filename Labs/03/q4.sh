read -p "enter file or directory name: " file

if [ -f "$file" ]; then
	echo "'$file' named file was found."
elif [ -f "$file.sh" ]; then
    echo "'$file.sh' named file was found."
elif [ -d "$file" ]; then 
	echo "'$file' named directory was found."
else
	echo "'$file' not found."
fi
