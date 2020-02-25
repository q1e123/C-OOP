#include <stdio.h>
#include "Class.h"

int main() {
    Class *c;
    c = new_class();
    set_private_data(c,7);
    get_private_data(c);

    Derived *d;
    d = new_derived();

    c = derived_downcast(d);
    virtual_func(c);
    return 0;
}
