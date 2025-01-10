comma := ,
empty:=
space := $(empty) $(empty)
foo := a b c
bar := $(subst $(space), $(comma) , $(foo)) # Watch out!

all:
	# Output is ", a , b , c". Notice the spaces introduced
	@echo $(bar)