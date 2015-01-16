#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fxp-fix.h>

int main(int argc, char* argv[])
{
    char buf[1024];

    fix_message* msg = new_fix_message();
    fix_message* msgs[1024];

    int c;
    int msg_count = 0;
    int tag = 0;
    for (int i = 0; (c = getchar()) != EOF; i++) {
        if (c == 1) {
            // finished reading field value
            char* field_value = malloc(i+1);
            strcpy(field_value, buf);

            fix_field* field = new_fix_field(tag, field_value);
            add_fix_field_to_message(msg, field);

            if (field->tag == 10) {
                if (msg_count < 1024) {
                    msgs[msg_count++] = msg;
                    msg = new_fix_message();
                } else {
                    print_fix_msgs(msgs, msg_count);
                    msg_count = 0;
        
                    msgs[msg_count++] = msg;
                    msg = new_fix_message();
                } 
            }

            i = clear_buffer(buf, i);
        } else if (c == '=') {
            // finished reading field name
            tag = atoi(buf);

            i = clear_buffer(buf, i);
        } else {
            // read text
            buf[i] = c;
        }
    }

    print_fix_msgs(msgs, msg_count);
    return 0;
}

