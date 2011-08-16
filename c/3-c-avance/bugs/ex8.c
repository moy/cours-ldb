/*
  Un petit exercice sur les pointeurs de fonction.

  Là aussi, votre compilateur vous donnera la solution si vous
  l'appelez avec les bonnes options, pour avoir un maximum de 
  warnings.
*/
#include <stdio.h>

const int TRUE = 1;
const int FALSE = 0;

int function_returning_false() {return FALSE;}

int main() {
	if (function_returning_false) {
		printf("function returned true\n");
	}
}
