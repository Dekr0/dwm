/* See LICENSE file for copyright and license details. */

// For function keys
#include <X11/XF86keysym.h>


/* broder */
static const unsigned int borderpx  = 1;        /* border pixel of windows */


/* snap */
static const unsigned int snap      = 32;       /* snap pixel */


/* gaps */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */


/* bar */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */


/* font */
static const char *fonts[]          = { "CaskaydiaCove Nerd Font:size=10:antialias=true:autohint=true" };


/* theme */
#include "theme.h"

static const char *colors[][3]      = {
    /*                     fg       bg      border */
    [SchemeNorm]       = { white,   black,  gray2 },
    [SchemeSel]        = { black,   blue,   blue  },
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* hotkey */

// key definitions
#define MODKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// helper for spawning shell commands in the pre dwm-5.0 fashion
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#include "launcher.h"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ WINKEY,                       XK_Return, spawn,          {.v = termcmd } }, // Modified
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} }, // Modified
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_0,      quit,           {0} }, // Modified
	{ MODKEY|ShiftMask,             XK_BackSpace, spawn,             {.v = shutdown_cmd} },
	{ MODKEY|ControlMask,           XK_BackSpace, spawn,             {.v = reboot_cmd} },

	/* Patches keybinding */
	// moveplace keybinding
	{ MODKEY|ShiftMask,             XK_Scroll_Lock,           moveplace,      {.ui = WIN_NW }},
	{ MODKEY,                       XK_Scroll_Lock,           moveplace,      {.ui = WIN_N  }},
	{ MODKEY,                       XK_Pause,                 moveplace,      {.ui = WIN_NE }},
	{ MODKEY,                       XK_Insert,                moveplace,      {.ui = WIN_W  }},
	{ MODKEY,                       XK_Home,                  moveplace,      {.ui = WIN_C  }},
	{ MODKEY,                       XK_Page_Up,               moveplace,      {.ui = WIN_E  }},
	{ MODKEY,                       XK_Delete,                moveplace,      {.ui = WIN_SW }},
	{ MODKEY,                       XK_End,                   moveplace,      {.ui = WIN_S  }},
	{ MODKEY,                       XK_Page_Down,             moveplace,      {.ui = WIN_SE }},
	// moveplace laptop keybinding
	// { MODKEY,                       XK_KP_Home,         moveplace,      {.ui = WIN_NW }},
	// { MODKEY,                       XK_KP_Up,           moveplace,      {.ui = WIN_N  }},
	// { MODKEY,                       XK_KP_Page_Up,      moveplace,      {.ui = WIN_NE }},
	// { MODKEY,                       XK_KP_Left,         moveplace,      {.ui = WIN_W  }},
	// { MODKEY,                       XK_KP_Insert,       moveplace,      {.ui = WIN_C  }},
	// { MODKEY,                       XK_KP_Right,        moveplace,      {.ui = WIN_E  }},
	// { MODKEY,                       XK_KP_End,          moveplace,      {.ui = WIN_SW }},
	// { MODKEY,                       XK_KP_Down,         moveplace,      {.ui = WIN_S  }},
	// { MODKEY,                       XK_KP_Page_Down,    moveplace,      {.ui = WIN_SE }},
	// moveresize keybinding
	{ WINKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ WINKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ WINKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ WINKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ WINKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ WINKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ WINKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ WINKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ WINKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ WINKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ WINKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ WINKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ WINKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ WINKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ WINKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ WINKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
	// vanitygaps keybinding (modified)
	{ MODKEY|WINKEY,              XK_equal,              incrgaps,       {.i = +1 } },
	{ MODKEY|WINKEY,              XK_minus,              incrgaps,       {.i = -1 } },
	{ MODKEY|WINKEY|ShiftMask,    XK_equal,              incrogaps,      {.i = +1 } },
	{ MODKEY|WINKEY|ShiftMask,    XK_minus,              incrogaps,      {.i = -1 } },
	{ MODKEY|WINKEY|ControlMask,  XK_equal,              incrigaps,      {.i = +1 } },
	{ MODKEY|WINKEY|ControlMask,  XK_minus,              incrigaps,      {.i = -1 } },
	{ MODKEY|WINKEY,              XK_g,                  togglegaps,     {0} },
	{ MODKEY|WINKEY|ShiftMask,    XK_g,                  defaultgaps,    {0} },
	{ MODKEY,                     XK_bracketleft,        incrihgaps,     {.i = +1 } },
	{ MODKEY,                     XK_bracketright,       incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,         XK_bracketleft,        incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,         XK_bracketright,       incrivgaps,     {.i = -1 } },
	{ MODKEY|WINKEY,              XK_bracketleft,        incrohgaps,     {.i = +1 } },
	{ MODKEY|WINKEY,              XK_bracketright,       incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,           XK_bracketleft,        incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,           XK_bracketright,       incrovgaps,     {.i = -1 } },
	
	/* Application keybinding */
	// browser keybinding
	{ WINKEY,                       XK_b,      spawn,          {.v = web_cmd } },
	// discord keybinding
	{ WINKEY,                       XK_c,      spawn,          {.v = discord_cmd} },
	// flameshot keybinding
	{ ControlMask|ShiftMask,        XK_s,      spawn,          {.v = flameshot_gui} },
	// pulseaudio keybinding
	{ 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
	{ 0,                            XF86XK_AudioMute,        spawn, {.v = mutevol } },
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },
	// ranger
	{ WINKEY,                       XK_r,      spawn,          {.v = ranger_cmd } },
	// rofi keybinding
	{ WINKEY|ShiftMask,             XK_d,      spawn,          {.v = rofi_run } },
	{ WINKEY,                       XK_d,      spawn,          {.v = rofi_drun } },
	{ WINKEY,                       XK_w,      spawn,          {.v = rofi_window } },
	// wmname
	{ WINKEY|MODKEY,                XK_f,      spawn,          {.v = fix_swing_cmd } },
	// xbacklight
	{ 0,                            XF86XK_MonBrightnessUp,    spawn, {.v = incr_brightness } },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = decr_brightness } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
