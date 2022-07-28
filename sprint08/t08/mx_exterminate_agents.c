#include "only_smiths.h"

void mx_exterminate_agents(t_agent ***agents) {
    int i = 0;
    t_agent **temp = *agents;

    while (temp[i]) {
        free(temp[i]->name);
        free(temp[i]);
        i++;
    }
    free(temp);
    agents = (t_agent ***)0;
    return;
}
