#!/bin/bash

# Define the folder containing your files
folder="./tests"

# Define the executable path
executable="./etapa3"

# Array of strings from your file
strings=("asl001" "asl003" "asl009" "asl010" "asl012" "asl014" "asl015" "asl016" "asl017" "asl018" "asl019" "asl027" "asl028" "asl031" "asl033" "asl037" "asl044" "asl048" "asl050" "asl052" "asl053" "asl055" "asl057" "asl058" "asl059" "asl061" "asl063" "asl069" "asl073" "asl074" "asl077" "asl079" "asl083" "asl086" "asl087" "asl088" "asl091" "asl092" "asl093" "asl099" "asl106" "asl108" "asl118" "asl126" "asl127" "asl129" "asl130" "asl131")

# Loop through each string
for str in "${strings[@]}"; do
    # Check if a file matching the string exists in the folder
    file="${folder}/${str}"
    if [ -f "$file" ]; then
        echo "Processing file: $file"

        # Run the executable with the file
        $executable < "$file" > "output"
        sudo bash output2dot.sh < output | xdot -

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