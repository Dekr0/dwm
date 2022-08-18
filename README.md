## Introduction

- This build of dwm includes some additional patches, which were that were applied upon the original source code of dwm, for personal usage. For offical vanilla version of dwm, please go visit the [offical suckless website](https://dwm.suckless.org/).

- Current `branch` I'm using the most - `moveresize`

---

## Requirements

- In order to build dwm you need the Xlib header files.

---

## Installation

- Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

- Afterwards enter the following command to build and install dwm (if
necessary as root):
    - `make clean install`

---

## Running dwm

- Add the following line to your .xinitrc to start dwm using startx:
    - `exec dwm`

- In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:
    - `DISPLAY=foo.bar:1 exec dwm`
     (This will start dwm on display :1 of the host foo.bar.)

- In order to display status info in the bar, you can do something
like this in your .xinitrc:

```
    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm
```

---

## Configuration

- The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

---

## Maintaining source code

### General Procedures

- Before making any change or patch, do the following:
    - `make clean && rm -f config.h && git reset --hard origin/master`
    - or run the `reset.sh script`
    - `rm -f config.h` is to remove `config.h` file from the make process
    - `git reset --hard origin/master` is to reset the state of main branch to the state of origin/master branch in https://git.suckless.org/dwm

- Create a new branch. Name of that new branch can be related to the changes or patches being made

- Switch to that new branch

- Make the necessary changes / patches in that new branch

- Add and commit the change made in that new branch

- Switch to main branch (eqivalent to origin/master branch in https://git.suckless.org/dwm)

- Merge the change in that new branch into main branch.

- Make sure that there are no errors happen after merging. If there are errors, do not go to the next step before errors are resolved

- Compile and build the source code by doing the following:
    - `make && sudo make clean install`

- If there are updates from suckless, do the following:
	- If the current repo does not have a remote for https://git.suckless.org/dwm, do the following:
        - `git remote add upstream https://git.suckless.org/dwm`
        - Note that "upstream" is a branch name under remotes
	- Fetch the updates
		- `git fetch upstream`
	- Switch to your master or main branch
        - You can either 
            - rewrite your master or mainbranch so that any commits of yours that aren't already in `upstream/master` or `upstream/main` are replayed on top of that other branch
				- `git rebase upstream/master or git rebase upstream/main`
			- or you don't want to rewrite the history of your master or main branch, then 
				- `git merge upstream/master or git merge upstream/main`

---

### Managing Branches

- `main` and `upstream/master` should only contains source code of original build of dwm (without any patch or modification beside `README.md`)

- `keybinding` should only contains keybindings that relates to manipulation of dwm pre-existed functionality, and keybindings that spawn applications or executing command
	- If you want to add keybindings that relate to a particular patch, make change on the branch that relate to that particular patch

- Everytime install a new patch, try to create a new branch just for that new patch so that it's as modular as possible
	- unless there are conflicts when merging each branch (install each individual patch).

---

## Applying changes and patches


- Try the following to apply a desire patch:
    - `git apply pacth-filename`

- If the previous step failed, do the following:
    - `patch < patch-filename`

- If the previous step failed, it should generate (a) .rej file(s) with. Each .rej file corresponds to a file that needs to be patch. (For example, `dwm.rej.c` -> `dwm.c`)
    - Open each .rej file and its corresponding file that needs to be patch
        - `+++` indicates that lines that need to be manually added from .rej file to into its corresponding file that needs to be patch
        - `---` indicates that lines that need to be manually added from .rej file to into its corresponding file that needs to be patch
