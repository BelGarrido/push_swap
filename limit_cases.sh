#!/bin/bash

OUTPUT_FILE="push_swap_tests.log"
echo "=== Test de casos límite push_swap ===" > "$OUTPUT_FILE"
echo "" >> "$OUTPUT_FILE"

# Lista de casos estáticos
cases=(
    ""
    "42"
    "1 2 3 4 5"
    "5 4 3 2 1"
    "2 1 4 3 6 5"
    "100 1 2 3 4"
    "1 2 3 5 4 6 7 8 9 10"
    "3 4 5 6 7 8 9 10 1 2"
    "50 1 49 2 48 3 47 4 46 5"
    "1 3 2"
    "2 1 3"
    "3 2 1"
)

# Ejecutar los casos estáticos
for case in "${cases[@]}"; do
    echo "Probando caso: \"$case\""
    result=$(./push_swap "$case")
    op_count=$(echo "$result" | wc -l)

    {
        echo "==============================="
        echo "Caso: \"$case\""
        echo "Número de operaciones: $op_count"
        echo ""
        echo "$result" | tail -n 50
        echo ""
    } >> "$OUTPUT_FILE"
done

# Casos dinámicos generados con Python
# Generar y probar 100 números aleatorios únicos
case_100=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 101), 100))))")
echo "Probando caso de 100 números aleatorios"
result_100=$(./push_swap "$case_100")
op_count_100=$(echo "$result_100" | wc -l)

{
    echo "==============================="
    echo "Caso: 100 números aleatorios"
    echo "Número de operaciones: $op_count_100"
    echo ""
    echo "$result_100" | tail -n 130
    echo ""
} >> "$OUTPUT_FILE"

# Generar y probar 500 números aleatorios únicos
case_500=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 501), 500))))")
echo "Probando caso de 500 números aleatorios"
result_500=$(./push_swap "$case_500")
op_count_500=$(echo "$result_500" | wc -l)

{
    echo "==============================="
    echo "Caso: 500 números aleatorios"
    echo "Número de operaciones: $op_count_500"
    echo ""
    echo "$result_500" | tail -n 530
    echo ""
} >> "$OUTPUT_FILE"

echo "✅ Todas las pruebas finalizadas. Revisa '$OUTPUT_FILE'."
