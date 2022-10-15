clang++ -std=c++17 -O2 -Wno-unused-result 셔틀버스.cpp
# clang++ -fsanitize=address -std=c++11 합승택시요금.cpp
# clang++ -g3 -fsanitize=address -Wall -Wextra -Werror 프렌즈4블록.cpp
# ./a.out
MallocNanoZone=0 ./a.out 
rm -rf a.out
# rm -r *.dSYM