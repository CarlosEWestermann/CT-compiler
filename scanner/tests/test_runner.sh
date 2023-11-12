#!/bin/bash

# Navegar para o diretório pai e executar o makefile
cd ..
make
cd -

# Criar diretório para as saídas dos testes
mkdir -p actual_outputs

# Contadores para os testes totais e testes aprovados
total_tests=0
passed_tests=0

# Iniciar o relatório de testes
report="Test Report\n\n"

# Percorrer todos os arquivos de teste na pasta inputs
for testcase in inputs/*.txt; do
    total_tests=$((total_tests + 1))

    # Obter o nome do arquivo
    filename=$(basename $testcase)
    
    echo "Running test: $filename"
    
    # Executar o parser e salvar a saída no diretório actual_outputs
    ../etapa2 < $testcase > actual_outputs/$filename
    
    # Comparar a saída com a saída esperada
    if diff -q expected_outputs/$filename actual_outputs/$filename; then
        echo "Test $filename PASSED"
        report="$report$filename: PASSED\n"
        
        passed_tests=$((passed_tests + 1))
    else
        echo "Test $filename FAILED"
        report="$report$filename: FAILED\n"
    fi

    echo "-------------------------"
done

# Finalizar o relatório de testes
report="$report\n$passed_tests tests passed out of $total_tests total tests."

# Salvar e mostrar o relatório
echo -e "$report" > test_report.txt

cat test_report.txt
