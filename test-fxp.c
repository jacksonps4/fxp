#include<stdio.h>
#include<stdlib.h>
#include <fxp-fix.h>
#include <test-fxp.h>

void run_test(char* name, bool test_function(void))
{
    if (test_function() == 0) {
        printf("PASSED: %s\n", name);    
    } else {
        printf("FAILED: %s\n", name);
    }
}

bool test_print_fix_msgs()
{
    fix_message* msgs[1];

    fix_message* msg = new_fix_message();
    msgs[0] = msg;

    fix_field* field = new_fix_field(35, "V - test msg");
    add_fix_field_to_message(msg, field);
    
    fix_field* field2 = new_fix_field(100, "123");
    add_fix_field_to_message(msg, field2);

    print_fix_msgs(msgs, 1);

    return 0; 
}

