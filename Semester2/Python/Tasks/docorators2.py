from decorators1 import benchmark


def remember(func):
    """ Decorator to caches function

    Args:
        func (callable): the function to be dicorated

    Returns:
        callable: The decorated function
    
    """
    cache = {'args': None, 'kwargs': None, 'result': None}
    
    def wrapper(*args, **kwargs):
        if (args, kwargs) != (cache['args'], cache['kwargs']):
            cache['args'], cache['kwargs'] = args, kwargs
            cache['result'] = func(*args, **kwargs)
        return cache['result']
    return wrapper


@benchmark
@remember
def test_func(start_iter: int, stop_iter: int) -> int:
    """ function for testing caches decorator

    Args:
        start_iter (int): number start for itaration
        stop_iter (int): number stor for iteration
        (start_iter > stop_iter)!!!

    Returns:
        int: result
    """
    
    result = 0
    for number in range(start_iter, stop_iter):
        result += number
    return result
    

if __name__ == "__main__":
    result = test_func(10, 100000000)
    print(result)
    result2 = test_func(10, 100000000)
    print(result2)

    result3 = test_func(22, 222222)
    print(result3)
    result4 = test_func(22, 222211)
    print(result4)
