set nocompatible " be iMproved, required
filetype off " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" Plugins
Plugin 'wincent/command-t'
Plugin 'scrooloose/nerdtree'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'vim-syntastic/syntastic'
Plugin 'tpope/vim-fugitive'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'mhinz/vim-startify'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on

" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" General
syntax on " Put colors in Vim
set number " Displays lines number
set ruler " By default, it displays the line number, the column number, the virtual column number, and the relative position of the cursor in the file (as a percentage) on the right side of the status line at the bottom of the window
set autoindent " Copy the indentation from the previous line, when starting a new line.
set smartindent "  Automatically inserts one extra level of indentation in some cases, and works for C-like files
set mouse=a " Allows to use the mouse
set mousehide  " Hide mouse after chars typed
set backspace=2 " Make backspace works like most other programs
set timeoutlen=250  " Time to wait after ESC (default causes an annoying delay)
highlight EW ctermbg=darkgreen guibg=lightgreen
match EW /  \+$/ " Shows, in green, spaces errorsi

" Visual
set novisualbell " No blinking
set noerrorbells " No noise
set laststatus=2  " Always show status line
set showcmd " Display an incomplete command in the lower right corner of the Vim window

" Syntastic
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*
let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0

" NERDTree
"autocmd vimenter * NERDTree " Open NERDTree with vim
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif " Automatically quit vim if NERDTree is last and only buffer
"map <C-n> :NERDTreeToggle<CR> " Map a key or shortcut to open NERDTree, here ctrl+n (instead of :NERDTree) SEARCH FOR ANOTHER COMBINATION, CTRL+N ALREADY USE 
