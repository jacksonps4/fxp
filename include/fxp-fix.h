typedef struct 
{
    int tag;
    char* value;
} fix_field;

typedef struct 
{
    int field_count;
    fix_field** fields; 
} fix_message;

int clear_buffer(char*, int);
fix_field* new_fix_field(int, char*);
fix_message* new_fix_message(void);
void add_fix_field_to_message(fix_message*, fix_field*);
void print_fix_msgs(fix_message*[], int);

