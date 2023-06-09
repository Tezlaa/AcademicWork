import time

""" Style """
GREEN = '\x1b[32m'
WHITE = '\x1b[37m'


def benchmark(func):
    """ Banchmark decorator
        Wrapp your function or method if you need to check his running time
    """
    
    def wrapper(*args, **kwarks):
        """
        Wrapper function for benchmarking.
        
        Args:
            *args: Positional arguments passed to the function.
            **kwargs: Keyword arguments passed to the function.

        Returns:
            The result of the function.
        """
        
        start_time = time.time()
        
        result = func(*args, **kwarks)
        
        print('FUNCTION TIME: {}{}{} seconds'.format(GREEN, time.time() - start_time, WHITE))
        return result
    return wrapper


@benchmark
def test_func(start_iter: int, stop_iter: int):
    """ Test func 
    This function performs a loop from the start_iter to the stop_iter values.
    It is used to demonstrate the benchmark decorator.
    
    Args:
        start_iter (int): The starting number of the loop.
        stop_iter (int): The ending number of the loop.
    """
    for _ in range(start_iter, stop_iter):
        pass
    

if __name__ == "__main__":
    test_func(10, 1000000)
    test_func(1, 222222)