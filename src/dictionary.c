/**
 * File name: dictionary.c
 * Author: Tanveer Gill 
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "helpers.h"
#include "dictionary.h"

// Intialize a trie node
node* trie_node;

// Count of loaded words
unsigned int word_count = 0;

// Prototypes
bool free_node(node* trie_node_);
int charIndex(int char_);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* tmp_node = trie_node;
    
    for (int i = 0; i < strlen(word); i++)
    {
        // index value of the character in the trie node
        unsigned int index_val = charIndex(word[i]);
        
        // check if some children exist at index_val in the trie_node
        if (tmp_node -> children[index_val] == NULL)
        {
            return false;
        }
        tmp_node = tmp_node -> children[index_val];
    }
    // return true iff the word is in the trie
    if (tmp_node -> is_word == true)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
 // BUGGY
bool load(const char* dictionary)
{
    // Open the dictionary and check if it opens fine
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open %s", dictionary);
        fclose(dict);
        return false;
    }
    trie_node = malloc(sizeof(node));
      
    // Assuming that dictionary is open, Iterate till the end of dictionary 
    for (int ch = fgetc(dict); !feof(dict); ch = fgetc(dict))
    {
        // if theres an error while reding return false
        if (ferror(dict))
        {
            unload();
            printf("Could not load %s", dictionary);
            return false;
        }
        
        // If the ch is not an alphabet or apostrophe, go to the next word
        if (!isalpha(ch) && ch != '\'')
        {
            while ((ch = fgetc(dict)) != '\n');
        }
        else 
        {
            // Resets tmp_trie to root of the trie
            node* tmp_trie = trie_node;
            while (ch != '\n')
            {
                // index val for the character
                unsigned int index_val = charIndex(ch);
                
                // If noting at index index_val in the node the insert node
                if ((tmp_trie -> children[index_val]) == NULL)
                {
                    node* new_node = malloc(sizeof(node));
                    tmp_trie -> children[index_val] = new_node;
                    tmp_trie = tmp_trie -> children[index_val];
                }
                    
                else
                {
                    tmp_trie = tmp_trie -> children[index_val];
                }
                
                // Go to the next character in the word
                ch = fgetc(dict);
            }
            // Put true for the bool value once the word is placed in the trie
            tmp_trie -> is_word = true;
            
            // Add one to the total number of words loaded
            word_count++;
        }
    }
    fclose(dict);
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return the number of words loded in the trie
    return word_count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return free_node(trie_node);
}

