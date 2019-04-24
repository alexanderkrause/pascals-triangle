#include <stdio.h>

int main() {
    int n;
	printf("Wie viele Ebenen?");
	scanf("%d", &n);
    int triangle[n + 1][n + 1];
    
	for (int row = 0; row <= n; row++) {
        for (int index = 0; index <= row; index++) {
            if (index == 0) {
            triangle[row][index] = 1;
            }
            else if (index == row) {
                triangle[row][index] = 1;
            }
            else {
                triangle[row][index] = triangle[row - 1][index - 1] + triangle[row - 1][index];
            }
        }
    }
	
	int stellenDerAusgabe = 5;
	
    for (int i = 0; i <= n; i++) {				//(Stellen der Ausgabe + 1) / 2 frei lassen
		int a = 0;
		while (a < n - i) {
			a++;
			int b = 0;
			while (b < (stellenDerAusgabe + 1) / 2) {
				b++;
				printf(" ");
			}
		}
		
        for (int j = 0; j <= i; j++) {
            printf("%5d", triangle[i][j]);		//Stellen der Ausgabe beachten, sollte ungerade sein
			printf(" ");
        }
        printf("\n");
    }
	
	getchar();
	printf("\nContinue...");
	getchar();
	
	return 0;
}