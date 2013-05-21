#include <stdio.h>
#include <string.h>

unsigned taille_chaine(char *ch)
{
    return strlen(ch);
}

int est_palindrome(char *ch);

// Ce programme lit ses parametres sur la ligne de commande.
// On peut par exemple l'appeler avec :
//   ./palindrome "chaine1" "la chaine 2" ""
// pour lui passer comme parametres : chaine1, la chaine 2
//   (considere comme un seul parametre), et la chaine vide
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        if (est_palindrome(argv[i])) {
            printf("\"%s\" est un palindrome.\n", argv[i]);
        } else {
            printf("\"%s\" n'est pas un palindrome.\n", argv[i]);
        }
    }
    return 0;
}
