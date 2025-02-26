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

# Corriger l'indentation avec clang-format
clang-format -style=Google -i "$FILE"

# Remplacer les espaces par des tabulations (si Betty demande des tabs)
sed -i 's/^    /\t/g' "$FILE"

# Supprimer les espaces au début des lignes
sed -i 's/^[ ]\+//g' "$FILE"

# Mettre les { sur la ligne suivante après une fonction et une condition
sed -i 's/){/)\n{/' "$FILE"
sed -i 's/if (/if\n(/' "$FILE"
sed -i 's/while (/while\n(/' "$FILE"

# Séparer les instructions sur plusieurs lignes
sed -i 's/\(if.*)\) \(.*;\)/\1\n\t\2/g' "$FILE"

# Vérifier avec betty-style après correction
betty-style "$FILE"

echo "✅ Correction terminée ! Vérifie avec betty-doc si nécessaire."

