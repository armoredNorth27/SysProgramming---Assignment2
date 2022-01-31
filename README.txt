Compiling instructions...

	For morse_code.c:
		-Navigate to the directory that contains this file using the terminal
		-use the command, "gcc -o morse morse_code.c" to compile and link the program
		-run the program by typing in the command "./morse" into the console.
		-The program should now be running
	
	For refugee_management.c:
		-Navigate to the directory that contains this file using the terminal
		-use the command, "gcc -o refugee refugee_management.c" to compile and link the program
		-run the program by typing in the command "./refugee" into the console.
		-The program should now be running
	
	For number_converter.c: 
		-Navigate to the directory that contains this file using the terminal
		-use the command, "gcc -o number number_converter.c -lm" to compile and link the program
		-run the program by typing in the command "./number" into the console.
		-The program should now be running
		
		*note*: You MUST!!!! compile the program by including the "-lm" at the end of the command.
			If you don't include the -lm then the program won't compile. This is because my
			number converter is using the pow() function from the math library with variables
			as one of its parameters. The -lm allows for variables to be used inside of the
			pow() function.
