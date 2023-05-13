from typing import Any, List


def flatten(list_with_list: list, depth: int = 1) -> List[Any]:
    """flatten the list by depth
        Example:
            list_with_list=[1, [2, 3], 4] -> need to get simple [1, 2, 3, 4],
            set depth=1 -> you get [1, 2, 3, 4].
            list_with_list=[1, 2, [3, [4, 5]]], depth=1 -> you get [1, 2, 3, [4, 5]]

    Args:
        list_with_list (list): list what need to flatten
        depth (int, optional): depth flatten the list. Default=1

    Returns:
        List[Any]: flattened list
    """
    
    result = []
    
    for element in list_with_list:
        if isinstance(element, list) and depth > 0:
            result.extend(flatten(element, depth=(depth - 1)))
        else:
            result.append(element)
    return result


if __name__ == "__main__":
    list_for_test = [
        {
            'list': [1, [2, 3], 4],
            'depth': 1
        },
        {
            'list': [1, [2, [3]], 4],
            'depth': 1
        },
        {
            'list': [1, [2, 3], 4, [5, [6, 7]]],
            'depth': 3
        },
        {
            'list': [1, [2, 3], 4, [5, [6, 7]]],
            'depth': 1
        }
    ]
    
    for test_element in list_for_test:
        test_list = test_element['list']
        test_depth = test_element['depth']
        
        result = flatten(list_with_list=test_list,
                         depth=test_depth)
        
        print(f'\nStart list: {test_list}, his depth: {test_depth}\nResult list: {result}')