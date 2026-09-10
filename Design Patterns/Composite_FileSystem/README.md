# File System Design

A simple file system hierarchy built with composite design pattern.

## Files

- [filesystemitem.h](filesystemitem.h) — base interface for all filesystem items
- [file.h](file.h) — file node with name and size
- [folder.h](folder.h) — folder node with child items
- [client.cpp](client.cpp) — example usage

## Features

- `ls()` to list contents
- `tree()` to print recursive structure
- `getSize()` to calculate total size
- `cd()` to navigate into a folder

## Example

```cpp
Folder* d = new Folder("Drive-D");
File* f = new File("movie.mp4", 120);
d->add(f);

cout << d->getSize();
```

## Run

```bash
g++ client.cpp -o file_system
./file_system
```