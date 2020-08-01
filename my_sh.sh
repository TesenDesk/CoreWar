for champ in "${@:1}"
do
	if [ -f "$champ" ]
	then
		# Champion from file
		champs="$champs $champ"
	else
		# Champion from bytecode
		./makeChampion.sh "$champ" "test_champ_$i" > my_champin.cor
		if [ $? -ne 0 ]
		then
			printerr "Champion creation failed."
			exit 1
		fi
		champs="$champs /tmp/champ$i.cor"
		let "i++"
	fi
done