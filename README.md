## DeviceDriversLabExam

# Bazif Rasool

The Keylogger is a ready to add kernel module that records keyboard strokes of capital letters.


## How to Run?

- make
- sudo insmod keylogger.ko
- open the /var/log/syslog file to check if it has logged keystrokes

## How it Works?

- is based on Lab Exercise 9
- is different as we only need capital letters in this
- added else-if clause to capture Capital Letters
-**if((param->value > 15 && param->value<=25) || (param->value > 29 && param->value<=38) || (param->value>43 && param->value<=50))**
- removed logging entry if small case letter
-**if (shiftKeyPressed == 0);
			//if Shift is not pressed then it is not logged
			// so no action will be taken**
