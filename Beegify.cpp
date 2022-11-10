/*------------------------------------------------------------------------------------------------------------------
* Beegify: takes input text string and converts it into large, 5 line tall ASCII art
* 
* Author:	Cameron Jupp
* Created:	Summer 2021
* Edited:	September 18th, 2022
-------------------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void beegify(const char* text);
void allLower(char* string);

//const char* [5] = { "","","","","" };

//Uppercase letters
const char* A[5] = { "      _     ","     / \\    ","    / _ \\   ","   / ___ \\  ","  /_/   \\_\\ " };
const char* B[5] = { "  ____   "," | __ )  "," |  _ \\  "," | |_) | "," |____/  " };
const char* C[5] = { "   ____  ","  / ___| "," | |     "," | |___  ","  \\____| " };
const char* D[5] = { "  ____   "," |  _ \\  "," | | | | "," | |_| | "," |____/  " };
const char* E[5] = { "  _____  "," | ____| "," |  _|   "," | |___  "," |_____| " };
const char* F[5] = { "  _____  "," |  ___| "," | |_    "," |  _|   "," |_|     " };
const char* G[5] = { "   ____  ","  / ___| "," | |  _  "," | |_| | ","  \\____| " };
const char* H[5] = { "  _   _  "," | | | | "," | |_| | "," |  _  | "," |_| |_| " };
const char* I[5] = { "  ___  "," |_ _| ","  | |  ","  | |  "," |___| " };
const char* J[5] = { "      _  ","     | | ","  _  | | "," | |_| | ","  \\___/  " };
const char* K[5] = { "  _  __ "," | |/ / "," | ' /  "," | . \\  "," |_|\\_\\ " };
const char* L[5] = { "  _      "," | |     "," | |     "," | |___  "," |_____| " };
const char* M[5] = { "  __  __  "," |  \\/  | "," | |\\/| | "," | |  | | "," |_|  |_| " };
const char* N[5] = { "  _   _  "," | \\ | | "," |  \\| | "," | |\\  | "," |_| \\_| " };
const char* O[5] = { "   ___   ","  / _ \\  "," | | | | "," | |_| | ","  \\___/  " };
const char* P[5] = { "  ____   "," |  _ \\  "," | |_) | "," |  __/  "," |_|     " };
const char* Q[5] = { "   ___   ","  / _ \\  "," | | | | "," | |_| | ","  \\__\\_\\ " };
const char* R[5] = { "  ____   "," |  _ \\  "," | |_) | "," |  _ <  "," |_| \\_\\ " };
const char* S[5] = { "  ____   "," / ___|  "," \\___ \\  ","  ___) | "," |____/  " };
const char* T[5] = { "  _____  "," |_   _| ","   | |   ","   | |   ","   |_|   " };
const char* U[5] = { "  _   _  "," | | | | "," | | | | "," | |_| | ","  \\___/  " };
const char* V[5] = { " __     __ "," \\ \\   / / ","  \\ \\ / /  ","   \\ V /   ","    \\_/    " };
const char* W[5] = { " __        __ "," \\ \\      / / ","  \\ \\ /\\ / /  ","   \\ V  V /   ","    \\_/\\_/    " };
const char* X[5] = { " __  __ "," \\ \\/ / ","  \\  /  ","  /  \\  "," /_/\\_\\ " };
const char* Y[5] = { " __   __ "," \\ \\ / / ","  \\ V /  ","   | |   ","   |_|   " };
const char* Z[5] = { "  _____ "," |__  / ","   / /  ","  / /_  "," /____| " };
//Symbols
const char* forwardSlash[5] = { "     __ ","    / / ","   / /  ","  / /   "," /_/    " };
const char* backSlash[5] = { " __     "," \\ \\    ","  \\ \\   ","   \\ \\  ","    \\_\\ " };
const char* period[5] = { "      ","      ","      ","  __  "," |__| " };
const char* comma[5] = { "     ","     ","     "," ___ "," )_/ " };
const char* apostraphe[5] = { "  __ "," |_/ ","     ","     ","     " };
const char* exclamation[5] = { "  _  "," | | "," | | "," |_| "," (_) " };
const char* plus[5] = { "     __    ","  __|  |__ "," |__   __| ","    |__|   ","           " };
const char* minus[5] = { "         ","  _____  "," |_____| ","         ","         " };
const char* equals[5] = { "  _____  "," |_____| ","  _____  "," |_____| ","         " };
const char* arrowLeft[5] = { "   __ ","  / / "," / /  "," \\ \\  ","  \\_\\ " };
const char* arrowRight[5] = { " __   "," \\ \\  ","  \\ \\ ","  / / "," /_/  " };
const char* colon[5] = { "  __  "," |__| ","  __  "," |__| ","      " };
const char* semicolon[5] = { "  __  "," |__| ","  __  "," | _| "," |/   " };



//Numbers
const char* zero[5] = { "   ___   ","  / _ \\  "," | | | | "," | |_| | ","  \\___/  " };
const char* one[5] = { "  _  "," / | "," | | "," | | "," |_| " };
const char* two[5] = { "  ____   "," |___ \\  ","   __) | ","  / __/  "," |_____| " };
const char* three[5] = { "  _____  "," |___ /  ","   |_ \\  ","  ___) | "," |____/  " };
const char* four[5] = { "  _  _    "," | || |  "," | || |_  "," |__   _| ","    |_|   " };
const char* five[5] = { "  ____   ","  | ___|  "," |___ \\  ","  ___) | "," |____/  " };
const char* six[5] = { "   __    ","  / /_   "," | '_ \\  "," | (_) | ","  \\___/  " };
const char* seven[5] = { "  _____  "," |___  | ","    / /  ","   / /   ","  /_/    " };
const char* eight[5] = { "   ___   ","  ( _ )  ","  / _ \\  "," | (_) | ","  \\___/  " };
const char* nine[5] = { "   ___   ","  / _ \\  "," | (_) | ","  \\__, | ","    /_/  " };


/*

Letters:
 |	   _     |  ____   |   ____  |  ____   |  _____  |  _____  |   ____  |  _   _  |  ___  |      _  |  _  __ |  _      |  __  __  |  _   _  |   ___   |  ____   |   ___   |  ____   |  ____   |  _____  |  _   _  | __     __ | __        __ | __  __ | __   __ |  _____ |
 |	  / \    | | __ )  |  / ___| | |  _ \  | | ____| | |  ___| |  / ___| | | | | | | |_ _| |     | | | | |/ / | | |     | |  \/  | | | \ | | |  / _ \  | |  _ \  |  / _ \  | |  _ \  | / ___|  | |_   _| | | | | | | \ \   / / | \ \      / / | \ \/ / | \ \ / / | |__  / |
 | 	 / _ \   | |  _ \  | | |     | | | | | | |  _|   | | |_    | | |  _  | | |_| | |  | |  |  _  | | | | ' /  | | |     | | |\/| | | |  \| | | | | | | | | |_) | | | | | | | | |_) | | \___ \  |   | |   | | | | | |  \ \ / /  |  \ \ /\ / /  |  \  /  |  \ V /  |   / /  |
 |  / ___ \  | | |_) | | | |___  | | |_| | | | |___  | |  _|   | | |_| | | |  _  | |  | |  | | |_| | | | . \  | | |___  | | |  | | | | |\  | | | |_| | | |  __/  | | |_| | | |  _ <  |  ___) | |   | |   | | |_| | |   \ V /   |   \ V  V /   |  /  \  |   | |   |  / /_  |
 | /_/   \_\ | |____/  |  \____| | |____/  | |_____| | |_|     |  \____| | |_| |_| | |___| |  \___/  | |_|\_\ | |_____| | |_|  |_| | |_| \_| |  \___/  | |_|     |  \__\_\ | |_| \_\ | |____/  |   |_|   |  \___/  |    \_/    |    \_/\_/    | /_/\_\ |   |_|   | /____| |


 Characters:

 |     __ | __     |      |     |  __ |  _  |     __    |         |  _____  |   __ | __   |  __  |  __  |                       
 |    / / | \ \    |      |     | |_/ | | | |  __|  |__ |  _____  | |_____| |  / / | \ \  | |__| | |__| |
 |   / /  |  \ \   |      |     |     | | | | |__   __| | |_____| |  _____  | / /  |  \ \ |  __  |  __  |                  
 |  / /   |   \ \  |  __  | ___ |     | |_| |    |__|   |         | |_____| | \ \  |  / / | |__| | | _| |                        
 | /_/    |    \_\ | |__| | )_/ |     | (_) |           |         |         |  \_\ | /_/  |      | |/   |            


 Numbers:

 |  _  |  ____   |  _____  |  _  _    |  ____   |   __    |  _____  |   ___   |   ___   |   ___   | 
 | / | | |___ \  | |___ /  | | || |   | | ___|  |  / /_   | |___  | |  ( _ )  |  / _ \  |  / _ \  |
 | | | |   __) | |   |_ \  | | || |_  | |___ \  | | '_ \  |    / /  |  / _ \  | | (_) | | | | | | |
 | | | |  / __/  |  ___) | | |__   _| |  ___) | | | (_) | |   / /   | | (_) | |  \__, | | | |_| | | 
 | |_| | |_____| | |____/  |    |_|   | |____/  |  \___/  |  /_/    |  \___/  |    /_/  |  \___/  |
                                                                                               
*/


