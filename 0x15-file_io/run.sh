$FILE = $1;

betty *.c *.h;
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c $FILE;

./a.out Requiescat;

rm a.out;
