if __name__ == "__main__":
    array_text = input('Write text: ')[:-1].split(',')  # del dot and split on list
    string_to_int_array = [int(number) for number in array_text]  # string to int
    print(string_to_int_array)
    
    """
    args:
        array_str(list): list with word
        a_start_array, b_start_array, c_start_array(list): lists for the word with the start symbol
    """
    array_str = ['ability', 'boolion', 'biuld', 'city', 'apple', 'Bogdan']
    
    a_start_array = []
    b_start_array = []
    c_start_array = []
    
    for i, word in enumerate(array_str):
        if word[0] == 'a':
            a_start_array.append(word)
        elif word[0] == 'b':
            b_start_array.append(word)
        elif word[0] == 'c':
            c_start_array.append(word)

    array_str = a_start_array + b_start_array + c_start_array
    print(array_str)
    
    """
    args:
        text(str): all text
        coma_count(int): how many comm in text
        semicolon_count(int): how many semicolon in text
    """
    text = input('Write text: ')

    comma_count = text.count(',')
    semicolon_count = text.count(';')

    if comma_count > semicolon_count:
        print("More commas")
    elif semicolon_count > comma_count:
        print("More semicolons")
    else:
        print("Equal")
