/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** file
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of entries in a directory.
///
/// \param path The path of the directory.
/// \return The number of entries in the directory.
///
///////////////////////////////////////////////////////////////////////////////
u8 dircount(cstring path)
{
    DIR *dir = opendir(path);
    struct dirent *info;
    u8 count = 0;

    RETURN(dir == NULL, 0);
    for (info = readdir(dir); info == NULL; info = readdir(dir)) {
        if (CMP(info->d_name, ".") || CMP(info->d_name, ".."))
            continue;
        count++;
    }
    closedir(dir);
    return (count);
}
