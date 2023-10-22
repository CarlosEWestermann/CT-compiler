cd ..
make
cd -

mkdir -p actual_outputs

total_tests=0
passed_tests=0

report="Test Report\n\n"

for testcase in inputs/*.txt; do
    total_tests=$((total_tests + 1))

    filename=$(basename $testcase)
    
    echo "Running test: $filename"
    
    ../scanner < $testcase > actual_outputs/$filename
    
    if diff -q expected_output/$filename actual_outputs/$filename; then
        echo "Test $filename PASSED"
        report="$report$filename: PASSED\n"
        
        passed_tests=$((passed_tests + 1))
    else
        echo "Test $filename FAILED"
        report="$report$filename: FAILED\n"
    fi

    echo "-------------------------"
done

report="$report\n$passed_tests tests passed out of $total_tests total tests."

echo -e $report > test_report.txt

cat test_report.txt
