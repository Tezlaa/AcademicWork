import os

from simplecrypt import decrypt, DecryptionException


PATH = os.path.dirname(__file__) + '\\'


class DecodeCryptoFile:
    """ Decode crypto file by password
    
    __init__:
        crypto_file_name (str): name your binary file with encrypto data
            Example use: crypto_file_name="enctypto.bin"
    decode:
        password (str): password for your binary file, if pass is not valid than returned None
        
        Return: result data or None
    """
    
    def __init__(self, crypto_file_name: str) -> None:
        self.crypto_path = PATH + crypto_file_name
    
    def decode(self, password: str) -> str | None:
        """ Decode your binary file by password

        Args:
            password (str): password for the file

        Returns:
            str | None: if pass is valid - return string and if not is valid - return None
        """
        
        with open(self.crypto_path, "rb") as file:
            try:
                return decrypt(password, file.read()).decode('utf8')
            except DecryptionException:
                return None


def get_passwords(password_path_name: str) -> list[str]:
    """ Get list with passwords

    Args:
        password_path_name (str): Path to file where passwords

    Returns:
        list[str]: list with all passwords
    """
    with open(PATH + password_path_name, 'r') as file:
        return file.read().split("\n")[:-1]
    

if __name__ == "__main__":
    passwords = get_passwords('Alisa_passwords.txt')
    crypto_file = DecodeCryptoFile('Alisa_encrypted.bin')
    
    for password in passwords:
        decode_text = crypto_file.decode(password)
        if decode_text:
            print('result decode: ', decode_text)
            break