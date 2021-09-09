#include "../inc/myStringMatch.h"

/*Brute-Force 暴力匹配 - BF算法*/
int BruteForce(char haystack[], char needle[]){

    int i, j;
    int flag;

    int n = strlen(haystack), m = strlen(needle);


    for(i = 0; i + m <= n; i++){

        flag = 1;

        for(j = 0; j < m; j++){
            if(haystack[i + j] != needle[j]){
                flag = 0;
                break;
            }

        }

        if(flag)
            return i;
    }


    return -1;

}

/*Rabin-Karp 算法 - RK算法*/
// 未调试好
int RabinKarp(char haystack[], char needle[], int q){
    int n = strlen(haystack), m = strlen(needle);

    int i, j;
    int hash_haystack = 0; // haystack的哈希值
    int hash_needle = 0; // needle的哈希值
    int h = 1;
    int d = 256;

    for(i = 0; i < m -1; i++){
        h = (h * d)%q;
    } 
    
    // 计算哈希值
    for(i = 0; i < m; i++){
        hash_needle = (d * hash_needle + needle[i])%q;
        hash_haystack = (d * hash_haystack + haystack[i])%q;
        
    }

    for(i = 0; i <= n-m; i++){

        if(hash_haystack == hash_needle){
            for(j = 0; j < m; j++){

                if(haystack[i+j] != needle[j])
                    break;
            }

            if(j == m)
                // printf("Pattern found at index %d \n", i);
                return i;
        }


        if(i < n-m){

            hash_haystack = (d * (hash_haystack - haystack[i]*h) + haystack[i + m])%q;
            
            if(hash_haystack < 0)
                hash_haystack = hash_haystack + q;

        }       
    }

    return -1;
}


int StringMatchDemo(){

    
    // char haystack[] = "hello";
    // char needle[] = "ll";

    char haystack[] = "GEEKS FOR GEEKS";
    char needle[] = "EEK";

    
    printf("%s\n", haystack);
    /*BF算法*/
    int bf = BruteForce(haystack, needle);
    printf("bf: %d\n", bf);

    /*RK算法*/
    int q = 101;
    bf = RabinKarp(haystack, needle, q);
    printf("bf: %d\n", bf);


    return 0;

}