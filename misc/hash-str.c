#include <stdio.h>

#define TABLE_SIZE 12

typedef struct _hash_table_t {
	char *string;
	struct  _hash_table *next;
} hash_table_t;

hash_table_t create_table();

int uniq_hash (char *str);
int hash_func(char *str)
{
	int sum;

	if (str == NULL) return -1;

	for( ; *str; str++) {
		sum = sum + *str;
	}
	return (sum % TABLE_SIZE);
}

int uniq_hash (char *str)
{
	unsigned long hash = 123456;

	int sum;

	//while(sum = *str++)
	for(sum = *str; *str != '\0'; *str++)
		hash = sum + (hash << 6) - hash;

	return hash % TABLE_SIZE;
}
int main()
{
	int key = hash_func("dog");
	printf("Using hash_func()\n");
	printf("The key for string is %d\n", key);
	//key = uniq_hash("god");
	key = hash_func("god");
	printf("The key for string is %d\n",key);
	key = hash_func("hog");
	printf("The key for string is %d\n",key);
	key = hash_func("kog");
	printf("The key for string is %d\n",key);
	key = hash_func("gog");
	printf("The key for string is %d\n",key);

	printf("Using unique_has()\n");
	key = uniq_hash("dog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("god");
	printf("The key for string is %d\n",key);
	key = uniq_hash("hog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("kog");
	printf("The key for string is %d\n",key);
	key = uniq_hash("gog");
	printf("The key for string is %d\n",key);
}
