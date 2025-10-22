#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main() {
    char input[MAX_LEN];
    char cleaned[MAX_LEN];
    int i, j = 0;

    printf("Enter a string: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    input[strcspn(input, "\n")] = '\0';

    // Clean the input: keep only letters, convert to lowercase
    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            cleaned[j++] = tolower(input[i]);
        }
    }
    cleaned[j] = '\0';

    // Check if there's anything valid to check
    if (strlen(cleaned) == 0) {
        printf("Invalid input! No letters found to check for palindrome.\n");
        return 1;
    }

    // Check palindrome
    int start = 0;
    int end = strlen(cleaned) - 1;
    int isPalindrome = 1;

    while (start < end) {
        if (cleaned[start] != cleaned[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if (isPalindrome) {
        printf("The input is a palindrome.\n");
    } else {
        printf("The input is NOT a palindrome.\n");
    }

    return 0;
}
