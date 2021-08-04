#ifndef MYHASH_H
#define MYHASH_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#include "../inc/uthash/uthash.h"
#include "../inc/ComFun.h"

// typedef struct int_struct {
//     int id;
//     int cookie;
//     UT_hash_handle hh;
// } int_struct;

// typedef struct string_struct {
//     int id;                    /* key */
//     char name[10];
//     UT_hash_handle hh;         /* makes this structure hashable */
// }string_struct, *string_struct_ptr;

typedef struct hash_struct {
    int id;                    /* key */
    char name[10];
    UT_hash_handle hh;         /* makes this structure hashable */
    UT_hash_handle alth;
}hash_struct, *hash_struct_ptr;

void AddUser(hash_struct *users, int user_id, char *name);
// hash_struct *FindUser(hash_struct* users, int user_id);
void DeleteUser(hash_struct* users, hash_struct *user);
void DeleteAll(hash_struct* users);
void PrintUsers(hash_struct* users);

int name_sort(hash_struct *a, hash_struct *b);
int id_sort(hash_struct *a, hash_struct *b);
void sort_by_name(hash_struct* users);
void sort_by_id(hash_struct* users);

void hash_base_demo();

#endif