int main()
{
	char text[100];
	int i = 0;
	while (1)
	{


		gets_s(text, 100);

		allLower(text);

		printf_s(text);
		printf_s("\n");

		beegify(text);

		printf_s("\n");


	}

}

void allLower(char* string)
{
	while (*string)
	{
		if (*string >= 65 && *string <= 90)
		{
			*string += 32;
		}
		string++;

	}
}


void beegify(const char* text)
{
	int i = 0;
	int j = 0;
	do
	{
		do
		{
			char character = text[i];

			switch (character)
			{
			/*case '':
				printf("%s", [j]);
				break; */



			case 'a':
				printf("%s", A[j]);
				break;

			case 'b':
				printf("%s", B[j]);
				break;

			case 'c':
				printf("%s", C[j]);
				break;

			case 'd':
				printf("%s", D[j]);
				break;

			case 'e':
				printf("%s", E[j]);
				break;

			case 'f':
				printf("%s", F[j]);
				break;

			case 'g':
				printf("%s", G[j]);
				break;

			case 'h':
				printf("%s", H[j]);
				break;

			case 'i':
				printf("%s", I[j]);
				break;

			case 'j':
				printf("%s", J[j]);
				break;

			case 'k':
				printf("%s", K[j]);
				break;

			case 'l':
				printf("%s", L[j]);
				break;

			case 'm':
				printf("%s", M[j]);
				break;

			case 'n':
				printf("%s", N[j]);
				break;

			case 'o':
				printf("%s", O[j]);
				break;

			case 'p':
				printf("%s", P[j]);
				break;

			case 'q':
				printf("%s", Q[j]);
				break;

			case 'r':
				printf("%s", R[j]);
				break;

			case 's':
				printf("%s", S[j]);
				break;

			case 't':
				printf("%s", T[j]);
				break;

			case 'u':
				printf("%s", U[j]);
				break;

			case 'v':
				printf("%s", V[j]);
				break;

			case 'w':
				printf("%s", W[j]);
				break;

			case 'x':
				printf("%s", X[j]);
				break;

			case 'y':
				printf("%s", Y[j]);
				break;

			case 'z':
				printf("%s", Z[j]);
				break;



			case ' ':
				printf("     ");
				break;
			case '+':
				printf("%s", plus[j]);
				break;
			case '-':
				printf("%s", minus[j]);
				break;
			case '!':
				printf("%s", exclamation[j]);
				break;
			case '.':
				printf("%s", period[j]);
				break;
			case '\'':
				printf("%s", apostraphe[j]);
				break;
			case ',':
				printf("%s", comma[j]);
				break;
			case '/':
				printf("%s", forwardSlash[j]);
				break;
			case '\\':
				printf("%s", backSlash[j]);
				break;
			case '=':
				printf("%s", equals[j]);
				break;
			case '<':
				printf("%s", arrowLeft[j]);
				break;
			case '>':
				printf("%s", arrowRight[j]);
				break;
			case ':':
				printf("%s", colon[j]);
				break;
			case ';':
				printf("%s", semicolon[j]);
				break;



			case '0':
				printf("%s", zero[j]);
				break;
			case '1':
				printf("%s", one[j]);
				break;
			case '2':
				printf("%s", two[j]);
				break;
			case '3':
				printf("%s", three[j]);
				break;
			case '4':
				printf("%s", four[j]);
				break;
			case '5':
				printf("%s", five[j]);
				break;
			case '6':
				printf("%s", six[j]);
				break;
			case '7':
				printf("%s", seven[j]);
				break;
			case '8':
				printf("%s", eight[j]);
				break;
			case '9':
				printf("%s", nine[j]);
				break;
			}

		} while (text[i++] != '\0');

		i = 0;

		printf("\n");

	}while (j++ < 4);
}


