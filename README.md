# ofPackageManager

## Description
ofPackageManager is an experimental package manager for openFrameworks. It is compatible with version 0.10.0 or higher and it does not support windows yet.

## Usage
### Installation

On Linux you need to install libgit: `sudo apt install libgit`.

You can download a fresh version of openFrameworks, as well as ofPackageManager and its depedencies via the following commands.
cd into your preferred installation directory, e.g. `mkdir ~/.ofPackageMananger && cd ~./ofPackageManager`
```
sh -c "$(curl -sSL https://raw.githubusercontent.com/thomasgeissl/ofPackageManager/master/scripts/install.sh)"
```

It is recommended to add the path your bash profile. Have a look at the `add_to_path.sh`script.

Run the global configuration in order to install addons globally. `ofPackageManager config -g`

### Package management
* Search package in database: ``` ofPackageManager search ofxHTTP ```
* Search package on github by name: ``` ofPackageManager search github ofxSyphon ```
* Search package on github by user: ``` ofPackageManager search github --user arturoc ```
* Install package by id: ``` ofPackageManager install ofxMidi ```
* Install package by github name (user/repo): ``` ofPackageManager install arturoc/ofxAruco ```
* Install package by url: ``` ofPackageManager install https://github.com/kylemcdonald/ofxCv.git ```
* Install addons globally: ``` ofPackageManager install -g kylemcdonald/ofxCv ```
* Add already cloned repositories: ``` ofPackageManager add -A local_addons ```
* Install dependencies of a package: ``` ofPackageManager install ```
* Generate project: ``` ofPackageManager generate ```
* Generate readme: ``` ofPackageManager generate readme ```
* Generate database entry file: ``` ofPackageManager generate database ```

### Package manager update/info
* Info: `ofPackageManager info`
* Help/man: `ofPackageManager help`
* Check for updates: ``` ofPackageManager doctor ```
* Upate packages database: ``` ofPackageManager update ```
* Print available packages: ``` ofPackageManager print packages ```
* Print version: ``` ofPackageManager print version ```

## TODOs
* replace system calls by libgit2 calls
* find solution for addon dependencies
* command line syntax
* better console output
* optimize

## License
This software is distributed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License).

Copyright (c) 2016 Thomas Geissl

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

## Changelog
