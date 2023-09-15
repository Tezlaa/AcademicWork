import os


class WindowSettings():
    size_limit = {
        'width': {'min': 10, 'max': 100},
        'height': {'min': 10, 'max': 100}
    }
        
    def __init__(self) -> None:
        self.width = 55
        self.height = 20
        self.x_position = 0
        self._is_visible = True
        self.title = 'Window'
    
    def set_position(self, value: int) -> int:
        if value > 0 and value < 50:
            self.x_position = value
        else:
            print('Set correct position and try again!')
        
        return self.x_position
    
    def set_width(self, width: int) -> int:
        return self.__set_size('width', width)

    def set_height(self, height: int) -> int:
        return self.__set_size('height', height)
    
    def __set_size(self, side: str, size: int):
        side_min = self.size_limit[side]['min']
        side_max = self.size_limit[side]['max']

        if size > side_min and size < side_max:
            setattr(self, side, size)
        else:
            print(f'Set correct {side}. \nMin: {side_min} Max: {side_max}')
        
        return getattr(self, side)
        

class BaseOptions(WindowSettings):    
    def draw(self):
        title = f'Title: {self.title}'
        
        if self._is_visible:
            self.clear()
            
            print(f"{' ' * self.x_position}{'-' * self.width}")
            print(f"{' ' * self.x_position}|{title}{' ' * ((self.width - 2) - len(title))}|")
            print(f"{' ' * self.x_position}{'-' * self.width}")
            
            for _ in range(self.height - 2):
                print(f"{' ' * self.x_position}|{' ' * (self.width - 2)}|")
            print(f"{' ' * self.x_position}{'-' * self.width}")
    
    def clear(self):
        os.system('cls')


class Window(BaseOptions):

    def show(self):
        self.is_visible = True
        self.draw()

    def hide(self):
        self.is_visible = False
        self.clear()

    def minimize(self):
        self.is_visible = False
        self.draw_minimized()

    def maximize(self):
        self.is_visible = True
        self.draw()

    def close(self):
        self.is_visible = False
        self.clear()

    def move(self, x, y):
        self.x = x
        self.y = y

    def draw_minimized(self):
        if self.is_visible:
            self.clear()
            print(f"{'#' * self.width}")
            print(f"Title: {self.title} (Minimized)")


if __name__ == "__main__":
    window = Window()
    window.show()

    while True:
        command = input("Введіть команду (show/hide/minimize/maximize/close/exit): ").lower()
        
        if command == "show":
            window.show()
        elif command == "hide":
            window.hide()
        elif command == "minimize":
            window.minimize()
        elif command == "maximize":
            window.maximize()
        elif command == "close":
            window.close()
        elif command == "exit":
            break
        else:
            print("Невідома команда. Спробуйте ще раз.")
