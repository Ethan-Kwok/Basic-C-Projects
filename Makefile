all : RightTruncatablePrimes

RightTruncatablePrimes : RightTruncatablePrimes.c
	gcc -Wall -Werror -fsanitize=address -std=c11 RightTruncatablePrimes.c -o RightTruncatablePrimes -lm

OrderedLinkedList : OrderedLinkedList.c
	gcc -Wall -Werror -fsanitize=address -std=c11 OrderedLinkedList.c -o OrderedLinkedList -lm

StacksAndQueues : StacksAndQueues.c
	gcc -Wall -Werror -fsanitize=address -std=c11 StacksAndQueues.c -o StacksAndQueues -lm

MatrixDeterminantCalculator : MatrixDeterminantCalculator.c
	gcc -Wall -Werror -fsanitize=address -std=c11 MatrixDeterminantCalculator.c -o MatrixDeterminantCalculator -lm

MagicSquareGenerator : MagicSquareGenerator.c
	gcc -Wall -Werror -fsanitize=address -std=c11 MagicSquareGenerator.c -o MagicSquareGenerator -lm

clean : 
	rm -rf RightTruncatablePrimes