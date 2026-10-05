#!/bin/bash

# Compila o projeto
gcc -Wall -Wextra -Werror *.c -o rpn_calc 2>/dev/null
if [ $? -ne 0 ]; then
    echo -e "\033[0;31mErro de compilação!\033[0m"
    exit 1
fi

run_test() {
    local arg="$1"
    local expected="$2"
    local output

    if [ -z "$arg" ]; then
        output=$(./rpn_calc | cat -e)
    else
        output=$(./rpn_calc "$arg" | cat -e)
    fi

    if [ "$output" == "$expected" ]; then
        echo -e "\033[0;32m[OK]\033[0m Teste: ./rpn_calc \"$arg\" -> Resultado: $output"
    else
        echo -e "\033[0;31m[FAIL]\033[0m Teste: ./rpn_calc \"$arg\""
        echo -e "   Esperado: $expected"
        echo -e "   Obtido  : $output"
    fi
}

echo "=== INICIANDO TESTES ==="
run_test "3 4 +" "7$"
run_test "10 5 -" "5$"
run_test "6 7 *" "42$"
run_test "20 4 /" "5$"
run_test "10 3 %" "1$"
run_test "1 2 * 3 * 4 +" "10$"
run_test "5 10 9 / - 50 *" "200$"
run_test "3 1 2 * * 4 -" "2$"
run_test "-5 3 +" "-2$"
run_test "5 -3 *" "-15$"
run_test "-10 -2 /" "5$"
run_test "3   4   +" "7$"
run_test "  1  2  +  " "3$"

echo "=== TESTES DE ERRO ==="
run_test "" "Error$"
run_test "1 2 3 4 +" "Error$"
run_test "1 +" "Error$"
run_test "+ 1 2" "Error$"
run_test "1 2 a +" "Error$"
run_test "1 2 + +" "Error$"
run_test "10 0 /" "Error$"
run_test "10 0 %" "Error$"

rm -f rpn_calc
