P = demo

SRCDIR = src
HDIR = include
BINDIR = bin
OBJDIR = obj
DOCDIR = doc

SOURCES := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(HDIR)/*.h)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

AR = ar
CC = gcc
CROSS = msp430
CROSS_COMPILE = ${CROSS}-${CC}
CROSS_AR = ${CROSS}-${AR}
MACHINEFLAGS=-mmcu=msp430g2553
CFLAGS = -Os -g -Iinclude -Wextra -std=c99 $(MACHINEFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	$(CROSS_COMPILE) -c -o $@ $< $(CFLAGS)
	
$(BINDIR)/$(P) : folders lib
	$(CROSS_COMPILE) $(BINDIR)/libeasymsp.a $(MACHINEFLAGS) -o $(BINDIR)/$(P)
		
$(BINDIR):
	mkdir $(BINDIR)
			
$(OBJDIR):
	mkdir $(OBJDIR)
				
$(DOCDIR):
	mkdir $(DOCDIR)
					
folders : $(BINDIR) $(OBJDIR)

lib : $(BINDIR)/libeasymsp.a

$(BINDIR)/libeasymsp.a : $(OBJECTS)
	$(CROSS_AR) rcs $(BINDIR)/libeasymsp.a $(OBJECTS)
							
#install : $(BINDIR)/$(P)
#	avrdude -C/usr/share/arduino/hardware/tools/avrdude.conf -v -v -v -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -Uflash:w:$(BINDIR)/$(P).hex:i
								
clean : $(BINDIR)/$(P) $(FOLDERS)
	rm -f $(OBJDIR)/*.o $(BINDIR)/*.hex $(BINDIR)/*.elf
	rm -rf $(BINDIR)
	rm -rf $(OBJDIR)
	rm -rf $(DOCDIR)
													
serial : $(BINDIR)/$(P)
	screen /dev/ttyACM0 115200 
								
												
documentation : $(DOCDIR) $(SOURCES) $(INCLUDES)
	doxygen Doxyfile

git : 
	git add include/*.h src/*.c Makefile .gitignore Doxyfile
	git status
