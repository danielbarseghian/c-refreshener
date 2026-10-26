# C-refreshener 
i made 2 exercices to try and get my C coding skill back to hopefully make C projects for the next weeks in terra!

## Description
### `counter`
i made this project to really start and get back into C. It was sooo hard, i was stuck so many times since i haven't coded for a while. I mixed up so many things and had to try to compile then fix the bugs over and over again.

### `mini-grep`
i really enjoyed making this one, its the first time i use Makefiles, include folder and src folder. I made a project trully by creating my own algorithms, even if there aren't the most efficiente i did it myself!

## How to use
The code is already pre-compiled for you! But if you want to modify the code yourself you should install dependecies!

### Install dependecies (for thoses wanting to modify the code)
You will need `make` and `gcc` to compile the code!

#### Windows
Install `MSYS2` that include make and gcc for windows.

1. First install MSYS2
You can get it from msys2's [website](msys2.org)!

2. Open it from the start menu and run
```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-make
```
press y when prompted

3. Check if there are installed
```bash
gcc --version
make --version
```

#### MacOS
On mac you can use apple's cli tools, they have `make` and `clang` (which is a C compiler that normally will work fine!).

1. First open the terminal
2. Then run 
```bash
xcode-select --install
```
3. Something will pop up, click install 
4. Finally verify
```bash
make --version
clang --version
```

#### Linux
Since linux is goated installing it is so much easier!

**Ubuntu/debian**
```bash
sudo apt install make gcc
```

**Fedora**
```bash
sudo dnf install make gcc
```

**Arch btw**
```bash
sudo pacman -S make gcc
```

Then verify its installed
```bash
make --version
gcc --version
```

### How to use the programs
if you installed the programs from the release open the terminal where the 2 programs are located or cd into it. If you opened the terminal in the folder you can skip step 1.
 #### `mini-grep`
1. go in the folder
```bash
cd mini-grep
```
2. use the program 
```bash
./minigrep [PATTERN] [FILE]
```
> if you ever get lost on how to use it you can use `--help` to learn how to use it!

 #### `word-frequencies-counter`
1. go into the folder
```bash
cd counter 
```
2. Then run the program
```bash
./counter
```
## What was the hardest step ? 
Honestly just starting out it was really frustrating and hard but i got true and im having so much fun coding in C now!

## What is grep ?
Grep is a unix/linux command to find a __pattern__ in a FILE.

## License
The project uses the MIT [license](#license).
