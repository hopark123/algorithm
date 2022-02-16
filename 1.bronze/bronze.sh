clang++ -g3 15829.cpp
# clang++ -g3 -fsanitize=address -Wall -Wextra -Werror 1157.cpp
./a.out
# MallocNanoZone=0 ./a.out 
rm -rf a.out
rm -r *.dSYM
