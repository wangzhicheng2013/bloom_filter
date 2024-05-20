#pragma once
#include <string.h>
struct bkdr_hash {
    size_t operator() (const char* key) {
        size_t hash_val = 0;
        int len = strlen(key); 
        for (int i = 0;i < len;i++) {
            hash_val *= 31;
            hash_val += key[i];
        }
        return hash_val;
    }
};
struct ap_hash {
    size_t operator() (const char* key) {
        size_t hash_val = 0;
        int len = strlen(key); 
        for (int i = 0;i < len;i++) {
            if (0 == (i & 1)) {
                hash_val ^= ((hash_val << 7) ^ key[i] ^ (hash_val >> 3));
            }
            else {
                hash_val ^= (~((hash_val << 11) ^ key[i] ^ (hash_val >> 5)));
            }
        }
        return hash_val;
    }
};
struct djb_hash {
    size_t operator() (const char* key) {
        size_t hash_val = 5381;
        int len = strlen(key); 
        for (int i = 0;i < len;i++) {
            hash_val += (hash_val << 5) + key[i];
        }
        return hash_val;
    }
};