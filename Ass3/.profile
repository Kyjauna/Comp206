# .bashrc

# Source global definitions
if [ -f /usr/socs/Profile ]; then
        . /usr/socs/Profile
fi

# User specific aliases and functions

echo "Welcome $USER to SOCS Bash!"
alias la='ls -la'
HISTSIZE=10
PS1="\u, \w: "
who | grep "kyoung33"
mesg no # no more messages while im trying to work! :^)
