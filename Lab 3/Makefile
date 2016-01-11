
CC = gccfilter -c -a g++

CCFLAGS  = -g -std=c++11 -Wpedantic -Wall -Wextra -Werror

KALKYLATOR = kalkylator.o Calculator.o Expression_Tree.o Expression.o
EXPRESSION_TREE_TEST = Expression_Tree.o expression_tree-test.o
EXPRESSION_TEST = expression_test.o Expression_Tree.o Expression.o

all: expression_tree-test kalkylator expression_test

kalkylator: $(KALKYLATOR) Makefile
	$(CC) $(CCFLAGS) -o kalkylator $(KALKYLATOR)
    
expression_tree-test: $(EXPRESSION_TREE_TEST) Makefile
	$(CC) $(CCFLAGS) -o expression_tree_test $(EXPRESSION_TREE_TEST)
    
expression_test: $(EXPRESSION_TEST) Makefile
	$(CC) $(CCFLAGS) -o expression_test $(EXPRESSION_TEST)

kalkylator.o: kalkylator.cc
	$(CC) $(CCFLAGS) -c kalkylator.cc

Calculator.o: Calculator.h Calculator.cc
	$(CC) $(CCFLAGS) -c Calculator.cc

Expression_Tree.o: Expression_Tree.h Expression_Tree.cc
	$(CC) $(CCFLAGS) -c Expression_Tree.cc

Expression.o: Expression.h Expression.cc
	$(CC) $(CCFLAGS) -c Expression.cc
    
expression_tree-test.o: expression_tree-test.cc Expression_Tree.h
	$(CC) $(CCFLAGS) -c expression_tree-test.cc

expression_test.o: expression_test.cc Expression_Tree.h Expression.h
	$(CC) $(CCFLAGS) -c expression_test.cc

clean:
	@ \rm -rf *.o *.gch core
    
zap: clean
	@ \rm -rf kalkylator *~