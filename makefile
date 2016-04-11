clean:
	cd examples; make clean
	@echo
	cd exercises; make clean
	@echo
	cd collatz; make clean

config:
	git config -l

init:
	touch README
	git init
	git add README
	git commit -m 'first commit'
	git remote add origin git@github.com:gpdowning/ooplsarc.git
	git push -u origin master

pull:
	@rsync -r -t -u -v --delete             \
    --include "Hello.c++"                   \
    --include "Assertions.c++"              \
    --include "UnitTests1.c++"              \
    --include "UnitTests2.c++"              \
    --include "UnitTests3.c++"              \
    --include "Coverage1.c++"               \
    --include "Coverage2.c++"               \
    --include "Coverage3.c++"               \
    --include "Exceptions.c++"              \
    --include "Exceptions2.c++"             \
    --include "Exceptions3.c++"             \
    --include "Variables.c++"               \
    --include "Arguments.c++"               \
    --include "Returns.c++"                 \
    --include "Cache.c++"                   \
    --include "Types.c++"                   \
    --include "Representations.c++"         \
    --include "Operators.c++"               \
    --include "StackVsHeap.c++"             \
    --include "Valgrind.c++"                \
    --include "Iterators.c++"               \
    --include "Selection.c++"               \
    --include "Iteration.c++"               \
    --include "Lambdas.c++"                 \
    --include "Auto.c++"                    \
    --include "Consts.c++"                  \
    --include "Arrays.c++"                  \
    --include "FunctionDefaults.c++"        \
    --exclude "*"                           \
    ../../examples/c++/ examples
	@rsync -r -t -u -v --delete             \
    --include "IsPrime1.c++"                \
    --include "IsPrime1.h"                  \
    --include "StrCmp.c++"                  \
    --include "StrCmp.h"                    \
    --include "Incr.c++"                    \
    --include "Incr.h"                      \
    --include "Equal.c++"                   \
    --include "Equal.h"                     \
    --include "Copy.c++"                    \
    --include "Copy.h"                      \
    --include "Fill.c++"                    \
    --include "Fill.h"                      \
    --include "AllOf.c++"                   \
    --include "AllOf.h"                     \
    --include "Transform.c++"               \
    --include "Transform.h"                 \
    --include "Accumulate.c++"              \
    --include "Accumulate.h"                \
    --include "DigitsIterator.c++"          \
    --include "DigitsIterator.h"            \
    --include "Digits.c++"                  \
    --include "Digits.h"                  \
    --include "Vector1.c++"                 \
    --exclude "*"                           \
    ../../exercises/c++/ exercises
	@rsync -r -t -u -v --delete             \
    --include "Collatz.c++"                 \
    --include "Collatz.h"                   \
    --include "RunCollatz.c++"              \
    --include "RunCollatz.in"               \
    --include "RunCollatz.out"              \
    --include "TestCollatz.c++"             \
    --include "TestCollatz.out"             \
    --exclude "*"                           \
    ../../projects/c++/collatz/ collatz

push:
	make clean
	@echo
	git add .travis.yml
	git add examples
	git add exercises
	git add collatz
	git add makefile
	git commit -m "another commit"
	git push
	git status

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test:
	cd examples; make test
	@echo
	cd exercises; make test
	@echo
	cd collatz; make html
	@echo
	cd collatz; make log
	@echo
	cd collatz; make test
	@echo
	cd collatz; make check
