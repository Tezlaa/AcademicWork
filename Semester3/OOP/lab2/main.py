import os
import glob
from io import TextIOWrapper
from datetime import datetime


class FileBaseOptions:
    date_format = '%Y-%m-%d %H:%M:%S'
    
    def __init__(self, path: str = 'autofile.txt') -> None:
        file_name = path.split('/')[-1]
        
        self.path = path
        self.extension = file_name.split('.')[-1] if '.' in file_name else None
        self.file_name = self.valid_file_name(file_name)
        
        self._file_instance = self._create_file_instance()
        self.file_sats = os.stat(self.path)
        
    def valid_file_name(self, file_name: str) -> str:
        """
        If the user put an invalid name i.e without an extenstion (.txt/.csv/...),
        add exctention .txt and return it.
        """
        if self.extension is None:
            self.extension = 'txt'
            self.path += '.txt'
            
        if '.' not in file_name:
            return f'{file_name}.{self.extension}'
        
        return file_name
    
    def get_file_size(self) -> float:
        """
        Size in kilobytes.
        """
        return self.file_sats.st_size / 1024
    
    def get_full_path(self) -> str:
        return os.path.abspath(self.path)
    
    def get_modify_date(self) -> str:
        modify_date = self.file_sats.st_mtime
        return self.unix_to_str(modify_date)
    
    def get_creation_date(self) -> str:
        birthtime = os.path.getctime(self.path)
        return self.unix_to_str(birthtime)
    
    @classmethod
    def unix_to_str(cls, unix_date: float) -> str:
        time = datetime.fromtimestamp(unix_date)
        return time.strftime(cls.date_format)

    def _create_file_instance(self) -> TextIOWrapper:
        #  find the file in directory
        open_flag = 'r+' if len(glob.glob(self.path)) > 0 else 'w+'
        
        return open(self.path, open_flag, encoding='utf-8')
    
    def _change_path(self, new_file_name: str) -> str:
        slice_path = '/'.join(self.path.split('/')[:-1])
        self.path = f'{slice_path}/{new_file_name}'
        return self.path


class File(FileBaseOptions):
    
    def close_file(self) -> None:
        self._file_instance.close()
    
    def open_file(self) -> None:
        if self.is_file_close():
            self._file_instance = self._create_file_instance()

    def is_file_close(self) -> bool:
        return self._file_instance.closed
    
    def get_list_file_content(self) -> list:
        if self.is_file_close():
            return
        
        self.close_file()
        self.open_file()
        return self._file_instance.readlines()
    
    def change_file_name(self, new_file_name: str) -> None:
        new_file_name = self.valid_file_name(new_file_name)
            
        old_path = self.get_full_path()
        self._change_path(new_file_name)
        new_path = self.get_full_path()
        
        self.close_file()
        os.rename(old_path, new_path)
        self.open_file()


class ConsoleFileInterface(File):
    def menu_change_file_name(self) -> None:
        print('Write new file name')
        new_file_name = input('\n\n>>> ')
        
        self.change_file_name(new_file_name=new_file_name)

    def menu_show_file_name(self) -> None:
        print(self.file_name)
    
    def menu_show_file_size(self) -> None:
        print(f'{(self.get_file_size()):.2f} Кб')

    def menu_show_full_path_to_file(self) -> None:
        print(self.get_full_path())
    
    def menu_show_file_birth_time(self) -> None:
        print(self.get_creation_date())

    def menu_show_file_modify_time(self) -> None:
        print(self.get_modify_date())
    
    def menu_show_file_status(self) -> None:
        status = 'Open'
        if self.is_file_close():
            status = 'close'
            
        print('File is', status)
    
    def menu_open_file(self) -> None:
        self.open_file()
    
    def menu_close_file(self) -> None:
        self.close_file()

    def menu_show_file_content(self) -> None:
        print('\n'.join(self.get_list_file_content()))
    

if __name__ == "__main__":
    file = ConsoleFileInterface('lab2/files/testfile')
    
    menu_actions = {
        '1': ('Get file name', file.menu_show_file_name),
        '2': ('Change file name', file.menu_change_file_name),
        '3': ('File size', file.menu_show_file_size),
        '4': ('Path to the file', file.menu_show_full_path_to_file),
        '5': ('File birth time', file.menu_show_file_birth_time),
        '6': ('File modification time', file.menu_show_file_modify_time),
        '7': ('File status', file.menu_show_file_status),
        '8': ('Open file', file.menu_open_file),
        '9': ('Close file', file.menu_close_file),
        '10': ('Show file content', file.menu_show_file_content),
    }
    
    while True:
        print('\n')
        for action in menu_actions.items():
            print(f'{action[0]} - {action[1][0]}')
        select_action = input('\n >>>  ')
        
        menu_action = menu_actions[select_action][1]
        menu_action()
        