TARGET = swap selection bubble qsort pointerConcept endian pointer2 functionPointer voidPointer arrayPointer arrayassignment arrayCompare swapFunction sumArrayFunction sumMatrixFunction helloString charPointerOperation strcatExample filePointer fileDescriptor dynamicAlocation charAddress unionExample enumExample bowling

# MySQL 컴파일 및 링크 옵션을 mysql_config로부터 가져옴
MYSQLFLAGS = $(shell mysql_config --cflags --libs)

all: $(TARGET)

swap: $@
selection: $@
bubble: $@
qsort: $@
pointerConcept: $@
endian: $@
pointer2: $@
functionPointer: $@
voidPointer: $@
arrayPointer: $@
arrayassignment: $@
arrayCompare: $@
swapFunction: $@
sumArrayFunction: $@
sumMatrixFunction: $@
helloString: $@
charPointerOperation: $@
strcatExample: $@
filePointer: $@
fileDescriptor: $@
dynamicAlocation: $@
charAddress: $@
unionExample: $@
enumExample: $@

# bowling 타겟은 MySQL 라이브러리 옵션을 포함하여 컴파일
bowling: bowling.c
		cc bowling.c -o bowling $(MYSQLFLAGS)

clean:
		rm $(TARGET)
