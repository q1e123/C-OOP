//
// Created by q1e123 on 27.02.2020.
//

#include "Template.h"
#include <stdlib.h>

Template *new_template(){
    Template *tmp;
    tmp = (Template*)(malloc(sizeof(Template)));
    return tmp;
}