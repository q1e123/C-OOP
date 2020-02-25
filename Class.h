#ifndef C_OOP_CLASS_H
#define C_OOP_CLASS_H

typedef struct Private Private;

struct Class;

typedef struct Class_vtable{
    void (*virtual_func)();
}Class_vtable;

typedef struct Class{
    int public_data;
    Class_vtable *vtable;

    Private *pv;
}Class;

int get_private_data(Class *self);
void set_private_data(Class *self, int data);
Class *new_class();
void virtual_func(Class *class);

typedef struct Derived{
    Class *base;
    int new_member;
}Derived;

Derived *new_derived();
void deriv_func();
Class *derived_downcast(Derived*);

#endif //C_OOP_CLASS_H
