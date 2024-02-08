#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void encrypt(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isascii(message[i])) {
            // Shift each character 5 positions to the right on the ASCII table
            message[i] = message[i] + 5;
        }
    }}

void decrypt(char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isascii(message[i])) {
            message[i] = message[i] - 5;
        }
    }}

bool isInteger(const char *str) {
    // Handle empty string
    if (str[0] == '\0') {
        return false;
    }

    char *endptr; // Used by strtol to check for conversion errors
    strtol(str, &endptr, 10);

    // If the entire string was not converted or the first character
    // after the conversion is not null (indicating extra characters),
    // it's not a valid integer.
    return *endptr == '\0';
}

void unary(int *msggg) {
    int val;
    if (isInteger(msggg)) {
        val = atoi(msggg);
        for (int i = 0; i < val; i++) {
            printf("1");
        }
        printf("0\n");
    } else {
        printf("Invalid Message\n");
    }
}
char *strrev(char *str){
    char *p1, *p2;
    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}
//Function to reverse the words in a string
void encode(char *str) {
    if (str && *str) {
        strrev(str);
    }
}

int main() {

    while(1) {
        char command[100];
        printf("Enter a command (encrypt/decrypt/unary/quit/encode): \n");
        fgets(command, sizeof(command), stdin);
        // Remove the newline character from the input
        if (command[strlen(command) - 1] == '\n') {
            command[strlen(command) - 1] = '\0';

            if (strcmp(command, "quit") == 0) {
                printf("Terminating the program.\n");
                break;
            }
            if (strncmp(command, "encrypt(", 8) == 0 && command[strlen(command) - 1] == ')') {
                // Extract the text inside parentheses
                char *token = strtok(command, "(");
                char *message;
                message = strtok(NULL, ")");
                if (message != NULL) {
                    if (strcmp(token, "encrypt") == 0) {
                        encrypt(message);
                        printf("Encrypted message: %s\n", message);
                    }
                }
            }

            if (strncmp(command, "decrypt(", 8) == 0 && command[strlen(command) - 1] == ')') {
                char *token = strtok(command, "(");

                if (token != NULL) {
                    if (strcmp(token, "decrypt") == 0) {
                        token = strtok(NULL, ")");
                        if (token != NULL) {
                            decrypt(token);
                            printf("Decrypted message: %s\n", token);
                        }

                    }
                }
            }
            if (strncmp(command, "encode(", 7) == 0 && command[strlen(command) - 1] == ')') {
                char *token = strtok(command, "(");
                if (token != NULL) {
                    if (strcmp(token, "encode") == 0) {
                        token = strtok(NULL, ")");
                        if (token != NULL) {
                            encode(token);
                            printf("encoded message: %s\n", token);
                        }

                    }
                }
            }
            if (strncmp(command, "unary(", 6) == 0 && command[strlen(command) - 1] == ')') {
                char *token = strtok(command, "(");
                if (token != NULL) {
                    if (strcmp(token, "unary") == 0) {
                        token = strtok(NULL, ")");
                        if (token != NULL) {
                            unary(token);
                        }
                    }
                }
            }
        }}
    return 0;}
