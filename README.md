# Word frequencie counter
im making 4 exercices to try and get back my level to create a custom-malloc! At first i was planning to make 4 exercices then ship but its better that i make each one into 4 projects!

## Description
The input will grow automaticly depending on the string's size. This part took me the most time, I rewrote it 2 times :0. Then it will sort put everything into a frequencie linked list and print them with the number of time they appear!

## How to use
This program has only been tested inside linux but normally everything should work inside any other distros
### Install dependecies
this is only required if you want to modify the code!

#### Windows

Install [MSYS2](https://www.msys2.org/), open the **MSYS2 UCRT64** terminal, and run:

```bash
pacman -Syu
pacman -S --needed mingw-w64-ucrt-x86_64-gcc make
```

If prompted to close the terminal after updating, reopen it and run the install command again. Add `C:\msys64\ucrt64\bin` to your Windows `PATH` if you want to use `gcc` and `make` from other terminals. <citation src="3"></citation>

#### MacOS

Install Apple’s Command Line Tools, which provide `make` and a compiler:

```bash
xcode-select --install
```

> macOS’s `gcc` command usually invokes Apple Clang, not GNU GCC. If you specifically need GNU GCC, install it with [Homebrew](https://brew.sh/):

```bash
brew install gcc make
```

<citation src="1"></citation>

#### Linux

Use your distribution’s package manager. 

Debian/Ubuntu
```bash
sudo apt update
sudo apt install build-essential
```

Fedora:

```bash
sudo dnf install gcc make
```

Arch btw:

```bash
sudo pacman -S gcc make
```

> its so much easier for linux :0

#### Verify the installation

Open a new terminal and check that the commands are available:

```bash
gcc --version
make --version
```

### Compile and test

1. compile it

```bash
    make word-frequencies-counter
```

2. run it

```bash
    ./word-frequencies-counter
```

now input some words and test it!


## What was the most challenging part?
it was not using AI. Im trying to remove my habit of always asking AI for every small things!

## Why it took so long?
Im also switching to neovim and im so bad with string manipulation too (im working on it).

## License
this project uses the MIT [license](LICENSE)
