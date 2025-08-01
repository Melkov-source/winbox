.PHONY: all clean box scrn

all: scrn box

scrn:
	$(MAKE) -C scrn

box: scrn
	$(MAKE) -C box

clean:
	$(MAKE) -C scrn clean
	$(MAKE) -C box clean
