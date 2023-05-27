import time

""" Style """
GREEN = '\x1b[32m'
WHITE = '\x1b[37m'


def benchmark(func):
    def wrapper(*args, **kwarks):
        start_time = time.time()
        
        result = func(*args, **kwarks)
        
        print('FUNCTION TIME: {}{}{} seconds'.format(GREEN, time.time() - start_time, WHITE))
        return result
    return wrapper


@benchmark
def test_func(start_iter: int, stop_iter: int):
    """ Test func """
    for _ in range(start_iter, stop_iter):
        pass
    

if __name__ == "__main__":
    test_func(10, 1000000)
    test_func(1, 222222)