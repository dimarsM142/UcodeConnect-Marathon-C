#include "../inc/header.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    t_agent **agent_array = NULL;
    
    agent_array = (t_agent **)malloc(sizeof(t_agent *) * count + 1);
    if (name == NULL || power == NULL || strength == NULL)
        return NULL;
    for (int i = 0; i < count; i++)
        agent_array[i] = mx_create_agent(name[i], power[i], strength[i]);
    agent_array[count] = NULL;

    return agent_array;
}

