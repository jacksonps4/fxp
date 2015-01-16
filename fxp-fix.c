#include<stdlib.h>
#include<stdio.h>
#include<fxp-fix.h>
#include<fix-protocol.h>

int clear_buffer(char* buf, int sz) 
{
    for (int i = 0; i < sz; i++) {
        buf[i] = 0;
    }   
    return -1; 
}

fix_field* new_fix_field(int tag, char* value)
{
    fix_field *field = malloc(sizeof(fix_field));
    field->tag = tag;
    field->value = value;
    return field;
}

fix_message* new_fix_message()
{
    fix_message* msg = malloc(sizeof(msg));
    msg->field_count = 0;
    msg->fields = NULL;

    return msg;
}

void add_fix_field_to_message(fix_message* msg, fix_field* field) 
{
    // TODO: deal with fields > 1024
    if (msg->fields == NULL)
    {
        msg->fields = malloc(1024 * sizeof(fix_field));
        msg->fields[0] = field;
    }
    else
    {
        msg->fields[msg->field_count] = field;
    }
    msg->field_count++;
}

void print_fix_msgs(fix_message* msgs[], int msg_count) 
{
    for (int m = 0; m < msg_count; m++) {
        fix_message *msg = msgs[m];
        printf("FIX message\n");
        printf("------------\n");
        for (int i = 0; i < msg->field_count; i++) {
            fix_field* field = msg->fields[i];
            printf("  [%5d] : %30s : %s\n", field->tag, lookup(field->tag), field->value);
        }   
        printf("------------\n\n");
    }   
}

