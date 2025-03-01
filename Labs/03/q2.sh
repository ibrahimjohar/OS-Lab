read -p "enter sentence: " sentence
vowels=0

for (( i=0; i<${#sentence}; i++ )); do
	letters="${sentence:i:1}"
	
	if [[ "$letters" =~ [aeiouAEIOU] ]]; then
		((vowel++))
	fi
done

echo "vowel count: "$vowel

Sat Mar  1 10:57:01 PM PKT 2025
