from typing import Dict, List


def valid_classes(pair_for_check: List[str], data: dict) -> bool:
    """Recursive function.
       parent == child this is the basic situation
       if parent != child -> then we go through the child's children
       if the child has no children, returns False

    Args:
        pair_for_check (List[str]): [parant, child(ren)]
        data (dict): all data before split_classes

    Returns:
        bool: True if the parent is the parent of the child
    """
    parent = pair_for_check[0]
    child = pair_for_check[1]
    
    if parent == child:
        return True
    
    try:
        for ancestor in data[child]:
            if valid_classes([parent, ancestor], data):
                return True
    except KeyError:
        return False
    
    return False
    

def split_classes(input_classes: str) -> Dict[str, List[str]]:
    split = input_classes.split(' : ')
    
    if len(split) < 2:
        return {input_classes: ['obj']}
    
    parent = split[0]
    children = split[1].split(' ')
    
    return {parent: children}


if __name__ == "__main__":
    data = {}
    results = []
    
    how_many_pairs = int(input('\nWrite how many classes: '))
    for number_cycle in range(how_many_pairs):
        data.update(
            split_classes(input_classes=input(f'Write classes №{number_cycle+1}: '))
        )
    
    how_many_check = int(input('\nWrite how many classes need to check: '))
    for number_cycle in range(how_many_check):
        pair_for_check = input(f'Write pair №{number_cycle+1}: ').split(' ')
        results.append(
            'Yes' if valid_classes(pair_for_check=pair_for_check, data=data) else 'No'
        )
    
    for result in results:
        print(result)
        
        