from typing import Any


""" Style """
WHITE = '\x1b[37m'
RED = '\x1b[31m'


def valid_objects(magic_methods: list[str]):
    """ Valid any function
    

    Args:
        magic_methods (List[str]): List with needed magic methods
                        Example use: magic_methods=['__str__', '__len__']
                        magic_methods[0] -> to first argument in the function
                        megic_methods[1] -> to second argument in the function
                        ...
    """

    def decorator(func):
        def wrapper(*args, **kwargs):
            """ Wrapper for the called function
            
            1. Create list for all arguments [args, kwargs.values()] and iterate on him
            2. everyone arguments zip with our magic_methods, we are have tuple: (argument, method)
                Example: (['hello', 'all'], '__int__')
            3. give them to the check_attr() function
            
            """
            
            for arguments in [args, kwargs.values()]:
                for argument, method in zip(arguments, magic_methods):
                    check_attr(argument, method)
              
            return func(*args, **kwargs)
        return wrapper
    return decorator


def check_attr(attribut: Any, magic_method: str) -> None | ValueError:
    """ Function to check if an attribute has a magic method or raise ValueError
        if attribut has a magic method -> Nothing return
        else -> return ValueError

    Args:
        attribut (Any): an attribut for check
        magic_method (str): magic method for check

    Raises:
        ValueError: If the attribut not has a magic method

    Returns:
        None: If the attribut has a magic method
    """
    if not hasattr(attribut, magic_method):
        raise ValueError(f"{RED}ERROR ARGUMENT: {attribut}, doesn't have magic method {magic_method}!{WHITE}")


@valid_objects(magic_methods=["__iter__", "__int__"])
def test_func(obj, int):
    """ Test func, arguments for test"""
    
    for i in obj:
        print(i)


if __name__ == "__main__":
    test_func(['2323', '1231'], 1)