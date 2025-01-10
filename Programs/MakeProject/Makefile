hey: one two
	# Outputs "hey", since this is the target name
	echo $@

	# Outputs all prerequisites newer than the target
	echo $?

	# Outputs all prerequisites
	echo $^

	# Outputs the first prerequisite
	echo $<

	echo >> hey

one:
	echo >> one

two:
	echo >> two

clean:
	rm -f hey one two