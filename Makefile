##
## EPITECH PROJECT, 2024
## csfml-engine
## File description:
## Makefile
##

.SILENT:

#-----------------------------------------------------------------------------#
#? Compiler Configuration

CC			=	gcc
FLAG		=	-g3															\
				-Wall														\
				-Wextra
FLAG		+=	-Iinclude
FLAG		+=	-lcsfml-system												\
				-lcsfml-window												\
				-lcsfml-graphics											\
				-lcsfml-network												\
				-lcsfml-audio												\
				-lm

#! WINDOWS ONLY
#FLAG		+=	-LC:\MinGW\lib

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#? Engine Sources

E_D_ROOT	=	./moon/
E_D_MATHS	=	$(E_D_ROOT)maths/
E_D_TIME	=	$(E_D_ROOT)time/
E_D_WINDOW	=	$(E_D_ROOT)window/
E_D_ASSETS	=	$(E_D_ROOT)assets/
E_D_OBJECTS	=	$(E_D_ROOT)objects/

E_C_ROOT	=	$(E_D_ROOT)engine.c
E_C_MATHS	=	$(E_D_MATHS)clamp.c											\
				$(E_D_MATHS)distance.c										\
				$(E_D_MATHS)intersect.c										\
				$(E_D_MATHS)lerp.c											\
				$(E_D_MATHS)max.c											\
				$(E_D_MATHS)min.c											\
				$(E_D_MATHS)vectors/add.c									\
				$(E_D_MATHS)vectors/angle.c									\
				$(E_D_MATHS)vectors/distance.c								\
				$(E_D_MATHS)vectors/divide.c								\
				$(E_D_MATHS)vectors/dot.c									\
				$(E_D_MATHS)vectors/endpoint.c								\
				$(E_D_MATHS)vectors/equal.c									\
				$(E_D_MATHS)vectors/lerp.c									\
				$(E_D_MATHS)vectors/multiply.c								\
				$(E_D_MATHS)vectors/normalize.c								\
				$(E_D_MATHS)vectors/subtract.c								\
				$(E_D_MATHS)vectors/movetowards.c
E_C_WINDOW	=	$(E_D_WINDOW)create.c										\
				$(E_D_WINDOW)destroy.c										\
				$(E_D_WINDOW)time.c
E_C_ASSETS	=	$(E_D_ASSETS)assets.c										\
				$(E_D_ASSETS)categories.c									\
				$(E_D_ASSETS)creatures.c									\
				$(E_D_ASSETS)images.c										\
				$(E_D_ASSETS)musics.c										\
				$(E_D_ASSETS)sort.c											\
				$(E_D_ASSETS)vfx.c											\
				$(E_D_ASSETS)sfx.c											\
				$(E_D_ASSETS)zones.c										\
				$(E_D_ASSETS)weapons.c										\
				$(E_D_ASSETS)bullets.c										\
				$(E_D_ASSETS)ui.c											\
				$(E_D_ASSETS)axolotl.c
E_C_OBJECTS	=	$(E_D_OBJECTS)pool.c										\
				$(E_D_OBJECTS)actors/animate.c								\
				$(E_D_OBJECTS)sfx.c											\
				$(E_D_OBJECTS)actors/create.c								\
				$(E_D_OBJECTS)actors/set.c									\
				$(E_D_OBJECTS)actors/transform.c							\
				$(E_D_OBJECTS)actors/collisions.c							\
				$(E_D_OBJECTS)props/create.c								\
				$(E_D_OBJECTS)props/draw.c									\
				$(E_D_OBJECTS)props/transform.c								\
				$(E_D_OBJECTS)effects/draw.c								\
				$(E_D_OBJECTS)effects/create.c

E_SOURCES	=	$(E_C_ROOT)													\
				$(E_C_MATHS)												\
				$(E_C_WINDOW)												\
				$(E_C_ASSETS)												\
				$(E_C_OBJECTS)

E_OBJECTS	=	$(E_SOURCES:.c=.o)

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#? Libmy Compilation

L_D_ROOT	=	./libmy/
L_D_CHAR	=	$(L_D_ROOT)char/
L_D_MEMORY	=	$(L_D_ROOT)memory/
L_D_NUMBER	=	$(L_D_ROOT)number/
L_D_PUTS	=	$(L_D_ROOT)puts/
L_D_STRINGS	=	$(L_D_ROOT)strings/
L_D_SYSTEM	=	$(L_D_ROOT)system/
L_D_BUFFER	=	$(L_D_ROOT)buffer/

