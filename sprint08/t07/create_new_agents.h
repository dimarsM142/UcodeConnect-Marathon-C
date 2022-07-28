#ifndef CREATE_NEW_AGENTS_H
#define CREATE_NEW_AGENTS_H

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

t_agent *mx_create_agent(char *name, int power, int strength);

t_agent **mx_create_new_agents(char**name, int*power, int *strength, int count);

char *mx_strcpy(char *, const char *);

char *mx_strnew(const int);

int mx_strlen(const char *);

char *mx_strdup(const char *);

#endif
