#ifndef MYHASH_H
#define MYHASH_H

#include "stdio.h"    
#include "string.h"
#include "ctype.h"      
#include "stdlib.h"  
#include <unistd.h> 

#include "math.h"  
#include "time.h"

#include "uthash.h"


typedef struct example_user_t {
    int id;
    int cookie;
    UT_hash_handle hh;
} example_user_t;

void myhash_demo();

#endif