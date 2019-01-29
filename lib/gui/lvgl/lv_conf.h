/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_
#define ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_

/* Dynamic memory */

#define LV_MEM_CUSTOM	1

#ifdef CONFIG_LVGL_MEM_POOL_HEAP_KERNEL

#define LV_MEM_CUSTOM_INCLUDE	"kernel.h"
#define LV_MEM_CUSTOM_ALLOC	k_malloc
#define LV_MEM_CUSTOM_FREE	k_free

#elif defined(CONFIG_LVGL_MEM_POOL_HEAP_LIB_C)

#define LV_MEM_CUSTOM_INCLUDE	"stdlib.h"
#define LV_MEM_CUSTOM_ALLOC	malloc
#define LV_MEM_CUSTOM_FREE	free

#else

#define LV_MEM_CUSTOM_INCLUDE	"lvgl_mem.h"
#define LV_MEM_CUSTOM_ALLOC	lvgl_malloc
#define LV_MEM_CUSTOM_FREE	lvgl_free

#endif

/* Graphics settings */

#define LV_HOR_RES	CONFIG_LVGL_HOR_RES
#define LV_VER_RES	CONFIG_LVGL_VER_RES
#define LV_DPI		CONFIG_LVGL_DPI

#define LV_VDB_SIZE	(CONFIG_LVGL_VDB_SIZE  * CONFIG_LVGL_HOR_RES \
		* CONFIG_LVGL_VER_RES / 100)

#if CONFIG_LVGL_BITS_PER_PIXEL == 0
#define LV_VDB_PX_BPP	LV_COLOR_SIZE
#else
#define LV_VDB_PX_BPP	CONFIG_LVGL_BITS_PER_PIXEL
#endif

#ifdef CONFIG_LVGL_VDB_STATIC
#define LV_VDB_ADR	0
#else
#define LV_VDB_ADR	LV_VDB_ADR_INV
#endif


#define LV_VDB_DOUBLE	CONFIG_LVGL_DOUBLE_VDB
#ifdef CONFIG_LVGL_VDB_STATIC
#define LV_VDB2_ADR	0
#else
#define LV_VDB2_ADR	LV_VDB_ADR_INV
#endif

#ifdef CONFIG_LVGL_ANTIALIAS
#define LV_ANTIALIAS	CONFIG_LVGL_ANTIALIAS
#else
#define LV_ANTIALIAS	0
#endif

#define LV_REFR_PERIOD		CONFIG_LVGL_SCREEN_REFRESH_PERIOD
#define LV_INV_FIFO_SIZE	CONFIG_LVGL_AVG_OBJ_COUNT

/* Miscellaneous setting */

#define LV_INDEV_READ_PERIOD		CONFIG_LVGL_INPUT_REFRESH_PERIOD
#define LV_INDEV_POINT_MARKER		CONFIG_LVGL_INPUT_MARK_PRESSED_POINTS
#define LV_INDEV_DRAG_LIMIT		CONFIG_LVGL_INPUT_DRAG_THRESHOLD
#define LV_INDEV_DRAG_THROW		CONFIG_LVGL_INPUT_DRAG_THROW_SLOW_DOWN
#define LV_INDEV_LONG_PRESS_TIME	CONFIG_LVGL_INPUT_LONG_PRESS_TIME
#define LV_INDEV_LONG_PRESS_REP_TIME	CONFIG_LVGL_INPUT_LONG_RESS_REPEAT_TIME

#ifdef CONFIG_LVGL_COLOR_DEPTH_32
#define LV_COLOR_DEPTH	32
#elif defined(CONFIG_LVGL_COLOR_DEPTH_16)
#define LV_COLOR_DEPTH	16
#elif defined(CONFIG_LVGL_COLOR_DEPTH_8)
#define LV_COLOR_DEPTH	8
#elif defined(CONFIG_LVGL_COLOR_DEPTH_1)
#define LV_COLOR_DEPTH	1
#else
#error No color depth defined
#endif

#define LV_COLOR_16_SWAP	CONFIG_LVGL_COLOR_16_SWAP
#define LV_COLOR_SCREEN_TRANSP	CONFIG_LVGL_COLOR_SCREEN_TRANSP

#ifdef CONFIG_LVGL_CHROMA_KEY_RED
#define LV_COLOR_TRANSP LV_COLOR_RED
#elif defined(CONFIG_LVGL_CHROMA_KEY_GREEN)
#define LV_COLOR_TRANSP LV_COLOR_LIME
#elif defined(CONFIG_LVGL_CHROMA_KEY_BLUE)
#define LV_COLOR_TRANSP LV_COLOR_BLUE
#elif defined(CONFIG_LVGL_CHROMA_KEY_CUSTOM)
#define LV_COLOR_TRANSP LV_COLOR_MAKE(CONFIG_LVGL_CUSTOM_CHROMA_KEY_RED, \
		CONFIG_LVGL_CUSTOM_CHROMA_KEY_GREEN, \
		CONFIG_LVGL_CUSTOM_CHROMA_KEY_BLUE)