L_C_CHAR	=	$(L_D_CHAR)countchar.c										\
				$(L_D_CHAR)isalnum.c										\
				$(L_D_CHAR)isalpha.c										\
				$(L_D_CHAR)iscntrl.c										\
				$(L_D_CHAR)isdigit.c										\
				$(L_D_CHAR)isgraph.c										\
				$(L_D_CHAR)islower.c										\
				$(L_D_CHAR)isprint.c										\
				$(L_D_CHAR)ispunct.c										\
				$(L_D_CHAR)isspace.c										\
				$(L_D_CHAR)isupper.c										\
				$(L_D_CHAR)isxdigit.c										\
				$(L_D_CHAR)tolower.c										\
				$(L_D_CHAR)toupper.c
L_C_MEMORY	=	$(L_D_MEMORY)free.c											\
				$(L_D_MEMORY)memcpy.c										\
				$(L_D_MEMORY)memset.c										\
				$(L_D_MEMORY)orealloc.c										\
				$(L_D_MEMORY)realloc.c
L_C_NUMBER	=	$(L_D_NUMBER)atob.c											\
				$(L_D_NUMBER)atof.c											\
				$(L_D_NUMBER)atoi.c											\
				$(L_D_NUMBER)isbool.c										\
				$(L_D_NUMBER)iscoord.c										\
				$(L_D_NUMBER)isfloat.c										\
				$(L_D_NUMBER)isint.c
L_C_PUTS	=	$(L_D_PUTS)error.c											\
				$(L_D_PUTS)fputs.c											\
				$(L_D_PUTS)putchar.c										\
				$(L_D_PUTS)puterr.c											\
				$(L_D_PUTS)putnbr.c											\
				$(L_D_PUTS)putstr.c											\
				$(L_D_PUTS)putwa.c
L_C_STRINGS	=	$(L_D_STRINGS)stowa.c										\
				$(L_D_STRINGS)strchr.c										\
				$(L_D_STRINGS)strcmp.c										\
				$(L_D_STRINGS)strdcat.c										\
				$(L_D_STRINGS)strdup.c										\
				$(L_D_STRINGS)stris.c										\
				$(L_D_STRINGS)strlen.c										\
				$(L_D_STRINGS)strncat.c										\
				$(L_D_STRINGS)strncmp.c										\
				$(L_D_STRINGS)strncpy.c										\
				$(L_D_STRINGS)strndup.c										\
				$(L_D_STRINGS)strpbrk.c										\
				$(L_D_STRINGS)strrchr.c										\
				$(L_D_STRINGS)strsplit.c									\
				$(L_D_STRINGS)strspn.c										\
				$(L_D_STRINGS)strtok_r.c									\
				$(L_D_STRINGS)strtok.c										\
				$(L_D_STRINGS)strtol.c										\
				$(L_D_STRINGS)strwlen.c										\
				$(L_D_STRINGS)wacmp.c										\
				$(L_D_STRINGS)wacpy.c										\
				$(L_D_STRINGS)walen.c										\
				$(L_D_STRINGS)watroy.c
L_C_SYSTEM	=	$(L_D_SYSTEM)basename.c										\
				$(L_D_SYSTEM)dircontent.c									\
				$(L_D_SYSTEM)dirlen.c										\
				$(L_D_SYSTEM)extname.c										\
				$(L_D_SYSTEM)isdir.c
L_C_BUFFER	=	$(L_D_BUFFER)buffchar.c										\
				$(L_D_BUFFER)buffinit.c										\
				$(L_D_BUFFER)buffint.c										\
				$(L_D_BUFFER)buffstr.c										\
				$(L_D_BUFFER)bufftroy.c										\
				$(L_D_BUFFER)fbuff.c										\
				$(L_D_BUFFER)rbuffint.c

L_SOURCES	=	$(L_C_CHAR)													\
				$(L_C_MEMORY)												\
				$(L_C_NUMBER)												\
				$(L_C_PUTS)													\
				$(L_C_STRINGS)												\
				$(L_C_SYSTEM)												\
				$(L_C_BUFFER)

L_OBJECTS	=	$(L_SOURCES:.c=.o)

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#? Program Sources

