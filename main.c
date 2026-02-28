#include "main.h"
#include "logger/logger.h"

int main() {
    const char capitalValues[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numericValues[] = "1234567890";
    const char symbolicValues[] = "!@#$%^&*()_+-=;'[],.<>/:";
    char buffer[1000];
    char *password;
    int i; 
    int hasCaps = 0;
    int hasNumeric = 0; 
    int hasSymbol= 0; 
    
    log_message("Starting Application");
    printf("\nRequirements: 8+ Charachters\n-Numeric Charachter \n-Capital Chara \nPlease insert a password: ");
    scanf("%999s", buffer);
    if (strlen(buffer) < 8) {
        printf("Password Complexity Failed (Needs to be more than 8 charachters): %s", buffer);
        return 1; 
    };
    password = malloc(strlen(buffer) + 1);
    if (password == NULL)
    {
        printf("Password memory allocation failed\n");
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
        printf("Password Complexity Test Passed\n");
        return 0; 
    }
    else if (hasCaps==0) {
        printf("Please add a capital charachter\n");
        return 1;
    }
    else if (hasNumeric==0) {
        printf("Please add a Numeric charachter\n");
        return 1;
    }
    else if (hasSymbol==0) {
        printf("Please add a Symbolic charachter\n");
        return 1;
    }
    else {
        printf("Password Complexity Test Failed\n");
        return 1; 
    }
}