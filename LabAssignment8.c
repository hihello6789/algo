#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 50

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

// Create a new trie node
TrieNode* createNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    if (node) {
        node->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

// Insert a word into the trie
void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) continue; 
        
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
            if (!current->children[index]) {
                printf("Memory allocation failed!\n");
                return;
            }
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

// Search for a word in the trie
bool search(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) {
        int index = tolower(word[i]) - 'a';
        if (index < 0 || index >= ALPHABET_SIZE) return false;
        
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return (current != NULL && current->isEndOfWord);
}

// Free the trie memory
void freeTrie(TrieNode *root) {
    if (root == NULL) return;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != NULL) {
            freeTrie(root->children[i]);
        }
    }
    free(root);
}

int readWordsFromCSV(const char *filename, TrieNode *root) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 0;
    }

    char line[MAX_WORD_LENGTH];
    int wordCount = 0;
    
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        // Remove newline or carriage return
        line[strcspn(line, "\n\r")] = '\0';
        
        // Skip empty lines
        if (strlen(line) == 0) continue;
        
        // Insert word into trie
        insert(root, line);
        wordCount++;
    }

    fclose(file);
    return wordCount;
}

int main() {
    TrieNode *root = createNode();
    if (!root) {
        printf("Error: Could not create trie root\n");
        return 1;
    }

    // Specify the CSV file path
    const char *filename = "words.csv";
    
    // Read words from CSV and insert into trie
    printf("Reading words from %s...\n", filename);
    int numWords = readWordsFromCSV(filename, root);
    
    if (numWords == 0) {
        printf("No words loaded. Exiting.\n");
        freeTrie(root);
        return 1;
    }
    
    printf("Inserted %d words into the trie.\n", numWords);
    printf("Trie built successfully!\n\n");
    
    // User interaction for searching words
    char input[MAX_WORD_LENGTH];
    printf("****Trie Word Search****\n");
    printf("Enter a word to search (or 'quit' to exit):\n\n");
    
    while (1) {
        printf("> ");
        if (scanf("%49s", input) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            break;
        }
        
        // Clear input buffer to prevent issues with long inputs
        while (getchar() != '\n');
        
        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Program terminated\n");
            break;
        }
        
        if (search(root, input)) {
            printf("[FOUND] Word '%s' is in the list!\n\n", input);
        } else {
            printf("[NOT FOUND] Word '%s' is not in the list.\n\n", input);
        }
    }
    
    // Clean up
    freeTrie(root);
    return 0;
}