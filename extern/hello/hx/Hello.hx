/**
 * bindings for c/lib/hello.c
 */
@:hlNative("hello") class C 
{
	public static function get_string():hl.Bytes {
		return null;
	}

	public static function get_string_from_chars():hl.Bytes {
		return null;
	}

	public static function pass_string(text:String):Void {}

	public static function get_integer():Int {
		return 0;
	}

	public static function pass_integer(int:Int):Void {}

	public static function get_strings_static():hl.NativeArray<hl.Bytes> {
		return null;
	}
}

/**
 * haxe interface for using the C bindings
 */
class Hello 
{
	public static function getString():hl.Bytes 
	{
		return C.get_string();
	}

	public static function getString_from_chars():String 
	{
		var bytes = C.get_string_from_chars();
		@:privateAccess
		return String.fromUTF8(bytes);
	}

	public static function passString(text:String) 
	{
		C.pass_string(text);
	}

	public static function getInteger() {
		return C.get_integer();
	}

	public static function passInteger(integer:Int) {
		C.pass_integer(integer);
	}

	public static function getStringsStatic():Array<String> {
		var dstrings:hl.NativeArray<hl.Bytes> = C.get_strings_static();
		@:privateAccess
		var strings = [for(d in dstrings) String.fromUTF8(d)];
		return strings;
	}
}
