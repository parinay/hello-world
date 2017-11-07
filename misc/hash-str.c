#include <stdio.h>

#define TABLE_SIZE 12

typedef struct _hash_table_t {
	char *string;
	struct  _hash_table *next;
} hash_table_t;

hash_table_t create_table();

int uniq_hash (char *str);
int hash_func(char *str, int table_size)
{
	int sum;

	if (str == NULL) return -1;

	for( ; *str; str++) {
		sum = sum + *str;
	}
	return (sum % table_size);
}

int uniq_hash (char *str)
{
	unsigned long hash = 5381;

	int sum;

	//while(sum = *str++)
	for(sum = *str; *str != '\0'; *str++)
		hash = sum + (hash << 5) - hash;

	return hash % 12;
}
int main()
{
	int key = hash_func("dog", 12);
	printf("The key for string \"parinay\" is %d\n", key);
	key = uniq_hash("god");
	printf("The key for string is %d\n",key);
	key = uniq_hash("dog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("hog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("kog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("gog");
	printf("The key for string is %d\n",key);
}
