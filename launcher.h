// dmenu
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon};


// terminal
static const char *termcmd[]  = { "alacritty", NULL };


// discord 
static const char *discord_cmd[] = { "discord", NULL };


// flameshot
static const char *flameshot_gui[] = { "flameshot", "gui", NULL };


// pulseaudio
static const char *upvol[]   = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "+5%", NULL };
static const char *downvol[] = { "/usr/bin/pactl", "set-sink-volume", "@DEFAULT_SINK@", "-5%", NULL };
static const char *mutevol[] = { "/usr/bin/pactl", "set-sink-mute",   "@DEFAULT_SINK@", "toggle", NULL };


// ranger command
static const char *ranger_cmd[] = { "alacritty", "-e", "nnn", NULL };


// reboot command
static const char *reboot_cmd[] = { "reboot", NULL };


// rofi commands
static const char *rofi_run[] = { "rofi", "-show", "run", NULL };
static const char *rofi_drun[] = { "rofi", "-show", "drun", NULL };
static const char *rofi_window[] = { "rofi", "-show", "window", NULL };


// browser
static const char *shutdown_cmd[] = { "shutdown", "now", NULL };


// browser
static const char *web_cmd[] = { "chromium", NULL };


// wmname
static const char *fix_swing_cmd[] = { "wmname", "LG3D", NULL };

// xbacklight
static const char *incr_brightness[] = { "xbacklight", "-inc", "5", NULL };
static const char *decr_brightness[] = { "xbacklight", "-dec", "5", NULL };
