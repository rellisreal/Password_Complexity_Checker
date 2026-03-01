#include "main.h"
#include "logger/logger.h"
#include <iso646.h>
#include <stdio.h>

int main() {
    const char capitalValues[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numericValues[] = "1234567890";
    const char symbolicValues[] = "!@#$%^&*()_+-=;'[],.<>/:";
    int results[3] = {0,0,0};
    int i; 
    char buffer[1000];
    char *password;

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
        if (strchr(capitalValues, password[i])) {results[0]=1;}
        if (strchr(numericValues, password[i])) {results[1]=1;}
        if (strchr(symbolicValues, password[i])) {results[2]=1;}
    }
    free(password);
    if (complexityChecker(results) == 1) {return 1;};
    return 0;
}

int complexityChecker(int results[]) {
    int i; 
    log_message("Checking Complexity");
    for (i = 0; i < 3; i++) {
        if (results[i] == 0)
        {
            printf("\n the number is %d \n", i);
            if (i == 0) {printf("Please add a capital charachter\n");};
            if (i == 1) {printf("Please add a numeric charachter\n");};
            if (i == 2) {printf("Please add a symbol\n");};
            return 1;
        };
    }
    printf("Password is secure\n");   
    return 0; 
}