class C1:
    def __init__(self) -> None:
        self._text = ''
    
    def _show_text(self) -> None:
        print(self._text)

    def _set_text(self, value) -> None:
        self._text = value
    
    text = property(_show_text, _set_text)
    

class C2(C1):
    def __init__(self) -> None:
        super().__init__()
        self._text_array = []
    
    def show_array(self) -> None:
        print(self._text_array)

    def set_array(self, array: list[str]) -> None:
        self._text_array = array


class C3(C2):
    COLOR = {
        'GREEN': '\u001b[32m',
        'RED': '\u001b[31m',
        'WHITE': '\u001b[37m',
        'YELLOW': '\u001b[33m',
    }
    
    def __init__(self, color: str, border_size: int) -> None:
        super().__init__()
        
        self._default_color = self.COLOR['WHITE']
        self._color = self._default_color
        self._set_color(color)
        
        self._border_size = 0
        self._set_border(border_size)

    def show_array(self) -> None:
        print(f'{" " * self._border_size}{self._color}{self._text_array}{self._default_color}')
    
    def _set_color(self, color: str):
        if color not in self.COLOR:
            raise KeyError(f'The color {color} not found in the class. Select one of them: {", ".join(self.COLOR.keys())}')
    
        self._color = self.COLOR[color]
    
    def _set_border(self, border_size: int):
        if border_size < 0:
            raise ValueError('The border cannot be less than size 0')
        
        self._border_size = border_size
    
    color = property(fset=_set_color)
    border = property(fset=_set_border)


def display_menu():
    print("Menu:")
    print("1. Show Array")
    print("2. Set Array")
    print("3. Change Color")
    print("4. Change Border Size")
    print("5. Quit")


if __name__ == '__main__':
    array = C3('GREEN', 10)

    while True:
        display_menu()
        choice = input("Enter your choice (1-5): ")

        if choice == '1':
            array.show_array()
        elif choice == '2':
            new_array = input("Enter a new array (comma-separated): ").split(',')
            array.set_array(new_array)
        elif choice == '3':
            new_color = input(f"Enter a new color ({', '.join(C3.COLOR.keys())}): ")
            array.color = new_color
        elif choice == '4':
            new_border_size = int(input("Enter a new border size: "))
            array.border = new_border_size
        elif choice == '5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please enter a number between 1 and 5.")