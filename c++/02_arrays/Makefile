CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRC = prime_numbers.cc            \
      reverse_order.cc           \
      sieve_of_eratosthenes.cc                \
      vector.cc                   \
      vector_eratosthenes.cc    \
      vector_prime.cc        \
     

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

#format: $(SRC)
#	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this #command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
