🔁 STRUCTURE DU PROJET

Voici la structure de ton dépôt GitHub :

holbertonschool-printf/
├── main.h             → les prototypes (les déclarations)
├── _putchar.c         → fonction pour afficher 1 caractère
├── _printf.c          → la fonction principale + %c, %s, %%
├── print_int.c        → %d et %i
└── test/
    └── main.c         → pour tester ton _printf

📁 1. main.h → Le fichier d'en-tête

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_int(va_list args);
int print_number(unsigned int num);
int handle_format(const char *format, va_list args, int i, int *count);

#endif /* MAIN_H */

🔍 Explication ligne par ligne :

    #ifndef MAIN_H / #define MAIN_H → évite que le fichier soit inclus plusieurs fois par erreur

    #include <stdarg.h> → obligatoire pour gérer les ... dans _printf

    #include <unistd.h> → donne accès à write(), utilisé dans _putchar

    Ensuite on déclare toutes les fonctions qu'on va utiliser dans le projet

    ✨ Ce fichier sert à "annoncer" toutes les fonctions que tu as ailleurs, pour que les autres fichiers sachent qu’elles existent.

📁 2. _putchar.c → Affiche un seul caractère

#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

🔍 Explication simple :

    Tu utilises write() pour afficher un seul caractère sur l'écran

    1 → stdout = terminal

    &c → adresse du caractère

    1 → longueur (1 caractère)

    🧠 On l’utilise partout à la place de putchar() ou printf() (interdits !)

📁 3. _printf.c → La fonction principale

Contient 5 fonctions :

    _printf → principale

    handle_format → gère les formats

    print_char

    print_string

    print_percent

🔷 _printf

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			i = handle_format(format, args, i, &count);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

🔍 Étape par étape :

    va_list args; → on prépare une "boîte" d’arguments

    va_start(args, format); → on ouvre cette boîte

    On parcourt chaque caractère de la chaîne format

    Si c’est un %, on regarde ce qu’il y a après et on appelle handle_format

    Sinon, on affiche le caractère normal avec _putchar

    À la fin, on ferme va_end et on retourne combien de caractères ont été affichés

🔷 handle_format

int handle_format(const char *format, va_list args, int i, int *count)
{
	if (format[i + 1] == 'c')
		*count += print_char(args);
	else if (format[i + 1] == 's')
		*count += print_string(args);
	else if (format[i + 1] == '%')
		*count += print_percent();
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		*count += print_int(args);
	else
	{
		_putchar('%');
		_putchar(format[i + 1]);
		*count += 2;
	}
	return (i + 1);
}

🔍 Ce qu’elle fait :

Quand _printf rencontre un %, cette fonction décide quoi faire ensuite :
format[i+1]	Appelle
'c'	print_char()
's'	print_string()
'%'	print_percent()
'd'/'i'	print_int()
Autre	affiche %X comme %r, %u → %r
🔷 print_char

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

➡️ On récupère le prochain argument (un int), on l’affiche avec _putchar.
🔷 print_string

int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

➡️ Récupère une chaîne (char *)
➡️ Affiche chaque lettre avec _putchar
➡️ Si la chaîne est NULL → affiche (null)
🔷 print_percent

int print_percent(void)
{
	return (_putchar('%'));
}

➡️ Affiche juste %
📁 4. print_int.c → Gestion de %d et %i

Contient 2 fonctions : print_int et print_number
🔷 print_int

int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	count += print_number(num);
	return (count);
}

➡️ Récupère un nombre signé (int)
➡️ Si négatif → affiche - et convertit en positif
➡️ Puis appelle print_number
🔷 print_number

int print_number(unsigned int num)
{
	int count = 0;

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar((num % 10) + '0');
	return (count);
}

➡️ Fonction récursive
➡️ Affiche chaque chiffre du nombre (de gauche à droite)
➡️ Exemple : 123 devient '1', '2', '3'
📁 5. test/main.c → Pour tester

#include "../main.h"
#include <stdio.h>

int main(void)
{
	int len1 = _printf("Salut %s\n", "toi");
	int len2 = printf("Salut %s\n", "toi");

	_printf("Len: %d\n", len1);
	printf("Len: %d\n", len2);

	return (0);
}

➡️ Compare le comportement de ton _printf() avec le vrai printf()
➡️ Les len1 et len2 permettent de vérifier que tu renvoies le bon nombre de caractères affichés





FONCTIONNEMENT GÉNÉRAL
❓1. Que fait exactement ta fonction _printf ?

    Elle lit une chaîne de caractères (format) caractère par caractère.
    Quand elle rencontre un %, elle regarde le caractère suivant pour savoir quel type d’argument afficher (%c, %s, %d, etc.).
    Ensuite, elle appelle la bonne fonction pour afficher la valeur.

❓2. Pourquoi as-tu besoin de va_list, va_start, va_arg, va_end ?

    Parce que _printf accepte un nombre d'arguments inconnu grâce aux ....
    va_list est la structure qui stocke ces arguments.
    va_start initialise cette liste.
    va_arg permet d’aller chercher chaque argument un par un.
    va_end termine proprement la lecture.

