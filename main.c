#include <stdio.h>
#include "Class.h"
#include "Template.h"
int main() {
    Class *c;
    c = new_class();
    set_private_data(c,7);
    get_private_data(c);

    Derived *d;
    d = new_derived();

    c = derived_downcast(d);
    virtual_func(c);

    Template *t;
    t = new_template();
    t->data = "asd";
    printf("data: %s",t->data);
    return 0;
}
