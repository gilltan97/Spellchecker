#include <stdio.h>
#include <stdbool.h>

 /**
  * Node of a radix tree
  **/
typedef struct node{
    struct node* children[27];
    bool is_word;
}node;

/**
 Return an index as int between 0 - 27 for 
 each char given to it as an argument
*/
int charIndex(int char_){
    // if char_ is an apostrophe
    if (char_ == 39){
        return 26;
    }
    // if char_ is upper case alphabet
    else if (isalpha(char_) && isupper(char_)){
        return char_ - 65;
    }
    // for lowercase alphabets
    return char_ - 97; 
}

/**
 * Recursively goes to each node of the trie and
 * frees the allocated memory for that node.
*/
bool free_node(node* trie_node_)
{
    if (trie_node_ == NULL)
    {
        return true;
    }
    
    // Free the allocated memory for each node 
    else
    {
        for (int i = 0; i < 26; i++)
        {   // Treverse through all the nodes
            free_node(trie_node_ -> children[i]);
        }
        // free the memory of root node
        free(trie_node_);
        return true;
    }
}