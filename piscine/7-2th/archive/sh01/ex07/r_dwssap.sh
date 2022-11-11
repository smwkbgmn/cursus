#!/bin/bash
cat /etc/passwd | grep -v "#" | awk -F ":" 'NR % 2 == 0 {print $1}' | rev | sort -r | awk -v FT_LINE1="$FT_LINE1" -v FT_LINE2="$FT_LINE2" 'NR >= FT_LINE1 && NR <= FT_LINE2' | xargs | sed "s/ /, /g; s/$/./" | tr -d "\n" 
