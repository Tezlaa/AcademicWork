from typing import Dict, Hashable


def set_or_create_by_hash(dictionary: dict, key: Hashable, values: str) -> Dict[str, str]:
    """
    
    Args:
        dictionary (dict)
        key (str): key hash
        values (str): user values

    Returns:
        Dict[str, str]: appending values in list by hash
    """
    
    try:
        dictionary[key].append(values)
    except KeyError:
        dictionary[key] = [values]

    return dictionary
    

def set_or_create(dictionary: dict, key: str, values: str) -> Dict[str, str]:
    """function for the set in list by key or create element by 2 * hash(key)

    Args:
        dictionary (dict)
        key (str): user key
        values (str): user values

    Returns:
        Dict[str, str]: result dict with appending values in list or 
        appending values in list by (2 * hash(key))
    """
    try:
        dictionary[key].append(values)
    except KeyError:
        hash_key = 2 * hash(key)
        
        dictionary = set_or_create_by_hash(dictionary=dictionary,
                                           key=hash_key,
                                           values=values)

    return dictionary


if __name__ == "__main__":
    """
    args:
        dictionary(dict): dict with key and values
        key(str): user key
        values(str): user values in key
    """
    dictionary = {'hi': []}
    
    while True:
        
        print('_' * 50)
        for element in dictionary.items():
            print(f'{element[0]} - {element[1]}')
        
        key = input('\nWrite key for a dictionary (write "." that exit): ')
        if key == '.':
            break
        
        values = input('Write values for a dictionary: ')
        
        dictionary = set_or_create(dictionary, key, values)
    
    