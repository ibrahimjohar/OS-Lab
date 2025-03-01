#!/bin/bash
if [ -z "$1" ]; then
	echo "usage: $0 <path_to_directory>"
	exit 1
fi
target_dir="$1"
if [ ! -d "$target_dir" ]; then
	echo "error: directory '$target_dir' not found."
	exit 1
fi
destination="$HOME/saved_copies"
mkdir -p "$destination"
date=$(date +"%Y-%m-%d")
backup="$destination/archive_$date"
mkdir -p "$backup"
rsync -a --progress "$target_dir/" "$backup/"
file_count=$(find "$backup" -type f | wc -l)
dir_count=$(find "$backup" -type d | wc -l)
echo "backup completed."
echo "total files: $file_count"
echo "total directories: $dir_count"
echo "saved at: $backup"
