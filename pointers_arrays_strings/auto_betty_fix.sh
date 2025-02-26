#!/bin/bash

# Vérifie si un fichier est donné
if [ $# -eq 0 ]; then
    echo "Usage: ./fix_betty.sh fichier.c"
    exit 1
fi

FILE="$1"

# Vérifie si le fichier existe
if [ ! -f "$FILE" ]; then
    echo "Erreur : fichier '$FILE' non trouvé."
    exit 1
fi

echo "🔧 Correction automatique du style Betty pour $FILE..."

# Corriger l'indentation et la mise en forme
clang-format -style=Google -i "$FILE"

# Remplacer les espaces par des tabulations (si Betty demande des tabs)
sed -i 's/    /\t/g'
