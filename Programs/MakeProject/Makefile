blah: blah.o
	gcc blah.o -o blah

blah.o: blah.c
	gcc -c blah.c -o blah.o

blah.c:
	echo int main() { return 0; } > blah.c

some_file: other_file
	echo "This will always run, and runs second"
	New-Item -Path "C:\Users\Conrad\Projects\CSC-222\Programs\MakeProject\some_file" -Itemtype File

other_file:
	echo "This will always run, and runs first"

some_file:
	New-Item -Path "C:\Users\Conrad\Projects\CSC-222\Programs\MakeProject\some_file" -Itemtype File

clean:
	rm -f some_file