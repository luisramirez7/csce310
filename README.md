# csce310
A repository to keep track of very useful algorithm implementations as I go through algorithms class. 

# WARNING: MINIMUM SPANNING TREE IS NOT FUNCTIONAL

Here are some guidlines to help you compile, and run these algorithms on your local machine. 

1. `git clone` the repository
2. If you are on a OSX machine, you already have a c++ compiler, it comes with excode. You invoke this by typing `$g++` in your command line.
3. `cd` into the folder you want to view. 
4. The following line will tell you how to compile the algorithm: `$g++ -std=c++11 -o part01 part01.cpp test01.cpp`
5. Depending on if the folder you are looking at has an `.in` or not, the ways you will run the executable will be different.
  - For files that have `.in` files, execute like so: `$ ./part01 < part01test01.in`, as an example. The `.in` file simply holds test information to test your algo. 
  - For files that have no `.in` files, simply run your program. I highly recommend (if one is not present) to create your own testing values, based off the test.cpp's, simply because this is your main program, and will be easier to provide the program with a plain text file of inputs. 
6. That's all! Become an algorithm master following these programs to practice your ability!
