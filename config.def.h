/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */

/* fonts */

/* defaults */
// static const char *fonts[]          = { "monospace:size=10" };

static const char *fonts[]             = { "CaskaydiaCove Nerd Font:size=10:antialias=true:autohint=true" };

/* theme */
#include "theme.h"

/* default */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_rose  },
};

/* tokyo night */
// static const char *colors[][3] = {
//     /*                     fg       bg      border */
//     [SchemeNorm]       = { white,   black,  gray2 },
//     [SchemeSel]        = { black,   blue,   blue  },
// };

/* tagging */
static const char *tags[] = { "", "", "", "󰘐", "5", "", "7", "8", "󰙯  " };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "Alacritty", NULL,       NULL,       1 << 0,       0,           -1 },
	{ "Chromium",  NULL,       NULL,       1 << 1,       0,           -1 },
    { "obsidian" , NULL,       NULL,       1 << 2,       0,           -1 },
    { "dbeaver",   NULL,       NULL,       1 << 3,       0,           -1 },
    { "code",      NULL,       NULL,       1 << 3,       0,           -1 },
	{ "Gimp",      NULL,       NULL,       1 << 5,       0,           -1 },
    { "spotify",   NULL,       NULL,       1 << 8,       0,           -1 },
    { "Discord",   NULL,       NULL,       1 << 8,       0,           -1 }
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

/* key definitions */
#include <X11/XF86keysym.h> // For function keys
#include "command.h"

#define MODKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
	/* modifier                     key        function        argument */

    /* windows management */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
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

    /* tag */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_0,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_BackSpace, spawn,             {.v = shutdown} },
	{ MODKEY|ControlMask,           XK_BackSpace, spawn,             {.v = reboot} },

    /* application */
    { WINKEY,                       XK_b,      spawn,          {.v = browser } },
    { WINKEY,                       XK_c,      spawn,          {.v = discord } },
    { WINKEY,                       XK_g,      spawn,          {.v = gimp }},
    { WINKEY,                       XK_o,      spawn,          {.v = obsidian }},
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { ControlMask|ShiftMask,        XK_s,      spawn,          {.v = flameshot } },
    { WINKEY|ShiftMask,             XK_d,      spawn,          {.v = rofi_run } },
    { WINKEY,                       XK_d,      spawn,          {.v = rofi_drun } },
    { WINKEY,                       XK_w,      spawn,          {.v = rofi_window } },
    { WINKEY,                       XK_Return, spawn,          {.v = terminal } },
    { WINKEY|MODKEY,                XK_f,      spawn,          {.v = wmname } },
    { 0,                            XF86XK_MonBrightnessUp,    spawn, {.v = incr_brightness } },
    { 0,                            XF86XK_MonBrightnessDown,  spawn, {.v = decr_brightness } },
    { 0,                            XF86XK_AudioLowerVolume, spawn, {.v = downvol } },
    { 0,                            XF86XK_AudioMute,        spawn, {.v = mutevol } },
    { 0,                            XF86XK_AudioRaiseVolume, spawn, {.v = upvol   } },

    /* gaps */
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = terminal } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

