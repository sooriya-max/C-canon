flags = -Wall -Wextra -fsanitize=address,undefined
input_file = bitrev


run:
	gcc $(flags) $(input_file).c -o $(input_file) && ./$(input_file)

clean:
	rm $(input_file)