P_D_ROOT	=	./source/
P_D_CTRL	=	$(P_D_ROOT)controller/
P_D_GAME	=	$(P_D_ROOT)game/
P_D_ENTITY	=	$(P_D_ROOT)entity/
P_D_EDITOR	=	$(P_D_ROOT)editor/
P_D_WEAPONS =   $(P_D_ROOT)weapons/
P_D_UI		=	$(P_D_ROOT)interfaces/
P_D_LVL		=	$(P_D_ROOT)levels/

P_C_ROOT	=	$(P_D_ROOT)main.c											\
				$(P_D_ROOT)arguments.c
P_C_CTRL	=	$(P_D_CTRL)animation.c										\
				$(P_D_CTRL)camera.c											\
				$(P_D_CTRL)shake.c											\
				$(P_D_CTRL)events.c											\
				$(P_D_CTRL)input.c
P_C_GAME	=	$(P_D_GAME)loop.c											\
				$(P_D_GAME)layering.c										\
				$(P_D_GAME)debug.c											\
				$(P_D_GAME)player.c											\
				$(P_D_GAME)health.c											\
				$(P_D_GAME)hud.c											\
				$(P_D_GAME)sign_tuto.c
P_C_EDITOR	=	$(P_D_EDITOR)editor.c										\
				$(P_D_EDITOR)events.c										\
				$(P_D_EDITOR)loop.c											\
				$(P_D_EDITOR)props.c										\
				$(P_D_EDITOR)events/canvas.c								\
				$(P_D_EDITOR)events/focus.c									\
				$(P_D_EDITOR)events/keyboard.c								\
				$(P_D_EDITOR)utils/clipboard.c								\
				$(P_D_EDITOR)utils/window.c									\
				$(P_D_EDITOR)utils/layer.c									\
				$(P_D_EDITOR)utils/move.c									\
				$(P_D_EDITOR)utils/moveall.c								\
				$(P_D_EDITOR)utils/inputs.c									\
				$(P_D_EDITOR)utils/canvas.c									\
				$(P_D_EDITOR)interfaces/browser.c							\
				$(P_D_EDITOR)interfaces/popup.c								\
				$(P_D_EDITOR)interfaces/bottom.c							\
				$(P_D_EDITOR)interfaces/init.c								\
				$(P_D_EDITOR)interfaces/context.c							\
				$(P_D_EDITOR)interfaces/canvas.c							\
				$(P_D_EDITOR)interfaces/settings.c							\
				$(P_D_EDITOR)interfaces/tools.c								\
				$(P_D_EDITOR)interfaces/input.c								\
				$(P_D_EDITOR)interfaces/interfaces.c						\
				$(P_D_EDITOR)interfaces/utils.c								\
				$(P_D_EDITOR)build/save.c									\
				$(P_D_EDITOR)build/load.c
P_C_ENTITY =	$(P_D_ENTITY)entity.c										\
				$(P_D_ENTITY)create.c										\
				$(P_D_ENTITY)movement.c										\
				$(P_D_ENTITY)update.c										\
				$(P_D_ENTITY)random_pos.c									\
				$(P_D_ENTITY)health.c										\
				$(P_D_ENTITY)action.c										\
				$(P_D_ENTITY)boss/action.c									\
				$(P_D_ENTITY)boss/movement.c
P_C_WEAPONS =	$(P_D_WEAPONS)create.c										\
				$(P_D_WEAPONS)update.c										\
				$(P_D_WEAPONS)draw.c
P_C_UI		=	$(P_D_UI)video/load.c										\
				$(P_D_UI)video/loop.c										\
				$(P_D_UI)menu/loop.c										\
				$(P_D_UI)saves/loop.c										\
				$(P_D_UI)saves/load.c										\
				$(P_D_UI)saves/save.c										\
				$(P_D_UI)saves/manage.c										\
				$(P_D_UI)settings/loop.c									\
				$(P_D_UI)settings/colums_settings.c							\
				$(P_D_UI)settings/audio_settings.c							\
				$(P_D_UI)settings/video_settings.c							\
				$(P_D_UI)settings/key_settings.c							\
				$(P_D_UI)settings/resolution.c								\
				$(P_D_UI)pause/loop.c										\
				$(P_D_UI)inventory/loop.c									\
				$(P_D_UI)inventory/player_change.c							\
				$(P_D_UI)text.c
