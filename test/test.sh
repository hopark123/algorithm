clang++  -std=c++11 dev5.cpp
# clang++ -fsanitize=address -std=c++11 2.cpp
# clang++ -g3 -fsanitize=address -Wall -Wextra -Werror 프렌즈4블록.cpp
# ./a.out
MallocNanoZone=0 ./a.out 
rm -rf a.out
# rm -r *.dSYM