#include "../inc/header.h"

t_agent *mx_create_agent(char *name, int power, int strength) {
    t_agent *instance = NULL;

    if (name == NULL)
        return NULL;
    instance = (t_agent *)malloc(sizeof(t_agent));
    instance->name = mx_strdup(name);
    instance->power = power;
    instance->strength = strength;
    return instance;
}

