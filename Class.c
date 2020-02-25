#include "Class.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  Private{
    int private_data;
}Private ;

int get_private_data(Class *self){
    printf("Private data: %d\n", self->pv->private_data);
}
void set_private_data(Class *self, int data){
    self->pv->private_data = data;
}

void virtual_func(Class *class){
    class->vtable->virtual_func();
}

Class *new_class(){
    Class *tmp;
    tmp = (Class*)(malloc(sizeof(Class)));

    tmp->pv = (Private*)(malloc(sizeof(Private)));

    tmp->vtable = (Class_vtable*)(malloc(sizeof(Class_vtable)));

    return tmp;
}

void deriv_func(){
    printf("Derived\n");
}

Derived *new_derived(){
    Derived *tmp;
    tmp = (Derived*)(malloc(sizeof(Derived)));

    tmp->base = new_class();
    tmp->base->pv = (Private*)(malloc(sizeof(Private)));


    Class_vtable *derived_vtable = (Class_vtable*)malloc(sizeof(Class_vtable));
    derived_vtable->virtual_func = &deriv_func;

    tmp->base->vtable = derived_vtable;

    return tmp;
}

Class *derived_downcast(Derived *derived){
    return derived->base;
}