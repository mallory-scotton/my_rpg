/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** load
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
string_t readf(cstring_t filepath, ulong_t *readed)
{
    FILE *f = fopen(filepath, "rb");
    char *string;
    long fsize;

    if (f == NULL)
        return (NULL);
    fseek(f, 0, SEEK_END);
    fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    string = malloc(fsize + 1);
    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;
    (*readed) = (ulong_t)fsize;
    return (string);
}

///////////////////////////////////////////////////////////////////////////////
static void load_prop_data(cstring_t buff, prop_t *prop, ulong_t *idx)
{
    prop->data[0] = ((int)buff[(*idx)]);
    prop->data[1] = ((int)buff[(*idx) + 1]);
    prop->data[2] = ((int)buff[(*idx) + 2]);
    prop->data[3] = ((int)buff[(*idx) + 3]);
    if (prop->data[0] == 1)
        prop->frame = prop->data[1];
    (*idx) += 4;
}

///////////////////////////////////////////////////////////////////////////////
static void load_prop(cstring_t buff, prop_t ***array, uint_t *count,
    ulong_t *idx)
{
    int catId = 0;
    int shtId = 0;
    prop_t *prop;

    catId = my_rbuffint(buff, 2, idx);
    shtId = my_rbuffint(buff, 2, idx);
    add_prop(Editor.zone->categories[catId]->sheets[shtId], array, count);
    prop = (*array)[(*count) - 1];
    prop->position.x = (buff[(*idx)]) ? -1.0f : 1.0f;
    (*idx)++;
    prop->position.x *= my_rbuffint(buff, 2, idx);
    prop->position.y = (buff[(*idx)]) ? -1.0f : 1.0f;
    (*idx)++;
    prop->position.y *= my_rbuffint(buff, 2, idx);
    prop->scale.x = (buff[(*idx)]) ? -1.0f : 1.0f;
    (*idx)++;
    prop->collision = (buff[(*idx)]) ? true : false;
    (*idx)++;
    load_prop_data(buff, prop, idx);
    prop_set_transform(prop);
}

///////////////////////////////////////////////////////////////////////////////
static void load_information(cstring_t buff, ulong_t *idx)
{
    ulong_t length = my_strlen(buff);

    if (length == 0)
        return;
    if (!load_zone(buff))
        return;
    for (uint_t i = 0; i < Assets.zoneCount; i++) {
        if (Assets.zones[i]->loaded == false)
            continue;
        Editor.zone = Assets.zones[i];
        Editor.zoneId = i;
    }
    (*idx) = (length + 1);
}

///////////////////////////////////////////////////////////////////////////////
static void load_layer(prop_t ***array, uint_t *count, cstring_t buff,
    ulong_t *idx)
{
    int howMany = my_rbuffint(buff, 3, idx);

    for (uint_t i = 0; i < (uint_t)howMany; i++)
        load_prop(buff, array, count, idx);
}

///////////////////////////////////////////////////////////////////////////////
static void load_bound(cstring_t buff, ulong_t *idx)
{
    int negative = 1;

    Editor.camera[0] = my_rbuffint(buff, 2, idx);
    Editor.camera[1] = my_rbuffint(buff, 2, idx);
    Editor.camera[2] = my_rbuffint(buff, 2, idx);
    Editor.camera[3] = my_rbuffint(buff, 2, idx);
    Editor.trigger[0] = my_rbuffint(buff, 2, idx);
    Editor.trigger[1] = my_rbuffint(buff, 2, idx);
    negative = (buff[(*idx)] == 1) ? -1 : 1;
    (*idx)++;
    Editor.trigger[2] = my_rbuffint(buff, 2, idx) * negative;
    negative = (buff[(*idx)] == 1) ? -1 : 1;
    (*idx)++;
    Editor.trigger[3] = my_rbuffint(buff, 2, idx) * negative;
}

///////////////////////////////////////////////////////////////////////////////
bool_t level_load(cstring_t filepath)
{
    ulong_t readed = 0;
    string_t path = my_strdcat(DIR_LEVEL, filepath, ".level");
    cstring_t buff = (cstring_t)readf(path, &readed);
    ulong_t idx = 0;

    FREE(path);
    if (buff == NULL)
        return (false);
    editor_clear();
    load_information(buff, &idx);
    load_layer(&(Editor.fProps), &(Editor.fCount), buff, &idx);
    load_layer(&(Editor.bProps), &(Editor.bCount), buff, &idx);
    load_bound(buff, &idx);
    return (true);
}
