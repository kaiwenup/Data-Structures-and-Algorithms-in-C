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


// typedef struct int_struct {
//     int id;
//     int cookie;
//     UT_hash_handle hh;
// } int_struct;

typedef struct string_struct {
    int id;                    /* key */
    char name[10];
    UT_hash_handle hh;         /* makes this structure hashable */
}string_struct, *string_struct_ptr;

void AddUser(struct string_struct* users, int user_id, char *name);
struct string_struct *FindUser(struct string_struct* users, int user_id);
void DeleteUser(struct string_struct* users, struct string_struct *user);
void DeleteAll(struct string_struct* users);
void PrintUsers(struct string_struct* users);

int name_sort(struct string_struct *a, struct string_struct *b);
int id_sort(struct string_struct *a, struct string_struct *b);
void sort_by_name(struct string_struct* users);
void sort_by_id(struct string_struct* users);


void uthash_base_test();

#endif