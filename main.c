#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

int main() {
    const char capitalValues[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numericValues[] = "1234567890";
    const char symbolicValues[] = "!@#$%^&*()_+-=;'[],.<>/:";
    char buffer[1000];
    char* password;
    int i; 
    int hasCaps = 0;
    int hasNumeric = 0; 
    int hasSymbol= 0; 
    
    printf("\nRequirements: 8+ Charachters \n -Numeric Charachter \n -Capital Chara \n Please insert a password: ");
    scanf("%999s", buffer);
    if (strlen(buffer) < 8) {
        printf("Password Complexity Failed (Needs to be more than 8 charachters): %s", buffer);
        return 1; 
    };
    password = malloc(strlen(buffer) + 1);
    if (password == NULL)
    {
        printf("Password memory allocation failed \n");
        return 1;
    }
    strcpy(password,buffer);

    for (i = 0; i < strlen(password); i++) {
        if (strchr(capitalValues, password[i])) {hasCaps=1;}
        if (strchr(numericValues, password[i])) {hasNumeric=1;}
        if (strchr(symbolicValues, password[i])) {hasSymbol=1;}
    }
    free(password);
    if (hasCaps==1 && hasNumeric==1 && hasSymbol==1) {
        printf("Password Complexity Passed: %s", password);
        return 0; 
    }
    else {
        printf("Password Complexity Failed: %s", password);
        return 1; 
    }
}