clang++ -g3 2609.cpp
# clang++ -g3 -fsanitize=address -Wall -Wextra -Werror 2108.cpp
./a.out
# MallocNanoZone=0 ./a.out 
rm -rf a.out
rm -r *.dSYM