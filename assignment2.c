#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment2.h"

/* ===================== Problem 1 ===================== */

int add_user_password(const char* file_name,
                      const char* username,
                      const char* password)
{
    size_t username_len = strlen(username);
    size_t password_len = strlen(password);
    
    // First, check if user already exists
    FILE* file = fopen(file_name, "rb");
    if (file != NULL) {
        size_t ulen, plen;
        while (1) {
            size_t read_count = fread(&ulen, sizeof(size_t), 1, file);
            if (read_count != 1) break;
            
            read_count = fread(&plen, sizeof(size_t), 1, file);
            if (read_count != 1) break;
            
            char* u = malloc(ulen);
            if (!u) {
                fclose(file);
                return -1;
            }
            
            read_count = fread(u, 1, ulen, file);
            if (read_count != ulen) {
                free(u);
                fclose(file);
                return -1;
            }
            
            // Compare username
            if (ulen == username_len && memcmp(u, username, ulen) == 0) {
                free(u);
                fclose(file);
                return 0; // user exists
            }
            
            free(u);
            
            // Skip the password
            if (fseek(file, plen, SEEK_CUR) != 0) {
                fclose(file);
                return -1;
            }
        }
        fclose(file);
    }
    
    // User doesn't exist, add it
    file = fopen(file_name, "ab");
    if (!file) return -1;
    
    fwrite(&username_len, sizeof(size_t), 1, file);
    fwrite(&password_len, sizeof(size_t), 1, file);
    fwrite(username, 1, username_len, file);
    fwrite(password, 1, password_len, file);
    
    fclose(file);
    return 1;
}

int check_user_password(const char* file_name,
                        const char* username,
                        const char* password)
{
    FILE* file = fopen(file_name, "rb");
    if (!file) return -1;
    
    size_t username_len = strlen(username);
    size_t password_len = strlen(password);
    size_t ulen, plen;
    
    while (1) {
        size_t read_count = fread(&ulen, sizeof(size_t), 1, file);
        if (read_count != 1) break;
        
        read_count = fread(&plen, sizeof(size_t), 1, file);
        if (read_count != 1) break;
        
        char* u = malloc(ulen);
        char* p = malloc(plen);
        if (!u || !p) {
            free(u);
            free(p);
            fclose(file);
            return -1;
        }
        
        read_count = fread(u, 1, ulen, file);
        if (read_count != ulen) {
            free(u);
            free(p);
            fclose(file);
            return -1;
        }
        
        read_count = fread(p, 1, plen, file);
        if (read_count != plen) {
            free(u);
            free(p);
            fclose(file);
            return -1;
        }
        
        // Check username
        if (ulen == username_len && memcmp(u, username, ulen) == 0) {
            // Username matches, check password
            if (plen == password_len && memcmp(p, password, plen) == 0) {
                free(u);
                free(p);
                fclose(file);
                return 1;
            } else {
                free(u);
                free(p);
                fclose(file);
                return -3;
            }
        }
        
        free(u);
        free(p);
    }
    
    fclose(file);
    return -2;
}

/* ===================== Problem 2 ===================== */

int fib3_p(unsigned int n, unsigned int p)
{
    if (n == 0) return 0;
    if (n == 1) return 1 % p;
    if (n == 2) return 2 % p;

    unsigned int a = 0, b = 1, c = 2;
    for (unsigned int i = 3; i <= n; i++) {
        unsigned int next = (a + b + c) % p;
        a = b;
        b = c;
        c = next;
    }

    return c;
}

/* ================= Problem 3 ================= */

char* evolve(const char* state) {
    int n = strlen(state);
    char* next = malloc(n + 1);
    if (!next) return NULL;
    for (int i = 0; i < n; i++) next[i] = '-';
    next[n] = '\0';

    int positions[n];
    int count = 0;

    for (int i = 0; i < n; i++)
        if (state[i] == '*')
            positions[count++] = i;

    if (count == 0 || count == 1) { 
        strcpy(next, state);
        return next;
    }

    
    int temp[n];
    for (int i = 0; i < n; i++) temp[i] = 0;

    
    if (positions[0] + 1 < n) temp[positions[0] + 1]++;

    
    if (positions[count - 1] - 1 >= 0) temp[positions[count - 1] - 1]++;

    
    for (int i = 1; i < count - 1; i++) {
        int left_dist = positions[i] - positions[i - 1];
        int right_dist = positions[i + 1] - positions[i];

        if (left_dist < right_dist)
            temp[positions[i] - 1]++;
        else if (right_dist < left_dist)
            temp[positions[i] + 1]++;
       
    }

   
    for (int i = 0; i < n; i++)
        if (temp[i] == 1)
            next[i] = '*';

    return next;
}

char* last_state(const char* state) {
    char* current = malloc(strlen(state) + 1);
    if (!current) return NULL;
    strcpy(current, state);

    while (1) {
        char* next = evolve(current);
        if (!next) { free(current); return NULL; }
        if (strcmp(next, current) == 0) { 
            free(current);
            return next;
        }
        free(current);
        current = next;
    }
}