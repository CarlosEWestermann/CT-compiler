#!/bin/bash

# Define the folder containing your files
folder="./E3"

# Define the executable path
executable="./etapa3"

# Array of strings from your file
strings=("z00" "z01" "z02" "z03" "z04" "z05" "z06" "z07" "z08" "z09" "z10" "z11" "z12" "z13" "z14" "z15" "z16" "z17" "z18" "z19" "z20" "z21" "z22" "z23" "z24" "z25" "z26" "z27" "z28" "z29" "z30" "z31" "z32" "z33" "z34" "z35" "z36" "z37" "z38" "z39" "z40" "z41" "z42" "z43" "z44" "z45" "z46" "z47" "z48" "z49" "z50" "z51" "z52" "z53" "z54" "z55" "z56" "z57" "z58" "z59")

# Loop through each string
for str in "${strings[@]}"; do
    echo "$str";
    # Check if a file matching the string exists in the folder
    file="${folder}/${str}"
    if [ -f "$file" ]; then
        echo "Processing file: $file"

        # Run the executable with the file
        $executable < "$file" > "output.txt"
        xdot "$file.ref.dot"

        # Check the exit code of the executable
        if [ $? -eq 0 ]; then
            echo "Executable ran successfully for $file"
        else
            echo "Executable failed for $file"
        fi
    else
        echo "No file found for $str"
    fi
done