#ifndef AGENT_H
#define AGENT_H

#include <stdlib.h>
#include "agent.h"

typedef struct s_agent t_agent;

t_agent *mx_create_agent(char *, int, int);

char *mx_strnew(const int);
char *mx_strcpy(char*, const char*);
int mx_strlen(const char*);
char *mx_strdup(const char*);

#endif
