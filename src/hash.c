#include "hash.h"

unsigned int hash_function(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31u) ^ (unsigned char)(*key++);
    }
    return hash;
}
