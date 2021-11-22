#include <stdio.h>

struct Foo {
    int bar;
    int baz;

    int bork(void) {
        return 3;
    };

    typedef enum {
        a=4,
        b=5
    } zoom;
} foo;

int main(void) {
    struct Foo z;

    z.bar = 1;
    z.baz = 2;

    printf("%d %d %d %d\n", z.bar, z.baz, z.bork(), Foo::a);
}