#else
#error No chroma key defined
#endif

#define LV_TXT_UTF8		CONFIG_LVGL_UTF_8
#define LV_TXT_BREAK_CHARS	CONFIG_LVGL_TEXT_BREAK_CHARACTERS

#define USE_LV_ANIMATION	CONFIG_LVGL_ANIMATION
#define USE_LV_SHADOW		CONFIG_LVGL_SHADOW
#define USE_LV_GROUP		CONFIG_LVGL_GROUP
#define USE_LV_GPU		CONFIG_LVGL_GPU
#define USE_LV_REAL_DRAW	CONFIG_LVGL_DIRECT_DRAW
#define USE_LV_FILESYSTEM	CONFIG_LVGL_FILESYSTEM

#define LV_ATTRIBUTE_TICK_INC
#define LV_ATTRIBUTE_TASK_HANDLER
#define LV_COMPILER_VLA_SUPPORTED		CONFIG_LVGL_VLA_SUPPORT
#define LV_COMPILER_NON_CONST_INIT_SUPPORTED	\
	CONFIG_LVGL_COMPILER_NON_CONST_INIT_SUPPORTED

#define LV_TICK_CUSTOM			1
#define LV_TICK_CUSTOM_INCLUDE		"kernel.h"
#define LV_TICK_CUSTOM_SYS_TIME_EXPR	(k_uptime_get_32())

#if CONFIG_LVGL_LOG_LEVEL == 0
#define USE_LV_LOG	0
#else
#define USE_LV_LOG	1

#if CONFIG_LVGL_LOG_LEVEL == 1
#define LV_LOG_LEVEL LV_LOG_LEVEL_ERROR
#elif CONFIG_LVGL_LOG_LEVEL == 2
#define LV_LOG_LEVEL LV_LOG_LEVEL_WARN
#elif CONFIG_LVGL_LOG_LEVEL == 3
#define LV_LOG_LEVEL LV_LOG_LEVEL_INFO
#elif CONFIG_LVGL_LOG_LEVEL == 4
#define LV_LOG_LEVEL LV_LOG_LEVEL_TRACE
#else
#error Invalid log level defined
#endif

#define LV_LOG_PRINTF   0
#endif

/* Theme support */

#ifdef CONFIG_LVGL_THEMES

#define LV_THEME_LIVE_UPDATE	CONFIG_LVGL_THEME_LIVE_UPDATE

#define USE_LV_THEME_TEMPL	0
#define USE_LV_THEME_DEFAULT	CONFIG_LVGL_THEME_DEFAULT
#define USE_LV_THEME_ALIEN	CONFIG_LVGL_THEME_ALIEN
#define USE_LV_THEME_NIGHT	CONFIG_LVGL_THEME_NIGHT
#define USE_LV_THEME_MONO	CONFIG_LVGL_THEME_MONO
#define USE_LV_THEME_MATERIAL	CONFIG_LVGL_THEME_MATERIAL
#define USE_LV_THEME_ZEN	CONFIG_LVGL_THEME_ZEN
#define USE_LV_THEME_NEMO	CONFIG_LVGL_THEME_NEMO

#else

#define LV_THEME_LIVE_UPDATE	0

#define USE_LV_THEME_TEMPL	0
#define USE_LV_THEME_DEFAULT	0
#define USE_LV_THEME_ALIEN	0
#define USE_LV_THEME_NIGHT	0
#define USE_LV_THEME_MONO	0
#define USE_LV_THEME_MATERIAL	0
#define USE_LV_THEME_ZEN	0
#define USE_LV_THEME_NEMO	0

#endif

/* Font support */

#ifdef CONFIG_LVGL_DEFAULT_FONT_BUILD_IN_10_ASCII
#define LV_FONT_DEFAULT (&lv_font_dejavu_10)
#elif defined(CONFIG_LVGL_DEFAULT_FONT_BUILD_IN_20_ASCII)
#define LV_FONT_DEFAULT (&lv_font_dejavu_20)
#elif defined(CONFIG_LVGL_DEFAULT_FONT_BUILD_IN_30_ASCII)
#define LV_FONT_DEFAULT (&lv_font_dejavu_30)
#elif defined(CONFIG_LVGL_DEFAULT_FONT_BUILD_IN_40_ASCII)
#define LV_FONT_DEFAULT (&lv_font_dejavu_40)
#elif defined(CONFIG_LVGL_DEFAULT_FONT_BUILD_IN_MONOSPACE)
#define LV_FONT_DEFAULT (&lv_font_monospace_8)
#elif defined(CONFIG_LVGL_DEFAULT_FONT_CUSTOM)
extern void *lv_default_font_custom_ptr;
#define LV_FONT_DEFAULT ((lv_font_t *) lv_default_font_custom_ptr)
#else
#error No defulat font defined
#endif

