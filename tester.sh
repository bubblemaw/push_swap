#!/bin/zsh

INT_MIN=-2147483648
INT_MAX=2147483647

if [ -z "$1" ]; then
  echo "Veuillez spécifier le nombre de nombres aléatoires à générer."
  exit 1
fi

NUMBERS_COUNT=$1

if [ "$NUMBERS_COUNT" -gt $((INT_MAX - INT_MIN + 1)) ]; then
  echo "Erreur : Le nombre de valeurs demandé dépasse la plage de valeurs uniques possibles entre $INT_MIN et $INT_MAX."
  exit 1
fi

typeset -a all_numbers
typeset -a selected_numbers
ARG=""

for ((i=0; i<$NUMBERS_COUNT; i++)); do
  random_number=$(( RANDOM * RANDOM % (INT_MAX - INT_MIN + 1) + INT_MIN ))
  
  if (( random_number % 2 != 0 )); then
    random_number=$(( random_number * -1 ))
  fi
  
  all_numbers+=($random_number)
done

selected_numbers=("${(U)all_numbers}")

while [ ${#selected_numbers[@]} -lt $NUMBERS_COUNT ]; do
  random_number=$(( RANDOM * RANDOM % (INT_MAX - INT_MIN + 1) + INT_MIN ))
  
  if (( random_number % 2 != 0 )); then
    random_number=$(( random_number * -1 ))
  fi
  
  if [[ ! " ${selected_numbers[@]} " =~ " ${random_number} " ]]; then
    selected_numbers+=($random_number)
  fi
done

for num in "${selected_numbers[@]}"; do
  ARG+="$num "
done

echo "Suite de nombres générée : $ARG"


echo "Exécution de push_swap..."
start_time_push_swap=$(date +%s)
push_swap_output=$(./push_swap $ARG)
end_time_push_swap=$(date +%s)
execution_time_push_swap=$(( end_time_push_swap - start_time_push_swap ))
echo "Temps d'exécution de push_swap : $execution_time_push_swap secondes"

echo "Exécution de checker_Mac..."
start_time_checker=$(date +%s)
echo "$push_swap_output" | ./checker_Mac $ARG
end_time_checker=$(date +%s)
execution_time_checker=$(( end_time_checker - start_time_checker ))
echo "Temps d'exécution de checker_Mac : $execution_time_checker secondes"
