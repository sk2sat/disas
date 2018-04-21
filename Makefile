CXX	= clang++
CXXFLAGS= -std=c++1z
LDFLAGS	=

TARGET	= disas
OBJS	= main.o

TEST_BIN= test.bin
TEST_SRC= test.asm

%.o : %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)

default:
	make $(TARGET)

run: $(TARGET) $(TEST_BIN)
	./$(TARGET) $(TEST_BIN)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $(LDFLAGS) $^

$(TEST_BIN) : $(TEST_SRC)
	nasm -o $@ $<