#ifdef CONFIG_LVGL_BUILD_IN_FONT_10

#define USE_LV_FONT_DEJAVU_10 \
	CONFIG_LVGL_BUILD_IN_FONT_10_ASCII_BPP
#define USE_LV_FONT_DEJAVU_10_LATIN_SUP	\
	CONFIG_LVGL_BUILD_IN_FONT_10_LATIN_SUP_BPP
#define USE_LV_FONT_DEJAVU_10_CYRILLIC \
	CONFIG_LVGL_BUILD_IN_FONT_10_CYRILLIC_BPP
#define USE_LV_FONT_SYMBOL_10 \
	CONFIG_LVGL_BUILD_IN_FONT_10_SYMBOL_BPP

#else

#define USE_LV_FONT_DEJAVU_10			0
#define USE_LV_FONT_DEJAVU_10_LATIN_SUP		0
#define USE_LV_FONT_DEJAVU_10_CYRILLIC		0
#define USE_LV_FONT_SYMBOL_10			0

#endif

#if CONFIG_LVGL_BUILD_IN_FONT_20

#define USE_LV_FONT_DEJAVU_20 \
	CONFIG_LVGL_BUILD_IN_FONT_20_ASCII_BPP
#define USE_LV_FONT_DEJAVU_20_LATIN_SUP \
	CONFIG_LVGL_BUILD_IN_FONT_20_LATIN_SUP_BPP
#define USE_LV_FONT_DEJAVU_20_CYRILLIC \
	CONFIG_LVGL_BUILD_IN_FONT_20_CYRILLIC_BPP
#define USE_LV_FONT_SYMBOL_20 \
	CONFIG_LVGL_BUILD_IN_FONT_20_SYMBOL_BPP

#else

#define USE_LV_FONT_DEJAVU_20			0
#define USE_LV_FONT_DEJAVU_20_LATIN_SUP		0
#define USE_LV_FONT_DEJAVU_20_CYRILLIC		0
#define USE_LV_FONT_SYMBOL_20			0

#endif

#if CONFIG_LVGL_BUILD_IN_FONT_30

#define USE_LV_FONT_DEJAVU_30 \
	CONFIG_LVGL_BUILD_IN_FONT_30_ASCII_BPP
#define USE_LV_FONT_DEJAVU_30_LATIN_SUP \
	CONFIG_LVGL_BUILD_IN_FONT_30_LATIN_SUP_BPP
#define USE_LV_FONT_DEJAVU_30_CYRILLIC \
	CONFIG_LVGL_BUILD_IN_FONT_30_CYRILLIC_BPP
#define USE_LV_FONT_SYMBOL_30 \
	CONFIG_LVGL_BUILD_IN_FONT_30_SYMBOL_BPP

#else

#define USE_LV_FONT_DEJAVU_30			0
#define USE_LV_FONT_DEJAVU_30_LATIN_SUP		0
#define USE_LV_FONT_DEJAVU_30_CYRILLIC		0
#define USE_LV_FONT_SYMBOL_30			0

#endif

#if CONFIG_LVGL_BUILD_IN_FONT_40

#define USE_LV_FONT_DEJAVU_40 \
	CONFIG_LVGL_BUILD_IN_FONT_40_ASCII_BPP
#define USE_LV_FONT_DEJAVU_40_LATIN_SUP \
	CONFIG_LVGL_BUILD_IN_FONT_40_LATIN_SUP_BPP
#define USE_LV_FONT_DEJAVU_40_CYRILLIC \
	CONFIG_LVGL_BUILD_IN_FONT_40_CYRILLIC_BPP
#define USE_LV_FONT_SYMBOL_40 \
	CONFIG_LVGL_BUILD_IN_FONT_40_SYMBOL_BPP

#else

#define USE_LV_FONT_DEJAVU_40			0
#define USE_LV_FONT_DEJAVU_40_LATIN_SUP		0
#define USE_LV_FONT_DEJAVU_40_CYRILLIC		0
#define USE_LV_FONT_SYMBOL_40			0

#endif

#define USE_LV_FONT_MONOSPACE_8		CONFIG_LVGL_BUILD_IN_FONT_MONOSPACE

#define LV_FONT_CUSTOM_DECLARE

