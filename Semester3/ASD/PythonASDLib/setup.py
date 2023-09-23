from setuptools import setup, find_packages

setup(
    name="PythonASDLib",
    version="1.0.0",
    author="Tezla",
    author_email="Bogdantihenko60@email.com",
    description="Package for algorithmics",
    packages=find_packages(),
    install_requires=[
        "openpyxl",
        "colorama",
    ],
)
