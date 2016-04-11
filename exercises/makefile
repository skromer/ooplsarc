FILES :=          \
    IsPrime1      \
    StrCmp        \
    Incr          \
    Copy          \
    Fill          \
    AllOf

CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
VALGRIND   := valgrind

%.app: %.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $< -o $@ $(LDFLAGS)

%.c++x: %.app
	./$<
	$(GCOV) -b ./$(<:.app=.c++) | grep -A 5 "File '$(<:.app=.c++)'"

clean:
	rm -f *.app
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov

test: $(FILES:=.c++x)
