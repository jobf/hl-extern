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
```

# compile the extern

```
haxelib run hxcpp hello_hl_Build.xml
```

This should produce a folder `Export/hl/bin`, each containing the hdll.

# testing

## pure haxe

run pure, you should see the greetings from c!

```
haxe test.hxml
```

## lime

run lime, you should see the greetings from c!

```
haxelib run lime test hl
```