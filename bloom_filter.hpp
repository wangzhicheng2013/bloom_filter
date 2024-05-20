#pragma once
#include <bitset>
#include <functional>
#include "hash_func.hpp"
template <size_t LEN = 1000003, 
          class hash_fun_type1 = bkdr_hash,
          class hash_fun_type2 = ap_hash,
          class hash_fun_type3 = djb_hash>
class bloom_filter {
private:
    std::bitset<LEN>bs_;
    std::hash<const char*>hash_func_;
public:
    void set(const char* key) {
        size_t hash_val = hash_fun_type1()(key) % LEN;
        bs_.set(hash_val);

        hash_val = hash_fun_type2()(key) % LEN;
        bs_.set(hash_val);

        hash_val = hash_fun_type3()(key) % LEN;
        bs_.set(hash_val);

        hash_val = hash_func_(key) % LEN;
        bs_.set(hash_val);
    }
    bool test(const char* key) {
        size_t hash_val = hash_fun_type1()(key) % LEN;
        if (false == bs_.test(hash_val)) {
            return false;
        }
        hash_val = hash_fun_type2()(key) % LEN;
        if (false == bs_.test(hash_val)) {
            return false;
        }
        hash_val = hash_fun_type3()(key) % LEN;
        if (false == bs_.test(hash_val)) {
            return false;
        }
        hash_val = hash_func_(key) % LEN;
        if (false == bs_.test(hash_val)) {
            return false;
        }
        return true;
    }
};