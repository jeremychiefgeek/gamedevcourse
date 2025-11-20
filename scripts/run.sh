#!/bin/sh
exec /usr/bin/g++ -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror -std=c++23 "$@"
