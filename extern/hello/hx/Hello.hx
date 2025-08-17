import hl.Bytes;

/**
 * C bindings for c/lib/hello.c
 */
@:hlNative("hello")
class C {
	public static function get_greeting():hl.Bytes {
		return null;
	}

	public static function get_greeting_from_chars():hl.Bytes {
		return null;
	}

	public static function greet_me(text:String):Void {
	}
}

/**
 * haxe interface for using the C bindings
 */
class Hello {

	public static function get_greeting():hl.Bytes {
		return C.get_greeting();
	}
	
	public static function get_greeting_from_chars():String {
		var bytes = C.get_greeting_from_chars();
		@:privateAccess
		return String.fromUTF8(bytes);
	}
	
	public static function greet_me(text:String) {
		C.greet_me(text);
	}
}