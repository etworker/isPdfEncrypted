# isPdfEncrypted

## Introduction

I cannot find any command line tool to check if pdf file is encrypted under Windows, so I have to write my tool.

This tool can check pdf file if encrypted.

## Usage

Syntax:

```isPdfEncrypted.exe <pdf filename>```

Example:

```isPdfEncrypted.exe c:\a.pdf```

Result:

Print `encrypted` if pdf is encrypted, or print `not encrypted` if pdf is not encrypted.

## Develop environment:

- Windows 8.1 64bit
- Visual Studio 2013
- C++ STL code without any 3rd lib

## For developer

If you need integrate this function into your application, please look at the function

```bool isPdfEncrypted(char *filename);```