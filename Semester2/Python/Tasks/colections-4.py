if __name__ == "__main__":
    """
    Args:
        user_text(List[str]): User text to lower and split on list
        result(Dict[str, int]): result dict where:
            key - word
            value - how much
    """
    
    user_text = input('Write your text: ').lower().split()
    result = {}
    
    for word in user_text:
        try:
            result[word] += 1
        except KeyError:
            result[word] = 1
    
    for word in result.items():
        print(word[0], word[1])