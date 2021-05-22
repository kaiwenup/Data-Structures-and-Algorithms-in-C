#include "myhash.h"
#include "ComFun.h"





// 添加整型数到哈希表
void AddUser(struct string_struct* users, int user_id, char *name){
    struct string_struct *s ;
    HASH_FIND_INT(users, &user_id, s);
    if(s == NULL){
        s = (struct string_struct*)malloc(sizeof(*s));
        s->id = user_id;
        HASH_ADD_INT(users, id, s);

        
        
    }

    strcpy(s->name, name);
    


}

// 哈希表中寻找整型数
struct string_struct *FindUser(struct string_struct* users, int user_id){
      struct string_struct *s;
      HASH_FIND_INT(users, &user_id, s);
      return s;
}

void DeleteUser(struct string_struct* users, struct string_struct *user){
    HASH_DEL(users, user);
    free(user);
}

void DeleteAll(struct string_struct* users){
    struct string_struct *current_user, *tmp;
    HASH_ITER(hh, users, current_user, tmp){
        HASH_DEL(users, current_user);
        free(current_user);
    }
}

void PrintUsers(struct string_struct *users){
    struct string_struct *s;
    int num = 1;
    for(s = users; s != NULL; s = (struct string_struct*)s->hh.next){
        printf("%d:user id: %2d: name: %s\n",num , s->id, s->name);
        num++;
    }

}

int name_sort(struct string_struct *a, struct string_struct *b) {
    return strcmp(a->name,b->name);
}

int id_sort(struct string_struct *a, struct string_struct *b) {
    return (a->id - b->id);
}

void sort_by_name(struct string_struct* users) {
    HASH_SORT(users, name_sort);
}

void sort_by_id(struct string_struct* users) {
    HASH_SORT(users, id_sort);
}


void uthash_base_test(){

    struct string_struct *string_user, *string_s, *string_tmp, *s = NULL; 
    struct string_struct *string_users_kw = NULL;
    struct string_struct *string_users_char = (struct string_struct*)malloc(sizeof(*string_users_char));
    string_users_char = NULL;


    char in[3] = {'z', 'k', 'w'};
    int i;
    // 字符数组键的使用
    int init_id = 0;  // !!!非常重要，一定要先给string_users_char分配内存，不然当参数传入AddUser时会出现错误
    s = (struct string_struct*)malloc(sizeof(*s));
    s->id = init_id;
    HASH_ADD_INT(string_users_char, id, s);
    strcpy(s->name, in);
    for(i = 1; i < 3; i++){
        // int id = GenRandomNum(10);
        int id = i;
        AddUser(string_users_char, id, in); // 一定要将已经分配好内存的string_users_char传入，不要分配一个空的


    }
    int find_id = 2;
    // HASH_FIND_INT(string_users_char, &find_id, string_s);
    string_s = FindUser(string_users_char, find_id);
    printf("user:%s\n", string_s ? string_s->name : "unknown");

    PrintUsers(string_users_char);


    char *names[] = {"joe", "bob", "betty", NULL};
    for(i = 0; names[i]; ++i){
        string_s = (struct string_struct *)malloc(sizeof *string_s);
        strcpy(string_s->name, names[i]);
        string_s->id = i;
        // AddUser(string_users_kw, i, names[i]);
        HASH_ADD_STR(string_users_kw, name, string_s);
    }
   
    // HASH_FIND_STR(string_users_kw, &find_id, string_s);
    // printf("user:%s\n", string_s ? string_s->name : "unknown");
    PrintUsers(string_users_kw);
}


