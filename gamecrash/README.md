


$ g++ -c ../src/main.cpp
$ g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

# In stall google test
sudo apt-get install libgtest-dev
Note that this package only install source files. You have to compile the code yourself to create the necessary library files. These source files should be located at /usr/src/gtest. Browse to this folder and use cmake to compile the library:

sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
 
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib

ref: https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/