/* Objects */
#define LV_OBJ_FREE_NUM_TYPE	uint32_t
#define LV_OBJ_FREE_PTR		1

#define USE_LV_LABEL		CONFIG_LVGL_OBJ_LABEL
#if USE_LV_LABEL != 0
#define LV_LABEL_SCROLL_SPEED	CONFIG_LVGL_OBJ_LABEL_SCROLL_SPEED
#endif

#define USE_LV_IMG		CONFIG_LVGL_OBJ_IMAGE
#if USE_LV_IMG != 0
#define LV_IMG_CF_INDEXED	CONFIG_LVGL_IMG_CF_INDEXED
#define LV_IMG_CF_ALPHA		CONFIG_LVGL_IMG_CF_ALPHA
#endif

#define USE_LV_LINE	CONFIG_LVGL_OBJ_LINE

#define USE_LV_ARC	CONFIG_LVGL_OBJ_ARC

#define USE_LV_CONT	CONFIG_LVGL_OBJ_CONTAINER

#define USE_LV_PAGE	CONFIG_LVGL_OBJ_PAGE

#define USE_LV_WIN	CONFIG_LVGL_OBJ_WINDOW

#define USE_LV_TABVIEW		CONFIG_LVGL_OBJ_TAB_VIEW
#if USE_LV_TABVIEW != 0
#define LV_TABVIEW_ANIM_TIME	CONFIG_LVGL_OBJ_TAB_VIEW_ANIMATION_TIME
#endif

#define USE_LV_CALENDAR		CONFIG_LVGL_OBJ_CALENDAR

#define USE_LV_PRELOAD			CONFIG_LVGL_OBJ_PRELOAD
#if USE_LV_PRELOAD != 0
#define LV_PRELOAD_DEF_ARC_LENGTH	CONFIG_LVGL_OBJ_PRELOAD_DEF_ARC_LENGTH
#define LV_PRELOAD_DEF_SPIN_TIME	CONFIG_LVGL_OBJ_PRELOAD_DEF_SPIN_TIME
#endif

#define USE_LV_BAR	CONFIG_LVGL_OBJ_BAR

#define USE_LV_LMETER	CONFIG_LVGL_OBJ_LINE_METER

#define USE_LV_GAUGE	CONFIG_LVGL_OBJ_GAUGE

#define USE_LV_CHART	CONFIG_LVGL_OBJ_CHART

#define USE_LV_LED	CONFIG_LVGL_OBJ_LED

#define USE_LV_MBOX	CONFIG_LVGL_OBJ_MSG_BOX

#define USE_LV_TA	CONFIG_LVGL_OBJ_TEXT_AREA
#if USE_LV_TA != 0
#define LV_TA_CURSOR_BLINK_TIME \
	CONFIG_LVGL_OBJ_TEXT_AREA_CURSOR_BLINK_TIME
#define LV_TA_PWD_SHOW_TIME \
	CONFIG_LVGL_OBJ_TEXT_AREA_PWD_SHOW_TIME
#endif

#define USE_LV_BTN	CONFIG_LVGL_OBJ_BUTTON

#if USE_LV_BTN != 0
#define LV_BTN_INK_EFFECT	CONFIG_LVGL_OBJ_BUTTON_INK_EFFECT
#endif

#define USE_LV_IMGBTN	CONFIG_LVGL_OBJ_IMG_BUTTON

#define USE_LV_BTNM	CONFIG_LVGL_OBJ_BUTTON_MATRIX

#define USE_LV_KB	CONFIG_LVGL_OBJ_KEYBOARD

#define USE_LV_CB	CONFIG_LVGL_OBJ_CHECK_BOX

#define USE_LV_LIST		CONFIG_LVGL_OBJ_LIST
#if USE_LV_LIST != 0
#define LV_LIST_FOCUS_TIME	CONFIG_LVGL_OBJ_LIST_FOCUS_TIME
#endif

#define USE_LV_DDLIST		CONFIG_LVGL_OBJ_DROP_DOWN_LIST
#if USE_LV_DDLIST != 0
#define LV_DDLIST_ANIM_TIME	CONFIG_LVGL_OBJ_DROP_DOWN_LIST_ANIM_TIME
#endif

#define USE_LV_ROLLER		CONFIG_LVGL_OBJ_ROLLER
#if USE_LV_ROLLER != 0
#define LV_ROLLER_ANIM_TIME	CONFIG_LVGL_OBJ_ROLLER_ANIM_TIME
#endif

#define USE_LV_SLIDER	CONFIG_LVGL_OBJ_SLIDER

#define USE_LV_SW	CONFIG_LVGL_OBJ_SWITCH

#endif /* ZEPHYR_LIB_GUI_LVGL_LV_CONF_H_ */