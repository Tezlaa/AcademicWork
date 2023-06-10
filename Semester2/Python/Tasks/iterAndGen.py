import itertools


def fibonacci():
    """ generator fibonacci
    
    Yields:
        int: The next Fibonacci number in the sequence.
    """
    number_start, number_end = 0, 1
    while True:
        yield number_start
        number_start = number_end
        number_end = number_start + number_end


if __name__ == "__main__":
    print(list(itertools.islice(fibonacci(), 20)))