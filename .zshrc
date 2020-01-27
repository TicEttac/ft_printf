# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/Users/nisauvig/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="bureau"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to automatically update without prompting.
# DISABLE_UPDATE_PROMPT="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS=true

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"
function set_conda {
    HOME=$(echo ~)
    INSTALL_PATH="/goinfre"
    MINICONDA_PATH=$INSTALL_PATH"/miniconda3/condabin"
    PYTHON_PATH=$(which python)
    SCRIPT="Miniconda3-latest-MacOSX-x86_64.sh"
    REQUIREMENTS="jupyter numpy pandas"
    DL_LINK="https://repo.anaconda.com/miniconda/Miniconda3-latest-MacOSX-x86_64.sh"
    if echo $PYTHON_PATH | grep -q $INSTALL_PATH; then
        echo "good python version :)"
    else
    cd
    if [ ! -f $SCRIPT ]; then
        curl -LO $DL_LINK
        fi
        if [ ! -d $MINICONDA_PATH ]; then
            sh $SCRIPT -b -p $INSTALL_PATH"/miniconda3"
    fi
    conda install -y $(echo $REQUIREMENTS)
    clear
    echo "Which python:"
    which python
    if grep -q "^export PATH=$MINICONDA_PATH" ~/.zshrc
    then
        echo "export already in .zshrc";
    else
        echo "adding export to .zshrc ...";
        echo "export PATH=$MINICONDA_PATH:$PATH" >> ~/.zshrc
    fi
    source ~/.zshrc
fi }
mk()
{	mkdir $@;
	cd $@ ; }

emacs()
{ vim $@ ; }
alias emacs=vim
if [ ! -d $HOME/custom_scripts ]; then
mkdir $HOME/custom_scripts
fi
if [ ! -f $HOME/custom_scripts/custom_rm ] ; then
{
	echo '# made by ede-ram
		if [ ! -d $HOME/trash ]; then
			mkdir $HOME/trash
				fi
				for file in "$@" ; do
					if [ ! -e $file ] ; then
					{
						/bin/echo $file" inexistant"
							continue
					}
	fi
		if [ -e $HOME/trash/$file ] ; then
		{
			while true; do
				echo "Do you want to overwrite $HOME/trash/$file [y/n]"
					read -p "" yn
					case $yn in
					[Yy]* ) break ;;
			[Nn]* ) continue 2 ;;
			* ) echo "Please answer yes or no.";;
			esac
				done
		}
	fi
		/bin/mv $file $HOME/trash
		/bin/echo $file" moved to trash"
		done' >$HOME/custom_scripts/custom_rm
}
	fi
rm()
	sh $HOME/custom_scripts/custom_rm $@
#export PATH=/Users/nisauvig/.brew/bin:/Users/nisauvig/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware Fusion.app/Contents/Public/:/usr/local/munki

export PATH=/goinfre/miniconda3/bin:/Users/nisauvig/.brew/bin:/Users/nisauvig/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware
export PATH=/goinfre/miniconda3/condabin:/goinfre/miniconda3/bin:/Users/nisauvig/.brew/bin:/Users/nisauvig/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Applications/VMware
