#include "myhash.h"
#include "ComFun.h"





// 添加整型数到哈希表
void AddUser(hash_struct *users, int user_id, char *name){
    struct hash_struct *s ;
    HASH_FIND_INT(users, &user_id, s);
    if(s == NULL){
        s = (struct hash_struct*)malloc(sizeof(*s));
        s->id = user_id;
        HASH_ADD_INT(users, id, s);

        
        
    }

    strcpy(s->name, name);
    
}
// 哈希表中寻找整型数

void DeleteUser(hash_struct* users, hash_struct *user){
    HASH_DEL(users, user);
    free(user);
}

void DeleteAll(hash_struct* users){
    hash_struct *current_user, *tmp;
    HASH_ITER(hh, users, current_user, tmp){
        HASH_DEL(users, current_user);
        free(current_user);
    }
}

void PrintUsers(hash_struct *users){
    hash_struct *s;
    int num = 1;
    unsigned int num_users = 0;
    num_users = HASH_COUNT(users);
    printf("there are %u users\n", num_users);
    for(s = users; s != NULL; s = (hash_struct*)s->hh.next){
        printf("%2d:user id: %2d: name: %s\n",num , s->id, s->name);
        num++;
    }

}

int name_sort(hash_struct *a, hash_struct *b) {
    return strcmp(a->name,b->name);
}

int id_sort(hash_struct *a, hash_struct *b) {
    return (a->id - b->id);
}

void sort_by_name(hash_struct* users) {
    HASH_SORT(users, name_sort);
}

void sort_by_id(hash_struct* users) {
    HASH_SORT(users, id_sort);
}

void hash_base_demo(){

    srand((unsigned)time(NULL));
    int i, nums = 15;
    char in[5] = {'1', '2', '3','4','5'};
    // int  in[5] = {1,2,3,4,5};

    hash_struct *s, *tmp;
    hash_struct *althusers = NULL;
    hash_struct *users = NULL;

    // 加入nums个值到哈希表
    for(i = 0; i < nums; ++i){
        HASH_FIND_INT(users, &i, s);  // 哈希表的所有key值必须独一无二，所以在加入之前需要检查key是否重复
        if(s == NULL)
        {
            s = (hash_struct *)malloc(sizeof *s);
            // s->id = GenRandomNum(100);
            if(s == NULL)
                exit(-1);
            s->id = i;
            HASH_ADD_INT(users, id, s);
            strcpy(s->name, in);
            HASH_ADD(alth, althusers, name, sizeof(char), s);
        }
        
    }

    PrintUsers(users);  // 遍历哈希表

    // /* delete each even ID 删除哈希表中的所有元素*/   
    // for(i=0; i<nums; ++i) {
    //     HASH_FIND_INT(users,&i,tmp);
    //     if (tmp != NULL) {
    //         HASH_DEL(users,tmp);
    //         free(tmp);
    //     } else {
    //         printf("user id %d not found\n", i);
    //     }
    // }
    
    PrintUsers(users);
    printf("\n");
    PrintUsers(althusers);
    



    /**将字符串加入哈希表**/
    // int find_id = 2;
    // s = FindUser(users, find_id);
    // printf("user:%s\n", s ? s->name : "unknown");

    // hash_struct *string_user, *string_s;
    // hash_struct *string_users = NULL;

    // char *names[] = {"joe", "bob", "betty", NULL};
    // for(i = 0; names[i]; ++i){
    //     string_s = (struct hash_struct *)malloc(sizeof *string_s);
    //     strcpy(string_s->name, names[i]);
    //     string_s->id = i;
    //     HASH_ADD_STR(string_users, name, string_s);
    // }


    // PrintUsers(string_users);
    // int find_id = 1;
    // HASH_FIND_STR(string_users, "betty", string_s);
    
    // if (string_s) printf("betty's id is %d\n", string_s->id);

    // /* free the hash table contents */
    // HASH_ITER(hh, string_users, string_s, tmp){
    //     HASH_DEL(string_users, string_s);
    //     free(string_s);
    // }
}




