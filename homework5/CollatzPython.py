import time

start = time.time()
def collatz_length(number):
    count = 0
    while number != 1:
        #even
        if number % 2 == 0:
            number //= 2
        #odd
        else:
            number = 3 * number + 1
        count += 1
    return count

def collatz_print_sequence(number):
    #print the sequence
    print(f"({number}: ", end="")
    while number != 1:
        #add arrow inbetween sequence
        print(f"{number} -> ", end="")
        if number % 2 == 0:
            number //= 2
        else:
            number = 3 * number + 1
    print("1)")

def main():
    max_number = 0
    max_length = 0

    #creates the range
    for i in range(1, 1000000):
        length = collatz_length(i)
        if length > max_length:
            max_length = length
            max_number = i

    print(f"Number with longest Collatz sequence: {max_number}")
    print("Collatz Sequence: ", end="")
    collatz_print_sequence(max_number)
    end = time.time()
    print(f"It took: {end - start} seconds")

if __name__ == "__main__":
    main()
"""
1,000,000,000 took to long to run but
the largest number for 1,000,000 is 837,799
and it took about 6.87 seconds to run.
"""
