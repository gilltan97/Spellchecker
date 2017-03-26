# Spellchecker
Deterministic spellchecker that flags the misspelled words in a text file by checking the validity of the words from a dictionary passed in as second argument to the program.  

## Usage
```bash 
# usage format
speller [dictionary] text

# usage example
speller dictionaries/large texts/witch.txt
```

## Output Format
```
==MISSPELLED WORDS==
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
BEDEVERE
B
BEDEVERE
BEDEVERE
BEDEVERE
Aah
BEDEVERE
BEDEVERE
Uhhh
Oooh
BEDEVERE
BEDEVERE

==SUMMARY==
WORDS MISSPELLED:     23
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        372
TIME IN load:         0.10
TIME IN check:        0.00
TIME IN size:         0.00
TIME IN unload:       0.07
TIME IN TOTAL:        0.18
```
