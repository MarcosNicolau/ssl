all: flex bison micro clean

bison: 
	bison -yd micro.y 

flex:
	flex micro.l

micro: flex bison
	gcc y.tab.c lex.yy.c -o micro.out

clean:
	rm lex.yy.c y.tab.c y.tab.h