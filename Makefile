##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## global
##

subsystem:
	cd generator && $(MAKE)
	cd solver && $(MAKE)	
clean:
	cd generator && $(MAKE) clean
	cd solver && $(MAKE) clean
fclean:
	cd generator && $(MAKE) fclean
	cd solver && $(MAKE) fclean
re:
	cd generator && $(MAKE) re
	cd solver && $(MAKE) re
