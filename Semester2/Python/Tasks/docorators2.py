from decorators1 import benchmark


def remember(func):
    """ Result cache function """
    cache = {'args': (), 'kwarks': {}, 'result': None}
    
    def wrapper(*args, **kwarks):
        if args != cache['args'] or kwarks != cache['kwarks']:
            cache['args'], cache['kwarks'] = args, kwarks
            cache['result'] = func(*args, **kwarks)
        return cache['result']
    return wrapper


@benchmark
@remember
def test_func(start_iter: int, stop_iter: int):
    """ Test func """
    
    result = 0
    for number in range(start_iter, stop_iter):
        result += number
    return result
    

if __name__ == "__main__":
    result = test_func(start_iter=10, stop_iter=100000000)
    print(result)
    result2 = test_func(start_iter=10, stop_iter=100000000)
    print(result2)
    
    result3 = test_func(start_iter=22, stop_iter=222222)
    print(result3)
    result4 = test_func(start_iter=22, stop_iter=222211)
    print(result4)