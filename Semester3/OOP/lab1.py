import os
from typing import Any

from colorama import init, Fore


class WindowSettings():
    colors = {
        'red': Fore.RED,
        'green': Fore.GREEN,
        'cyan': Fore.CYAN,
        'blue': Fore.BLUE,
        'yellow': Fore.YELLOW,
        'white': Fore.WHITE
    }
    size_limit = {
        'width': {'min': 10, 'max': 100},
        'height': {'min': 10, 'max': 100},
        'position': {'min': 0, 'max': 50},
        'border_size': {'min': 0, 'max': 5},
    }
    
    issue_message = None

    def __init__(self) -> None:
        self.width = 55
        self.height = 15
        self.position = 1
        self.border_size = 1
        self._is_visible = True
        self.title = 'Window'
        self.title_color = self.colors['blue']
        self.border_color = self.colors['green']
    
    def get_colors(self) -> list[str]:
        return list(self.colors.keys())
    
    def set_title_color(self, color: str) -> str:
        return self.__set_color('title_color', color)

    def set_border_color(self, color: str) -> str:
        return self.__set_color('border_color', color)
    
    def set_position(self, value: int) -> int:
        return self.__set_size('position', value)
    
    def set_border_size(self, value: int) -> int:
        return self.__set_size('border_size', value)
    
    def set_width(self, width: int) -> int:
        return self.__set_size('width', width)

    def set_height(self, height: int) -> int:
        return self.__set_size('height', height)
    
    def __set_color(self, attr: str, color: str) -> str:
        self.issue_message = None
        
        if color in self.colors.keys():
            setattr(self, attr, self.colors[color])
        else:
            self.issue_message = 'Set correct color and try again!'
        
        return color
    
    def __set_size(self, atr: str, size: int) -> Any:
        self.issue_message = None
        
        side_min = self.size_limit[atr]['min']
        side_max = self.size_limit[atr]['max']

        if size > side_min and size < side_max:
            setattr(self, atr, size)
        else:
            self.issue_message = f'Set correct {atr} size. \nMin: {side_min} Max: {side_max}'
        
        return getattr(self, atr)
        

class BaseOptions(WindowSettings):
    def open_window(self):
        self._draw()
    
    def show(self) -> None:
        self._is_visible = True
        self._draw()
    
    def hide(self) -> None:
        self._is_visible = False
        self._draw()
    
    def close(self) -> None:
        os._exit(1)
        
    def clear(self) -> None:
        os.system('cls')
        
    def _draw(self) -> None:
        
        self.clear()
        if not self._is_visible:
            return
        
        title = f'Title: {self.title}'
        border_y = '|' * self.border_size
        border_with_color = f'{self.border_color}{border_y}{self.colors["white"]}'
        border_size_x = 1
        position = ' ' * self.position
        display_width_title = ' ' * ((self.width - (len(border_y) * 2)) - len(title))
        display_width = ' ' * (self.width - (len(border_y) * 2))
        
        self.__draw_horizontal_line(border_size_x, position)
        print(f'{position}{border_with_color}{self.title_color}{title}{display_width_title}{border_with_color}')
        self.__draw_horizontal_line(border_size_x, position)
        
        for _ in range(self.height - 2):
            print(f'{position}{border_with_color}{display_width}{border_with_color}')
        
        self.__draw_horizontal_line(border_size_x, position)
        
        if self.issue_message is not None:
            print(f'{self.colors["red"]}{self.issue_message}{self.colors["white"]}\n')
    
    def __draw_horizontal_line(self, border_size: int, position) -> None:
        for _ in range(border_size):
            print(f"{position}{self.border_color}{'-' * self.width}{self.colors['white']}")
    

class Window(BaseOptions):
    def change_title(self) -> None:
        print('Write new title:')
        self.title = input('\n\n>>> ')
    
    def change_title_color(self) -> None:
        self.__change_color(self.set_title_color)
    
    def change_border_color(self) -> None:
        self.__change_color(self.set_border_color)
    
    def change_width(self) -> None:
        self.__change_size(self.set_width)
    
    def change_height(self) -> None:
        self.__change_size(self.set_height)
    
    def change_border_size(self) -> None:
        self.__change_size(self.set_border_size)
        
    def change_position(self) -> None:
        self.__change_size(self.set_position)
    
    def __change_size(self, setter) -> None:
        print('Write size')
        size = int(input('\n\n>>> '))
        setter(size)

    def __change_color(self, setter) -> None:
        print('Select number color:')
        colors = self.get_colors()
        
        while True:
            for i, color in enumerate(colors):
                print(f'{i} - {color}')
            selected_color = int(input('\n\n>>> '))
            
            try:
                setter(colors[selected_color])
                return
            except IndexError:
                continue


if __name__ == "__main__":
    init()
    window = Window()
    
    while True:
        window.open_window()
        command = input("Change actions \
            \nshow | hide | close | title | title color | border | border color | position | height | width\
                \n\n>>> ").lower()
        
        if command == "show":
            window.show()
        elif command == "hide":
            window.hide()
        elif command == "title":
            window.change_title()
        elif command == "title color":
            window.change_title_color()
        elif command == "border":
            window.change_border_size()
        elif command == "border color":
            window.change_border_color()
        elif command == "position":
            window.change_position()
        elif command == "height":
            window.change_height()
        elif command == "width":
            window.change_width()
        elif command == "close":
            window.close()