P_C_LVL		=	$(P_D_LVL)switch.c											\
				$(P_D_LVL)end.c												\
				$(P_D_LVL)tutorial.c										\
				$(P_D_LVL)hub.c

P_SOURCES	=	$(P_C_ROOT)													\
				$(P_C_EDITOR)												\
				$(P_C_CTRL)													\
				$(P_C_GAME)													\
				$(P_C_ENTITY)												\
				$(P_C_WEAPONS)												\
				$(P_C_UI)													\
				$(P_C_LVL)

P_OBJECTS	=	$(P_SOURCES:.c=.o)

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#! Building

E_NAME		=	$(E_D_ROOT)moon.a
P_NAME		=	my_rpg
L_NAME		=	$(L_D_ROOT)libmy.a

PRINT_OK	=	echo -ne "\033[0m\033[104m[👍]\033[0m '$<'\033[1K\r"
PRINT_KO	=	echo -e "\033[0m\033[103m[👎]\033[0m '$<'"
GREP_STATUS	=	grep -q "warning:" && $(PRINT_KO) || $(PRINT_OK)

all: $(P_NAME)
	cat axolotl.art

%.o: %.c
	echo -ne "\033[104m[🙏]\033[0m '$<' \r"
	echo -ne "\033[0;33m"
	$(CC) $(FLAG) -c $< -o $@ 2>&1 | tee /dev/tty | $(GREP_STATUS)

build_library: $(L_OBJECTS)
	echo -ne "\033[104m[✅]\033[0m All Objects have been compiled\n"
	echo -e "\033[106m[⚒️]\033[0m Building library"
	echo -e "\033[105m[🏁]\033[0m $(FLAG)"
	ar -rc $(L_NAME) $(L_OBJECTS)
	echo -e "\033[102m[✅]\033[0m Library builded"

build_engine: $(E_OBJECTS)
	echo -ne "\033[104m[✅]\033[0m All Objects have been compiled\n"
	echo -ne "\033[106m[⚒️]\033[0m Building engine \n"
	echo -e "\033[105m[🏁]\033[0m $(FLAG)"
	ar -rc $(E_NAME) $(E_OBJECTS)
	echo -e "\033[102m[✅]\033[0m Engine builded"

build_program: build_library build_engine $(P_OBJECTS)
	echo -ne "\033[104m[✅]\033[0m All Objects have been compiled\n"
	echo -e "\033[106m[⚒️]\033[0m Building program"
	echo -e "\033[105m[🏁]\033[0m $(FLAG)"
	$(CC) $(FLAG) -o $(P_NAME) $(P_OBJECTS) $(E_NAME) $(L_NAME)
	echo -e "\033[102m[✅]\033[0m Program builded"

$(P_NAME): build_program

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#! Testing

T_NAME		=	unit_tests

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#! Cleaning

FIND		=	find -type f -iname
RM			=	rm -f

clean:
	$(FIND) "*.o" -delete
	$(FIND) "*.a" -delete

fclean: clean
	$(RM) $(P_NAME)

tests_clean: clean
	$(FIND) "*.gcno" -delete
	$(FIND) "*.gcda" -delete
	$(FIND) "*.css" -delete
	$(FIND) "*.html" -delete

tests_fclean: tests_clean
	$(RM) $(T_NAME)

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#! Misc

re: fclean all

re_library:
	$(RM) $(L_OBJECTS) $(L_NAME)
	make build_library

re_program:
	$(RM) $(P_OBJECTS) $(L_NAME)
	make build_program

tests_re: tests_fclean tests_run

style:
	echo -e "\033[106m?? Checking for coding style errors...\033[0m"
	coding-style . . > /dev/null
	mv -f coding-style-reports.log old.log > /dev/null
	./style.sh

#-----------------------------------------------------------------------------#

#-----------------------------------------------------------------------------#
#! ARCHIVE MANIPULATION FOR ASSETS

ARCHIVE		:=	assets

EXTENSION	:=	.tar.xz

compress:
	echo -e "\e[34mCompressing assets...\e[0m"
	tar -cJf $(ARCHIVE)$(EXTENSION) assets
	echo -e "\e[32mCompression done.\e[0m"

decompress:
	echo -e "\e[34mDecompressing assets...\e[0m"
	tar -xJf $(ARCHIVE)$(EXTENSION)
	echo -e "\e[32mDecompression done.\e[0m"

#-----------------------------------------------------------------------------#
