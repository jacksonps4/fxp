#include <fix-protocol.h>

char* lookup(int tag)
{
    for (int i = 0; i < TAG_COUNT; i++) {
        fix_tag t = tags[i];
        if (t.tag == tag) {
            return t.name;
        }
    }
    return 0;
}