❓3. Comment _printf gère le % ?

    Quand il voit %, il regarde le caractère juste après.
    Il envoie ça à la fonction handle_format(), qui décide quelle fonction appeler :
    print_char, print_string, print_int, print_percent, ou alors il affiche %X si c’est inconnu.

🧩 FORMATS
❓4. Quels formats sont pris en charge dans ton projet ?

    %c, %s, %%, %d, %i
    Les autres comme %u, %x, %p, %o ne sont pas demandés dans le projet de base, donc je les affiche tels quels.

❓5. Quelle différence entre %d et %i ?

    Aucune dans ce projet. Les deux servent à afficher un entier signé.
    Je les gère tous les deux avec la même fonction : print_int().

❓6. Comment tu affiches un nombre entier (%d) ?

    Je vérifie d’abord s’il est négatif.
    Si oui, j’affiche - et je travaille avec le positif.
    Ensuite, j’appelle print_number() pour afficher chiffre par chiffre.

❓7. Comment tu affiches chaque chiffre ?

    J’utilise une fonction récursive print_number().
    Si le nombre est plus grand que 10, je l’appelle sur num / 10.
    Puis j’affiche le chiffre des unités avec _putchar((num % 10) + '0').

🔐 CONTRAINTES
❓8. As-tu respecté toutes les contraintes Holberton ?

    Oui :

    Aucune variable globale

    Pas plus de 5 fonctions par fichier

    Pas plus de 40 lignes par fonction

    Tous les fichiers sont Betty OK

    J’utilise write() uniquement via ma fonction _putchar

    Pas de main dans les fichiers à la racine

    Aucun warning avec valgrind ou à la compilation

❓9. Que retourne _printf à la fin ?

    Le nombre total de caractères affichés, comme la vraie fonction printf.

❓10. Que fait _printf("%") ?

    C’est un cas d’erreur : il n’y a pas de caractère après le %.
    Je retourne donc -1, comme demandé par les instructions du projet.

🧠 CODE & STRUCTURE
❓11. Pourquoi avoir séparé le projet en plusieurs fichiers ?

    Pour respecter la contrainte de maximum 5 fonctions par fichier,
    et aussi pour garder un code clair et bien organisé.

❓12. À quoi sert _putchar ?

    C’est une petite fonction qui utilise write() pour afficher un seul caractère.
    Elle me permet de ne pas écrire write(1, &c, 1) partout.

❓13. Pourquoi tu utilises unsigned int dans print_int ?

    Pour convertir les entiers négatifs en positifs.
    -n sur un int négatif peut poser problème, donc je le stocke dans un unsigned int pour éviter les erreurs.

⚠️ QUESTIONS PIÈGE
❓14. Que se passe-t-il si format == NULL ?

    Je retourne -1.
    C’est le tout début de la fonction _printf : je vérifie si format est NULL pour éviter de lire quelque chose qui n’existe pas.

❓15. Que fait _printf("%z") ?

    Comme %z n’est pas reconnu, je l’affiche tel quel : %z.
    Ce comportement est géré dans handle_format() → default : j’affiche % + le caractère.

/





🟢 1. Start Printf

C’est l’appel de la fonction par l’utilisateur :

_printf("Salut %s", "Betty");

🔵 2. Vérification : format == NULL ?

Si format est nul, le programme retourne immédiatement -1 pour éviter une erreur :

if (format == NULL)
    return (-1);

🔵 3. Initialisation de va_list

Initialisation de la gestion des arguments variables :

va_list args;
va_start(args, format);

🔁 4. Boucle : format[i] != '\0'

Parcours caractère par caractère de la chaîne format :

while (format[i]) { ... }

🔍 5. Si format[i] == '%'

Tu vérifies si le caractère est %. Si oui, tu examines format[i + 1].
🔢 6. Analyse de format[i + 1]

En fonction du caractère suivant %, tu appelles la bonne fonction :
Caractère	Action
'c'	print_char(args)
's'	print_string(args)
'd' / 'i'	print_int(args)
'%'	print_percent()
autre	Affiche % suivi du caractère inconnu
🟡 7. Fonctions appelées selon le format

    print_char(args) : affiche un seul caractère

    print_string(args) : affiche une chaîne de caractères

    print_int(args) : affiche un entier signé (gère aussi les négatifs)

    print_percent() : affiche simplement %

⚠️ 8. Format inconnu

Si % est suivi d’un caractère non reconnu (ex: %r, %z),
tu affiches :

_putchar('%');
_putchar(format[i + 1]);

🔄 9. i++ et continuation

Après avoir traité un format (%s, %d, etc.), tu avances dans la chaîne avec i++ pour continuer la boucle.
🛑 10. Fin de la boucle while

Quand tu atteins \0 (fin de la chaîne), la boucle se termine.
✅ 11. Nettoyage : va_end(args)

Tu termines proprement la lecture des arguments :

va_end(args);

🔚 12. Retour : return count

Tu retournes le nombre total de caractères affichés :

return (count);