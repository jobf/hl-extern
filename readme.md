# Minimal proof of concept hashlink extern.

Including a pure haxe project and a lime project, to test the extern with.

We'll even use lime from a git repo, because someguywho.

# setup

## install haxelibs

Init a local haxelib repo to keep the project isolated from the rest of the system. This will create a new folder `.haxelib` where haxelibs will be installed. 

```
haxelib newrepo
```

Install git lime.

```
haxelib git lime https://github.com/openfl/lime.git 8.2.2

# or your own fork, this checks out a specific commit because latest will not build here
haxelib git lime https://github.com/SomeGuyWhoLovesCoding/lime.git 	d5c86fb74924e111ed3a1f5c2eea2e9595689faf
```

To build lime we also need hxp, hxcpp and format, so install them.

```
haxelib install hxp
haxelib install hxcpp
haxelib install format
```

## compile lime

```
# lime tools
haxelib run lime rebuild tools

# the hashlink that lime ships
haxelib run lime rebuild hl

# hxcpp target (use windows instead of linux if that's your thing)
haxelib run lime rebuild linux
```

# compile the extern

```
haxelib run hxcpp hello_hl_Build.xml
```

This should produce two folders, each containing the hdll

```
bin
Export/hl/bin
```

# testing

## compile the pure haxe test

Copy the haxelib binaries to the output folder. Will need changing for Windows.

```
cp .haxelib/lime/git/templates/bin/hl/Linux64/* bin
```
Now compile the project.

```
haxe build.hxml
```

Run it, you should see the greeting from c!

```
cd bin
hl main.hl
```

## run the lime test

```
haxelib run lime test hl
```

You should see the green from c, however we have a glitch.

```
FATAL ERROR : Failed to load function hello@get_greeting
```

This glitch is usually due to one of the following

- mismatch of hashlink version between the vm used to run it and the source used to compile the extern
- missing or incompatible hl dependencies
- other reasons?

We know the versino is correct, as we used the same source to compile hashlink and the extern.

So it could be a missing dependency, or something else?
