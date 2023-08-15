#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define TABLE_SIZE 100

unsigned int hash(const char *input);

struct HashTable {
  int occupied;
  char *arr[];
};

struct HashTable *createTable(int size);
void deleteTable(struct HashTable *table);
void insert(char *key, char *val, struct HashTable *table);
void delete(char *key, struct HashTable *table);
char *get(char *key, struct HashTable *table);

struct HashTable *createTable(int size) {
  struct HashTable *h = malloc(sizeof(struct HashTable) + size * sizeof(char *));
  if(h) {
    h->occupied = 0;
    for(int i = 0; i < size; i++) {
      h->arr[i] = NULL;
    }
  }
  return h;
}

char *get(char *key, struct HashTable *table) {
  if(table) {
    unsigned int index = hash(key);
    return table->arr[index];
  }
  return "";
}

void delete(char *key, struct HashTable *table) {
  if(table) {
    unsigned int index = hash(key);
    table->arr[index] = NULL;
    table->occupied -= 1;
  }
}

void insert(char *key, char *val, struct HashTable *table) {
  unsigned int index = hash(key);
  table->arr[index] = val;
  table->occupied += 1;
  return;
}

void deleteTable(struct HashTable *table) {
  if(table) {
    free(table);
  }
  return;
}

unsigned int hash(const char *input) {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256((unsigned char *)input, strlen(input), hash);

  unsigned int index = 0;
  for(int i = 0; i < sizeof(hash); i++) {
    index = (index << 8) | hash[i];
  }
  return index % TABLE_SIZE;
}

int main() {
  struct HashTable *table = createTable(TABLE_SIZE);
  insert("test", "one", table);
  insert("testing", "two", table);
  printf("This table has %d elements.\n", table->occupied);
  delete("testing", table);
  printf("Now this table has %d elements.\n", table->occupied);
  printf("El: %s", get("test", table));
  deleteTable(table);
  return 0;
}

