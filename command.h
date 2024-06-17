static const char *browser[] = { "chromium", NULL };
static const char *discord[] = { "discord", NULL };

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", "CaskaydiaCove Nerd Font:size=10", NULL };

static const char *obsidian[] = { "obsidian", NULL };
static const char *gimp[] = { "gimp", NULL };
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *terminal[]  = { "wezterm" };
// static const char *terminal[]  = { "st", "-e", "/usr/bin/tmux", NULL };
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
