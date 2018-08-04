# Sample Code to Use `O_NONBLOCK` for FIFO

## Usage

In a terminal, type

```shell-session
$ mkfifo hoge
$ cat > hoge
....
TYPE SOMETHING
...
ctrl-D TO END
...
```

In another one, enter

```shell-session
$ gcc ./test.c
$ ./a.out
```


