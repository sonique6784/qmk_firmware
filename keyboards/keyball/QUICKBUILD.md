# HACK
## OLED
* keyboards/keyball/lib/logofont/logofont.c
* keyboards/keyball/lib/oledkit/oledkit.c

## CONFIG
### Specific K61
* keyboards/keyball/keyball61/config.h
### Common
* keyboards/keyball/config.h

# BUILD
cd qmk_firmware/
make keyball/keyball61:via -j 8
