import ctypes, os, pathlib
# lib = cdll.LoadLibrary('C:/Program\ Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream')
# proj_folder = pathlib.Path(f'{os.getcwd()}\{__file__}').parent
# os.add_dll_directory(proj_folder)
# os.add_dll_directory("${./}")
# ctypes.DEFAULT_MODE
lib = ctypes.CDLL('./test.dll')


class Foo(object):
    def __init__(self):
        self.obj = lib.Foo_new()

    def bar(self):
        lib.Foo_bar(self.obj)

f = Foo()
f.bar() #and you will see "Hello" on the screen
