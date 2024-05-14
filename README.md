# User-Level System Call Hook Report
To use zpoline to achieve monitoring and modification of system calls.
## Overview
[Zpoline: a system call hook mechanism based on binary rewriting](https://www.usenix.org/system/files/atc23-yasukata.pdf)
*Zpoline* employs binary rewriting techniques to redirect the originally intended syscall instructions to a user-defined hook
function, enabling users to implement user-level system call hooking.
In this project, you need to use z p ol i ne to achieve monitoring and modification of system calls. The recommended operating
environment is Ubuntu 22.04 x86_64. 
>`(If you are using an M1/M2 Mac, you will require a virtual machine that supports x86
emulation.)`

## Requirement
1. Build z p ol i ne from source code : [GitHub - yasukata/zpoline: system call hook for Linux](https://github.com/yasukata/zpoline)
3. Execute the default system call hook by *zpoline*.
LIBZPHOOK=./apps/basic/libzphook_basic.so LD_PRELOAD=./libzpoline.so /bin/ls
4. Check the [system call table](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/) to determine which system calls have been invoked by the ls program.
