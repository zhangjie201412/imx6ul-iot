#define LOG_TAG     "BUGGER"

#include <execinfo.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ucontext.h>
#include <unistd.h>

#include <cutils/log.h>
#include <cutils/bugger.h>

typedef struct _sig_ucontext {
    unsigned long       uc_flags;
    struct ucontex      *uc_link;
    stack_t             uc_stack;
    struct sigcontext    uc_mcontext;
    sigset_t            uc_sigmask;
} sig_ucontext_t;

void critical_error_handler(int sig_num, siginfo_t *info,
        void *ucontext)
{
    void *array[128];
    void *caller_addr;
    char **messages;
    int size, i;
    sig_ucontext_t *uc;

    uc = (sig_ucontext_t *)ucontext;
    //get the address at the time the signal was raised
    //just for arm
    caller_addr = (void *)uc->uc_mcontext.arm_pc;
    ALOGE("signal %d (%s), address is %p from %p",
            sig_num, strsignal(sig_num), info->si_addr,
            (void *)caller_addr);

    size = backtrace(array, 128);
    //overwrite sigaction with caller's address
    array[1] = caller_addr;
    messages = backtrace_symbols(array, size);

    //skip first stack frame(pointers here)
    for(i = 1; i < size && messages != NULL; ++i) {
        ALOGE("     (%d) %s", i, messages[i]);
    }

    free(messages);
    exit(EXIT_FAILURE);
}

void bugger_start()
{
    struct sigaction sigact;

    sigact.sa_sigaction = critical_error_handler;
    sigact.sa_flags = SA_RESTART | SA_SIGINFO;

    if(sigaction(SIGSEGV, &sigact, (struct sigaction *)NULL) != 0) {
        ALOGE("Error setting signal handler for %d (%s)",
                SIGSEGV, strsignal(SIGSEGV));
        exit(EXIT_FAILURE);
    }
}
