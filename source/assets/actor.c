/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** actor
*/

#include "rpg.h"

void actor_load(cstring path)
{
    RETURN(path == NULL, (void)0);
}

void actors_load(void)
{
    warray content = dircontent(DATA_PATH);
    ulong len = my_walen(content);
    string tmp;

    RETURN(len == 0, (void)0);
    for (ulong i = 0; i < len; i++) {
        tmp = my_strdcat(DATA_PATH, "/", content[i]);
        actor_load(tmp);
        FREE(tmp);
    }
    my_watroy(content);
}
