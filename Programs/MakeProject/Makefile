files := file1 file2
some_file: $(files)
	echo "Look at this variable: " $(files)
	touch some_file

file1:
	echo >> file1
file2:
	echo >> file2

clean:
	rm -f file1 file2 some_file