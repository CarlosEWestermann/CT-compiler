#!/bin/bash
cd ..
make
cd -

mkdir -p actual_outputs

total_tests=0
passed_tests=0

report="Test Report\n\n"

readarray -t sorted_testcases < <(find inputs -name "*.txt" | sort -V)

for testcase in "${sorted_testcases[@]}"; do
    total_tests=$((total_tests + 1))

    filename=$(basename "$testcase")
    
    echo "Running test: $filename"
    start_time=$(date +%s.%N)
    
    ../etapa2 < "$testcase" > actual_outputs/"$filename"
    
    if diff -q expected_outputs/"$filename" actual_outputs/"$filename"; then
        end_time=$(date +%s.%N)
        elapsed=$(echo "$end_time - $start_time" | bc)
        echo "Test $filename PASSED in $elapsed seconds"
        report="$report$filename: PASSED in $elapsed seconds\n"
        
        passed_tests=$((passed_tests + 1))
    else
        echo "Test $filename FAILED"
        report="$report$filename: FAILED\n"
        diff_output=$(diff expected_outputs/"$filename" actual_outputs/"$filename")
        report="$report$diff_output\n\n"
    fi

    echo "-------------------------"
done

report="$report\n$passed_tests tests passed out of $total_tests total tests."

echo -e "$report" > test_report.txt

cat test_report.txt
