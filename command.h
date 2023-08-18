static const char *browser[] = { "chromium", NULL };
static const char *discord[] = { "discord", NULL };

/* default command */
// static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
// static const char *termcmd[]  = { "st", NULL };

static const char *obsidian[] = { "obsidian", NULL };
static const char *gimp[] = { "gimp", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *terminal[]  = { "alacritty", NULL };
static const char *wmname[] = { "wmname", "LG3D", NULL };

static const char *rofi_run[] = { "rofi", "-show", "run", NULL };
static const char *rofi_drun[] = { "rofi", "-show", "drun", NULL };
static const char *rofi_window[] = { "rofi", "-show", "window", NULL };

/* power */
static const char *reboot[] = { "reboot", NULL };
static const char *shutdown[] = { "shutdown", "now", NULL };

/* laptop brightness */
static const char *incr_brightness[] = { "xbacklight", "-inc", "5", NULL };
static const char *decr_brightness[] = { "xbacklight", "-dec", "5", NULL };

/* volume */
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };
