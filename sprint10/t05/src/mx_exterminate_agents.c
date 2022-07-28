#include "../inc/header.h"

void mx_exterminate_agents(t_agent ***agents) {
     t_agent **buff = *agents;

    for (int i = 0; buff[i]; i++) {
        mx_printchar('!');
        mx_printchar('\n');
        free(buff[i]->name);
        free(buff[i]);
    }
    //free(buff);
    mx_printchar('\n');
    free(*agents);
    // buff = NULL;
    *agents = NULL;
}
