/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** window
*/

///////////////////////////////////////////////////////////////////////////////
// Header
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Win global variable
///
/// \param self         References to the render window
/// \param size         2D vector representing the size of the window
/// \param isFullscreen Boolean, true if the window is in fullscreen, false
///                     otherwise.
///
///////////////////////////////////////////////////////////////////////////////
global_window_t *Win;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the window icon.
///
/// This function initializes the window icon by loading an image from the
/// specified file path (WINDOW_ICON) and setting it as the window icon. If the
/// image loading fails, the function returns without setting the icon.
///
///////////////////////////////////////////////////////////////////////////////
static void window_init_icon(void)
{
    vec2u size;
    sfImage *icon = sfImage_createFromFile(WIN_ICON);

    RETURN(icon == NULL, (void)0);
    size = sfImage_getSize(icon);
    sfRenderWindow_setIcon(Win->self, size.x, size.y,
        sfImage_getPixelsPtr(icon));
    sfImage_destroy(icon);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the window.
///
/// This function creates the main SFML window with the specified dimensions,
/// title, style, and context settings. It also initializes the window icon
/// if a valid path is provided. The window is then configured with the desired
/// framerate limit, and its position is set to the center of the screen if
/// the WINDOW_CENTERED flag is true.
///
/// \return    true if the window is successfully initialized, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
status window_init(void)
{
    sfVideoMode screen = sfVideoMode_getDesktopMode();

    Win = malloc(sizeof(global_window_t));
    RETURN(Win == NULL, fail);
    Win->self = sfRenderWindow_create(WIN_MODE, WIN_TITLE, WIN_STYLE, NULL);
    Win->view = sfView_createFromRect((rectf){0, 0, VIEW_WIDTH, VIEW_HEIGHT});
    RETURN(Win->self == NULL, fail);
    if (Win->view == NULL) {
        sfRenderWindow_destroy(Win->self);
        FREE(Win);
        return (fail);
    }
    sfRenderWindow_setView(Win->self, Win->view);
    sfView_setCenter(Win->view, VEC2(VIEW_WIDTH / 2.0f, VIEW_HEIGHT / 2.0f));
    DOIF(WIN_ICON != NULL, window_init_icon);
    sfRenderWindow_setFramerateLimit(Win->self, WIN_FPS);
    RETURN(WIN_CENTERED == false, success);
    sfRenderWindow_setPosition(Win->self, VEC2I(MID(screen.width, WIN_WIDTH),
        MID(screen.height, WIN_HEIGHT)));
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the main window dimensions.
///
/// This function retrieves the current size of the main window using
/// sfRenderWindow_getSize, and ensures that it falls within the specified
/// minimum and maximum dimensions. If the size is outside this range,
/// it is clamped to the valid range using the CLAMP macro. The updated size
/// is then applied to the window using sfRenderWindow_setSize.
///
/// \param size     The resized event value
///
///////////////////////////////////////////////////////////////////////////////
void window_update(sfSizeEvent size)
{
    float factor = (float)((float)VIEW_WIDTH / (float)size.width);

    sfView_setSize(Win->view, VEC2(VIEW_WIDTH, size.height * factor));
    sfRenderWindow_setView(Win->self, Win->view);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the main window.
///
/// This function checks if the main window exists (not NULL) and destroys it
/// using sfRenderWindow_destroy. After calling this function, the window
/// pointer in the Paint structure should be set to NULL to avoid potential
/// issues with accessing a destroyed window.
///
///////////////////////////////////////////////////////////////////////////////
void window_destroy(void)
{
    RETURN(Win == NULL, (void)0);
    DOIFX(Win->self != NULL, sfRenderWindow_destroy, Win->self);
    DOIFX(Win->view != NULL, sfView_destroy, Win->view);
    FREE(Win);
}
