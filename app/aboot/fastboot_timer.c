#include <stdlib.h>
#include "fastboot.h"
#include "fastboot_timer.h"

#ifdef FASTBOOT_TIMER
bool stay_in_fastboot = false;

bool fastboot_stay_requested() 
{
    return stay_in_fastboot;
}

void set_fastboot_stay_flag(bool en) 
{
	stay_in_fastboot = en;
}

static void cmd_oem_stay(const char *arg, void *data, unsigned sz)
{
    stay_in_fastboot = true;
	fastboot_okay("");
}

void fastboot_timer_register_commands(void) {
	fastboot_register("oem stay", cmd_oem_stay);
}
#endif