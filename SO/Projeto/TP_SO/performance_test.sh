#!/bin/bash
export LC_NUMERIC="en_US.UTF-8"

# Configurações
SERVER_EXEC="./bin/dserver"
CLIENT_EXEC="./bin/dclient"
DOCS_DIR="Documents"
CACHE_DIR="Server_Cache"
RESULTS_FILE="performance.csv"
SEARCH_TERMS=("Deus" "Israel" "Cruz" "Jesus" "AG")

# Função de limpeza melhorada
cleanup() {
    echo "▶️ A preparar servidor..."
    "$CLIENT_EXEC" -f >/dev/null 2>&1
    sleep 1
    pkill -f "$SERVER_EXEC" 2>/dev/null
    rm -f /tmp/doc_pipe /tmp/client_* 2>/dev/null
}
trap cleanup EXIT

# Limpeza inicial
rm -rf "$CACHE_DIR" "$RESULTS_FILE"
mkdir -p "$CACHE_DIR"

# Iniciar servidor silenciosamente
echo "🔄 A iniciar servidor..."
"$SERVER_EXEC" "$DOCS_DIR" 10 >/dev/null 2>&1 &
SERVER_PID=$!
sleep 2

# Verificação robusta do servidor
if ! ps -p $SERVER_PID >/dev/null; then
    echo "❌ Servidor não iniciou corretamente"
    exit 1
fi

# Função de teste aprimorada
run_test() {
    local cmd="$1"
    local label="$2"
    local total=0
    local runs=3
    
    echo -n "🔍 A testar $label... "
    
    for ((i=1; i<=runs; i++)); do
        start=$(date +%s.%N)
        timeout 5 $cmd >/dev/null 2>&1
        end=$(date +%s.%N)
        runtime=$(echo "$end - $start" | bc -l)
        total=$(echo "$total + $runtime" | bc -l)
        echo -n "."
        sleep 0.3
    done
    
    avg=$(echo "scale=4; $total/$runs" | bc -l)
    printf " %.4f s\n" $avg
    echo "$label,$avg" >> "$RESULTS_FILE"
}

# Cabeçalho do CSV
echo "test_type,time_seconds" > "$RESULTS_FILE"

# 1. Testes de Busca Paralela
echo "🔎 TESTES DE BUSCA PARALELA"
for term in "${SEARCH_TERMS[@]}"; do
    for threads in 1 1000; do
        run_test "$CLIENT_EXEC -s '$term' $threads" "search_${term}_${threads}threads"
    done
done