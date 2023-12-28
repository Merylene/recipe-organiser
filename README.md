# recipe-organiser
This final project should help people to organise their recipes so that it could be accessed with just typing

# Usage of the Program
For admin access
```
./recipe.exe edit
```
For normal viewing
```
./recipe.exe view
```

for edit password will be required (all passwords/recipes will be encypted so that the access point will only be the program)

# How to install CMake on Ubuntu
```
sudo apt-get -y install cmake
which cmake
cmake --version
```

# Usage of CMakelists.txt

Navigate to the project (just an example)
```
cd repo/recipe-organiser
```

Create a directory to build and run 
```
mkdir build
cd build
cmake .. 
make
```
if on wsl and want to excecute all at once could do this it will do all the steps at once
```
mkdir build;cd build;cmake .. ;make
```

# Parts that need help with 
1. how to remove an awkward line that is created while trying to enter the recipe
2. encryption and decryption of text 
would appreciate if there are anyone that is willing to help :)