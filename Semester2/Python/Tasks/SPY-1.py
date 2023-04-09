import array


if __name__ == "__main__":
    # """
    # args:
    #     text(str): all text
    #     text_before_symbol(str): cropped text + 1 before symbol - ':'
    # """
    
    # text = input('Write text: ')
    
    # text_before_symbol = text[:text.find(':') + 1]
    # print(text_before_symbol)
    
    # """
    # args:
    #     text(str): all text
    # """
    # text = input('Write text: ').lower()
    
    # print(f"\n\tcount symbol 'a' - {text.count('a')}"
    #       f"\n\tcount symbol 'b' - {text.count('b')}"
    #       f"\n\tcount symbol 'c' - {text.count('c')}"
    #       f"\n\tcount symbol 'd' - {text.count('d')}\n")
    
    """
    args:
        array_text(list): generator which print input field with number text
        max_text_in_array(str): max element in list
        
        factor(int): factor for adding space before text
        
    """
    array_text = [input(f'Write text number {text_number}: ') for text_number in range(1, 4)]
    
    max_text_in_array = max(array_text, key=len)

    for i, item in enumerate(array_text):
        if max_text_in_array != item:
            factor = len(max_text_in_array) - len(item)
            array_text[i] = " " * factor + item
    
    print(f'\ntext 1: {array_text[0]}\n'
          f'text 2: {array_text[1]}\n'
          f'text 3: {array_text[2]}\n')